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

    // No Error
    xe_OK = 0,

    // General Error
    xe_GEN = 1,

    // Runtime Error
    xe_RUNTM = 1,
    
    // Memory Error
    xe_MEM = 3,

    // Math Error
    xe_MATH = 4,

    // Overflow Error
    xe_OVER = 5,

    // Underflow Error
    xe_UNDER = 6,

    // Floating Point Error
    xe_FLOAT = 7,

    // Divide-by-Zero Error
    xe_DIVZ = 8,

    // Buffer Error
    xe_BUF = 9,

    // End of File Error
    xe_EOF = 10,

    // End of Stream Error
    xe_EOS = 11,

    // Lookup Error
    xe_LOOK = 12,

    // Index Error
    xe_INDEX = 13,

    // Key Error
    xe_KEY = 14,

    // IO Error
    xe_IO = 15,

    // File Not Found Error
    xe_NOFILE = 16,

    // Directory Not Found Error
    xe_NODIR = 17,

    // Input Error
    xe_IN = 18,

    // Bad Data Error
    xe_DATA = 19,

    // Bad Type Error
    xe_TYPE = 20,

    // External Service Error
    xe_EXT = 21,

    // Connection Error
    xe_CNXN = 22,

    // Authentication Error
    xe_AUTH = 23,

    // Lost Resource Error
    xe_LOST = 24,

    // Conflict Error
    xe_CONFL = 25,

    // OS Error
    xe_OS = 26,

    // Network Error
    xe_NET = 27,

    // Not Implemented Error
    xe_NIMPL = 28,

    // Obsolete Error
    xe_OBS = 29,

    // Special code used by test harness to find skipped tests.
    xe_TESTSKIP = 100,

    // Special code used by test harness to find todo tests.
    xe_TESTTODO = 101,

    // Special code used by test harness to find test force fails.
    xe_TESTFORCE = 102

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