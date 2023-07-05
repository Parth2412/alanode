# Bios Boot Tutorial

The `bios-boot-tutorial.py` script simulates the bios boot sequence.

## Prerequisites

1. Python 3.x
2. CMake
3. git
4. g++
5. build-essentials
6. pip3
7. openssl
8. curl
9. jq
10. psmisc

## Steps

1. Install alanode binaries by following the steps provided in the [alanode README](https://github.com/alacrityio/alanode/tree/release#software-installation).

2. Install CDT by following the steps provided in the [CDT README](https://github.com/alacrityio/alaio.cdt-1.6.1).

3. Compile ALAIO System Contracts 1.7.0:

```bash
$ cd ~
$ git clone https://github.com/alacrityio/alaio.contracts-1.7.0 alaio.contracts-1.7.0
$ cd ./alaio.contracts-1.7.0/
$ mkdir build
$ cd ./build
$ cmake -DCMAKE_BUILD_TYPE=Release ..
$ make -j $(nproc)
$ cd ./contracts/
$ pwd
```

4. Make note of the path where the contracts were compiled
   The last command in the previous step printed the contracts directory. Make note of it; we will reference it from now on as the environment variable `CONTRACTS_DIRECTORY`.

5. Launch the `bios-boot-tutorial.py` script:

```bash
$ cd ~
$ git clone https://github.com/alacrityio/alanode
$ cd ./alanode/tutorials/bios-boot-tutorial/
$ python3 bios-boot-tutorial.py --alacli=alacli --alanode=alanode --kalad=kalad --contracts-dir="${CONTRACTS_DIRECTORY}" -w -a
```
