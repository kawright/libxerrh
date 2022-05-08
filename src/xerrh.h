/*
 This file contains the definitions of all public API members in the
 `libxerrh` library.
*/

#ifndef XERRH_H_
#define XERRH_H_

/*
Contains all error codes which can be used as return data for library functions
which report their error statuses using return data. The values correspond to
the exit code that is used when the code is used with the `xe_fatal` function.
*/
typedef enum {

    // Non-error:
    xe_OK = 0,

    // General-errors:
    xe_GEN = 1,
    xe_RUNTM = 1,
    
    // Memory:
    xe_MEM = 3,

    // Math:
    xe_MATH = 4,
    xe_OVER = 5,
    xe_UNDER = 6,
    xe_FLOAT = 7,
    xe_DIVZ = 8,

    // Buffer:
    xe_BUF = 9,
    xe_EOF = 10,
    xe_EOS = 11,

    // Lookup:
    xe_LOOK = 12,
    xe_INDEX = 13,
    xe_KEY = 14,

    // IO:
    xe_IO = 15,
    xe_NOFILE = 16,
    xe_NODIR = 17,

    // Input:
    xe_IN = 18,
    xe_DATA = 19,
    xe_TYPE = 20,

    // Service:
    xe_EXT = 21,
    xe_CNXN = 22,
    xe_AUTH = 23,
    xe_LOST = 24,
    xe_CONFL = 25,

    // Other:
    xe_OS = 26,
    xe_NET = 27,
    xe_NIMPL = 28,
    xe_OBS = 29,

    // Testing:
    xe_TESTSKIP = 100,
    xe_TESTTODO = 101,
    xe_FORCE = 102

} xe_Code;

/*
Immediately terminate the current process with the given error code and 
explaination, which will be reported to `stderr` before returning.
*/
void xe_fatal(xe_Code code, char *explain);

/*
Report a warning to stderr.
*/
void xe_warn(xe_Code code, char *explain);

#endif