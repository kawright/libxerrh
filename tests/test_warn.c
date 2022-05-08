/*
This file contains a test for ensuring `xe_warn` works correctly.
*/

#include "../src/xerrh.h"

int main(int argc, char *argv[]) {

    xe_warn(xe_RUNTM, "A fake runtime error occurred!");
    xe_warn(xe_DIVZ, "A fake divide-by-zero error occurred!");
    xe_warn(xe_OS, "A fake operating system error occurred!");

    return 0;
}