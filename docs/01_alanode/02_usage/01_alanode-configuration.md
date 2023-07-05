---
content_title: Alanode Configuration
---

The plugin-specific options can be configured using either CLI options or a configuration file, `config.ini`. Alanode-specific options can only be configured from the command line. All CLI options and `config.ini` options can be found by running `alanode --help` as shown above.

Each `config.ini` option has a corresponding CLI option. However, not all CLI options are available in `config.ini`. For instance, most plugin-specific options that perform actions are not available in `config.ini`, such as `--delete-state-history` from `state_history_plugin`.

For example, the CLI option `--plugin alaio::chain_api_plugin` can also be set by adding `plugin = alaio::chain_api_plugin` in `config.ini`.

## `config.ini` location

The default `config.ini` can be found in the following folder on Linux:
`~/.local/share/alaio/alanode/config`

A custom `config.ini` file can be set by passing the `alanode` option `--config path/to/config.ini`.

## Alanode Example

The example below shows a typical usage of `alanode` when starting a block producing node:

```sh
alanode \
  -e -p alaio \
  --data-dir /users/mydir/alaio/data     \
  --config-dir /users/mydir/alaio/config \
  --plugin alaio::producer_plugin      \
  --plugin alaio::chain_plugin         \
  --plugin alaio::http_plugin          \
  --plugin alaio::state_history_plugin \
  --contracts-console   \
  --disable-replay-opts \
  --access-control-allow-origin='*' \
  --http-validate-host=false        \
  --verbose-http-errors             \
  --state-history-dir /shpdata \
  --trace-history              \
  --chain-state-history        \
  >> alanode.log 2>&1 &
```

The above `alanode` command starts a producing node by:

- enabling block production (`-e`)
- identifying itself as block producer "alaio" (`-p`)
- setting the blockchain data directory (`--data-dir`)
- setting the `config.ini` directory (`--config-dir`)
- loading plugins `producer_plugin`, `chain_plugin`, `http_plugin`, `state_history_plugin` (`--plugin`)
- passing `chain_plugin` options (`--contracts-console`, `--disable-replay-opts`)
- passing `http-plugin` options (`--access-control-allow-origin`, `--http-validate-host`, `--verbose-http-errors`)
- passing `state_history` options (`--state-history-dir`, `--trace-history`, `--chain-state-history`)
- redirecting both `stdout` and `stderr` to the `alanode.log` file
- returning to the shell by running in the background (&)
