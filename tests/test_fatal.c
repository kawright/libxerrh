/*
This file contains a test for ensuring `xe_fatal` works correctly.
*/

#include "../src/xerrh.h"

int main(int argc, char *argv[]) {
    xe_fatal(xe_OK, "This test works!");
}