---
content_title: Kalad
---

## Introduction

`kalad` is a key manager service daemon for storing private keys and signing digital messages. It provides a secure key storage medium for keys to be encrypted at rest in the associated wallet file. `kalad` also defines a secure enclave for signing transaction created by `alacli` or a third part library.

## Installation

`kalad` is distributed as part of the [Alacrityio software suite](https://github.com/alacrityio/alanode). To install `kalad` just visit the [Alacrityio Software Installation](../00_install/index.md) section.

## Operation

When a wallet is unlocked with the corresponding password, `alacli` can request `kalad` to sign a transaction with the appropriate private keys. Also, `kalad` provides support for hardware-based wallets such as Secure Encalve and YubiHSM.

[[info | Audience]]
| `kalad` is intended to be used by Alacrityio developers only.
