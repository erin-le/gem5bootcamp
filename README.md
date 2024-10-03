# gem5 bootcamp environment

This repository has been designed for use in gem5 tutorials.

It has been built with the assumption users will utilize [Codespaces](https://github.com/features/codespaces) to learn gem5.

The repository contains the following directories:

> **Note:** 'gem5' and 'gem5-resources' are submodules though the [.devcontainer/devcontainer.json](.devcontainer/devcontainer.json) file specifies that a `git submodule update --init --recursive` command is executed when the Codespace Docker container is created.
>
> **Note:** The `.devcontainer/on_create.sh` script is executed the first time the codespace is created.
> This will pre-download much of the resources (disk images, etc.) that are used in the gem5 tutorials.
> It can take a while to do this.
> A pre-built devcontainer is set up for the bootcamp and should be used to avoid this delay.

The container used by Codespaces is built from [Dockerfile](gem5/util/dockerfiles/devcontainer/Dockerfile).
It contains:

* All gem5 dependencies (inc. optional dependencies).
* Prebuilt gem5 binaries:
  * `/usr/local/bin/gem5-chi` (`/usr/local/bin/gem5`) (gem5 ALL ISAs with CHI protocol)
  * `/usr/local/bin/gem5-mesi` (default gem5 ALL build with MESI_Two_Level)
  * `/usr/local/bin/gem5-vega` (x86-only with GPU protocol)
* A RISCV64 and an AARCH64 GNU cross-compiler:
  * RISCV64 GNU cross-compiler found in `/opt/cross-compiler/riscv64-linux/`.
  * AARCH64 GNU cross-compiler found in `/opt/cross-compiler/aarch64-linux/`.

## Beginners' example

The following can be used within the Codespace container to run a basic gem5 simulation straight away:

```sh
gem5 gem5/configs/example/gem5_library/arm-hello.py
```

This will execute a "Hello world!" program inside a simulated ARM system.

## Updating submodules

In this project we have two submodules: 'gem5' and 'gem5-resources'.
These are automatically obtained when the codespaces is initialized.
At the time of writing the 'gem5' directory is checked out to the stable branch at v24.0.0.0.
The 'gem5-resources' repository is checked out to revision '97532302', which should contain resources with known compatibility with gem5 v24.0.

To update the git submodules to be in-sync with their remote origins (that hosted on our [GitHub](https://github.com/gem5/gem5)), execute the following command:

```sh
git submodule sync   # Only needed if submodule remotes changed
git submodule update --remote
```

This repository may be updated to these in-sync submodules by running the following (this assumes you have correct permissions to do so):

```sh
git add gem5 gem5-resources
git commit -m "git submodules updated"
git push
```

## Creating content

See [creating-content.md](creating-content.md) for more information on how to create content for the gem5 bootcamp.
