## Goal

Connect to a specific `alanode` or `kalad` host to send COMMAND

`alacli` and `kalad` can connect to a specific node by using the `--url` or `--wallet-url` optional arguments, respectively, followed by the http address and port number these services are listening to.

[[info | Default address:port]]
| If no optional arguments are used (i.e. `--url` or `--wallet-url`), `alacli` attempts to connect to a local `alanode` or `kalad` running at localhost `127.0.0.1` and default port `8888`.

## Before you begin

- Install the currently supported version of `alacli`

## Steps

### Connecting to Alanode

```sh
alacli -url http://alanode-host:8888 COMMAND
```

### Connecting to Kalad

```sh
alacli --wallet-url http://kalad-host:8888 COMMAND
```
