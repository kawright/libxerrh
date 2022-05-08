BUILD_DIRS = build \
	build/obj \
	build/lib \
	build/tests

TEST_BINS = build/tests/test_fatal \
	build/tests/test_warn

.PHONY: clean tests library install uninstall

tests: $(TEST_BINS)

library: build/lib/xerrh.a

# T E S T    B I N A R I E S

build/tests/%: build/obj/%.o build/obj/xerrh.o
	@echo -n COMPILING TEST $@...
	@gcc -g -Wall -o $@ $< build/obj/xerrh.o
	@echo DONE!

# T E S T    O B J E C T    F I L E S

build/obj/%.o: tests/%.c
	@ echo -n BUILDING $@...
	@ gcc -g -Wall -o $@ -c $<
	@ echo DONE!

# L I B R A R I E S

build/lib/libxerrh.a: build/obj/xerrh.o
	@ echo -n ARCHIVING build/lib/libxerrh.a
	@ ar rcs build/lib/libxerrh.a build/obj/xerrh.o
	@ echo DONE!

# O B J E C T    F I L E S 

build/obj/xerrh.o: src/xerrh.c src/xerrh.h
	@ echo -n BUILDING xerrh.o...
	@ gcc -g -Wall -o build/obj/xerrh.o -c src/xerrh.c
	@ echo DONE!

install: library
	@ echo -n COPYING FILES...
	@ cp build/lib/libxerrh.a /usr/local/lib/libxerrh.a
	@ cp src/xerrh.h /usr/local/include/xerrh.h
	@ echo -n DONE!

uninstall:
	@ echo -n DELETING FILES...
	@ rm -f /usr/local/lib/libxerrh.a
	@ rm -f /usr/local/include/xerrh.h
	@ echo -n DONE!

clean:
	@ echo -n CLEANING BUILD DIRECTORY...
	@ rm -Rf build
	@ echo DONE!

$(shell mkdir -p $(BUILD_DIRS))