# `libxerrh` - Extended Error Handling

## Contents

### General Information

- [What is `libxerrh`?](#what-is-libxerrh)
- [How do I install `libxerrh`?](#how-do-i-install-libxerrh)

---

## What is `libxerrh`?

`libxerrh` is a small C library that provides an extension to the error reporting capabilities afforded by the C standard library. It provides a canonical set of error codes that can be used an any C library or application code to provide consistency in error reporting. It also provides convenience functions for reporting warnings and fatal errors to `stderr`.

## How do I install `libxerrh`?

There are a couple of ways to use `libxerrh` in your own C project. No matter which way you choose, the first step will be to clone the `libxerrh` git repository to your local machine:

```console
foo@BAR:~/my_projects$ git clone https://github.com/kawright/libxerrh.git
```

The first--and easiest--way to include `libxerrh` in your project is simply to add `libxerrh.c` and `libxerrh.h` directly into your project.

If you would rather consume `libxerrh` through formal library files, you have a few options. The easiest option would be to run the `install` target through `make`, as such:

```console
foo@BAR:~/my_projects/libxerrh$ sudo make install
```

To uninstall:

```console
foo@BAR:~/my_projects/libxerrh$ sudo make uninstall
```

If you just need to build the library file, use the `library` target:

```console
foo@BAR:~/my_projects/libxerrh$ make library
```

You can find the library file that was created in the `build/lib` directory.

Finally, you can always find the library and header files for each release in its tag information on the GitHub page, available to download in a zip file.

## Project Manifest

This project consists of the following files and folders:

| File/Directory Path | Version Added | Description |
|---|---|---|
| `src` |  `v1.0.0` | This folder contains all source and header files in the `libxerrh` library. |
| `src/xerrh.c` | `v1.0.0` | This file contains the implementation of all public API members of the `libxerrh` library. |
| `src/xerrh.h` | `v1.0.0` | The header file for the `libxerrh` library. |
| `tests` | `v1.0.0` | This folder contains test cases that are written in C and can be run using the `runtests.py` script. |
| `tests/test_fatal.c` | `v1.0.0` | Test case for ensuring `xe_fatal` works correctly. |
| `tests/test_warn.c` |  `v1.0.0` | Test case for ensuring `xe_warn` works correctly. |
| `.gitignore` | `v1.0.0` | The project `.gitignore` file. |
| `CHANGELOG.md` | `v1.0.0` | The project changelog file. |
| `LICENSE` | `v1.0.0` | Contains the text of the license used for this project. |
| `Makefile` | `v1.0.0` | The project `Makefile` file. |

