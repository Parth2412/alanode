## Overview

This how-to guide provides instructions on how to create a keypair consisting of a public key and a private key for signing transactions in an Alacrityio blockchain.

## Before you begin

Make sure you meet the following requirements:

- Install the currently supported version of `alacli`
  [[info | Note]]
  | The alacli tool is bundled with the Alacrityio software. [Installing Alacrityio](../../00_install/index.md) will also install the alacli tool.
- Learn about asymmetric cryptography (public and private keypair) in the context of an Alacrityio blockchain.

## Command Reference

See the following reference guide for `alacli` command line usage and related options:

- [`alacli create key`](../03_command-reference/create/key.md) command and its parameters

## Procedure

The following steps show how to create a public/private keypair, display them on the console, and save them to a file:

1. Create a public/private keypair and print them to the console:

```sh
alacli create key --to-console
```

**Where**:

- `--to-console` = The option parameter to print the keypair to the console

**Example Output**

```console
Private key: 5KPzrqNMJdr6AX6abKg*******************************cH
Public key: ALA4wSiQ2jbYGrqiiKCm8oWR88NYoqnmK4nNL1RCtSQeSFkGtqsNc
```

2. Create a public/private keypair and save it to a file:

```sh
alacli create key --file pw.txt
```

**Where**:

- `--file` = The option parameter to save the keypair to a file
- `FILE_TO_SAVEKEY` = The name of the file to save the keypair

**Example Output**

```console
saving keys to pw.txt
```

To view the saved keypair stored in the file:

```sh
cat pw.txt
```

```console
Private key: 5K7************************************************
Public key: ALA71k3WdpLDeqeyqVRAAxwpz6TqXwDo9Brik5dQhdvvpeTKdNT59
```

## Summary

By following these instructions, you are able to create public/private keypairs, print them to the console, and save them to a file.
