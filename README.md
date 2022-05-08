# `libxerrh` - Extended Error Handling

## Contents

### General Information

- [What is `libxerrh`?](#what-is-libxerrh)
- [How do I install `libxerrh`?](#how-do-i-install-libxerrh)
- [Project Manifest](#project-manifest)
- [Running Tests](#running-tests)

### API Reference

- [Enum: `xe_Code`](#enum-xecode)

---

## What is `libxerrh`?

`libxerrh` is a small C library that provides an extension to the error reporting capabilities afforded by the C standard library. It provides a canonical set of error codes that can be used an any C library or application code to provide consistency in error reporting. It also provides convenience functions for reporting warnings and fatal errors to `stderr`.

---

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

---

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

---

## Running Tests

`libxerrh` includes a handful of small test programs you can build and then run using the included Python test harness. To build the tests, run the following:

```console
foo@BAR:~/my_projects/libxerrh$ make tests
```

After building the tests, you can either run them one at a time (an exit code of `0` indicates success), or all at once using the included Python test harness `runtests.py`:

```console
foo@BAR:~/my_projects/libxerrh$ ./runtests.py
```

If you want to skip any of the tests, update the respective `.c` file to immediately return the exit code `100`.

---

## Enum: `xe_Code`

```c
typedef enum xe_Code;
```

This enum contains all error codes which can be used as return data for library functions which report error statuses through return data. The member values correspond to the exit code that is used when the code is passed into the `xe_fatal` function.

### Members

| Name | Value | Description |
|---|---|---|
| `xe_OK` | `0` | The function completed execution successfully with no errors to report. |
| `xe_GEN` | `1` | A general error occurred. |
| `xe_RUNTM` | `1` | A runtime error occurred (alias of `xe_GEN`). |
| `xe_MEM` | `3` | An attempt to allocate heap memory failed. |
| `xe_MATH` | `4` | A math error occurred. |
| `xe_OVER` | `5` | An overflow condition was detected. |
| `xe_UNDER` | `6` | An underflow condition was detected. |
| `xe_FLOAT` | `7` | A floating-point arithmetic error occurred. |
| `xe_DIVZ` | `8` | An attempt to divide by zero was made. |
| `xe_BUF` | `9` | A buffer error occurred. |
| `xe_EOF` | `10` | An operation failed because the end of a file was reached. |
| `xe_EOS` | `11` | An operation failed because the end of a stream was reached. |
| `xe_LOOK` | `12` | A lookup attempt failed. |
| `xe_INDEX` | `13` | An attempt to access an out-of-bounds array index was made. |
| `xe_KEY` | `14` | An attempt to get the value of an unknown key was made. |
| `xe_IO` | `15` | A general IO error occurred. |
| `xe_NOFILE` | `16` | The requested file does not exist. |
| `xe_NODIR` | `17` | The requested directory does not exist. |
| `xe_IN` | `18` | Unexpected input was detected. |
| `xe_DATA` | `19` | Input contained unexpected or malformed data. |
| `xe_TYPE` | `20` | Input was of the incorrect type. |
| `xe_EXT` | `21` | An external service reported an error. |
| `xe_CNXN` | `22` | A connection with an external service failed. |
| `xe_AUTH` | `23` | Authentication with an external service failed. |
| `xe_LOST` | `24` | The requested resource was not found. |
| `xe_CONFL` | `25` | An operation failed due to a resource conflict. |
| `xe_OS` | `26` | A general OS error occurred. |
| `xe_NET` | `27` | A network error occurred. |
| `xe_NIMPL` | `28` | The requested feature is not implemented yet. |
| `xe_OBS` | `29` | The requested feature is obsolete. |
| `xe_TESTSKIP` | `100` | Special code used by test harnesses to identify skipped tests. |
| `xe_TESTTODO` | `101` | Special code used by test harnesses to identify todo tests. |
| `xe_TESTFORCE` | `102` | Special code used by test harnesses identify tests that were force failed. |

### History

| Version Number | Comments |
|---|---|
| `v1.0.0` | Added to public API. |