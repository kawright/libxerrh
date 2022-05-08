/*
This file contains the implementation of the entire `libxerrh` library.
*/

#include <stdio.h>
#include <stdlib.h>

#include "xerrh.h"

void xe_fatal(xe_Code code, char *explain) {

    // Print the explaination string to `stderr`, then exit.
    fprintf(stderr, "ERROR [%d]: %s\n", code, explain);
    exit(code);
}

void xe_warn(xe_Code code, char *explain) {

    fprintf(stderr, "WARNING [%d]: %s\n", code, explain);
    return;
}