#!/usr/bin/env python3

# This script tests that alacli launches kalad automatically when kalad is not
# running yet.

import subprocess


def run_alacli_wallet_command(command: str, no_auto_kalad: bool):
    """Run the given alacli command and return subprocess.CompletedProcess."""
    args = ['./programs/alacli/alacli']

    if no_auto_kalad:
        args.append('--no-auto-kalad')

    args += 'wallet', command

    return subprocess.run(args,
                          check=False,
                          stdout=subprocess.DEVNULL,
                          stderr=subprocess.PIPE)


def stop_kalad():
    """Stop the default kalad instance."""
    run_alacli_wallet_command('stop', no_auto_kalad=True)


def check_alacli_stderr(stderr: bytes, expected_match: bytes):
    if expected_match not in stderr:
        raise RuntimeError("'{}' not found in {}'".format(
            expected_match.decode(), stderr.decode()))


def kalad_auto_launch_test():
    """Test that kala auto-launching works but can be optionally inhibited."""
    stop_kalad()

    # Make sure that when '--no-auto-kalad' is given, kalad is not started by
    # alacli.
    completed_process = run_alacli_wallet_command('list', no_auto_kalad=True)
    assert completed_process.returncode != 0
    check_alacli_stderr(completed_process.stderr, b'Failed http request to kalad')

    # Verify that kalad auto-launching works.
    completed_process = run_alacli_wallet_command('list', no_auto_kalad=False)
    if completed_process.returncode != 0:
        raise RuntimeError("Expected that kalad would be started, "
                           "but got an error instead: {}".format(
                               completed_process.stderr.decode()))
    check_alacli_stderr(completed_process.stderr, b'launched')


try:
    kalad_auto_launch_test()
finally:
    stop_kalad()
