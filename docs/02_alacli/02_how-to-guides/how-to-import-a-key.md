## Overview

This how-to guide provides instructions on how to import a private key into the `kalad` default wallet. You can use the private key to authorize transactions in an Alacrityio blockchain.

## Before you Begin

Make sure you meet the following requirements:

- Create a default wallet using the `alacli wallet create` command. See the [How to Create a Wallet](../02_how-to-guides/how-to-create-a-wallet.md) section for instructions.
- Open and unlock the created wallet.
- Familiarize with the [`alacli wallet import`](../03_command-reference/wallet/import.md) command.
- Install the currently supported version of `alacli`.
  [[info | Note]]
  | `alacli` is bundled with the Alacrityio software. [Installing Alacrityio](../../00_install/index.md) will also install `alacli`.
- Understand what a [public key](/glossary.md#public-key) and [private key](/glossary.md#private-key) is.

## Command Reference

See the following reference guide for `alacli` command line usage and related options:

- [alacli wallet import](../03_command-reference/wallet/import.md) command and its parameters

## Procedure

The following steps show how to import a private key to an existing `kalad` default wallet:

1. Run the following command to import a private key into the default wallet. The command prompts to enter a private key:

```sh
alacli wallet import
```

```console
private key:
```

2. Enter the private key and hit Enter.

```sh
***
```

**Example Output**
The command confirms that the private key is imported correctly by displaying the corresponding public key:

```console
imported private key for: ALA8FBXJUfbANf3xeDWPoJxnip3Ych9HjzLBr1VaXRQFdkVAxwLE7
```

## Summary

By following these instructions, you are able to import a private key to the default wallet.
