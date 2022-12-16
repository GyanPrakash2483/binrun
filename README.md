# binrun
Termux package to run binaries stored on external storage.

Internal storage on android is mounted with `noexec` flag which prevents any file to have executable permission.

# How binrun works
Binrun copies the binary executable file to `data` directory where it can have executable permission, makes it executable, executes it with passed arguments, and then deletes it.

# Usage

```
binrun <path/to/executable> <arguments to pass ...>
```

# Compiling

*Requirements: *
cmake, C compiler and toolchain(llvm recommended)

```
git clone https://github.com/GyanPrakash2483/binrun.git
cd binrun
mkdir build && cd build
cmake ..
make
make install
```

# Dependencies

Please make sure `chmod` and `termux-elf-cleaner` is installed for this to work properly.
