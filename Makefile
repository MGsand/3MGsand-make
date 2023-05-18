.PHONY: clean

CFLAGS = -Wall -Wextra -Werror
CPPFLAGS = -MMD

LIBPATH = obj/src/lib

all: bin/geometry

test: bin/gtest

bin/geometry: obj/src/geometry/geometry.o obj/src/lib/lib.a
	$(CC) $(CFLAGS) -o $@ $^

bin/gtest: test/main.o obj/src/lib/sum.o  thirdparty/ctest.h obj/src/lib/circle.o 
	$(CC) $(CFLAGS) -o $@ $^

test/main.o: test/main.c
	$(CC) -c $(CFLAGS) $< $(CPPFLAGS) -o $@ -I test

obj/src/lib/sum.o: thirdparty/sum.c 
	$(CC) -c $(CFLAGS) $< $(CPPFLAGS) -o $@ -I src/lib

obj/src/lib/lib.a: obj/src/lib/circle.o
	ar rcs $@ $^

obj/src/geometry/geometry.o: src/geometry/geometry.c
	$(CC) -c $(CFLAGS) $< $(CPPFLAGS) -o $@ -I src/lib
	
obj/src/lib/circle.o: src/lib/circle.c src/lib/circle.h
	$(CC) -c $(CFLAGS) $< $(CPPFLAGS) -o $@ -I src/lib
	
clean: 
	rm bin/geometry
	rm obj/src/geometry/*.d
	rm obj/src/geometry/*.o
	rm obj/src/lib/*.d
	rm obj/src/lib/*.o
	rm obj/src/lib/*.a

-include obj/src/geometry/geometry.d obj/src/lib/circle.d
