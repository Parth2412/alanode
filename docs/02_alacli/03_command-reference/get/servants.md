## Description

Retrieve accounts which are servants of a given account

## Info

**Command**

```sh
alacli get servants
```

**Output**

```console
Usage: alacli get servants account

Positionals:
  account TEXT                The name of the controlling account
```

## Command

```sh
alacli get servants inita
```

## Output

```json
{
  "controlled_accounts": ["tester"]
}
```
