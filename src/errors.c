#include <stdio.h>
#include <stdlib.h>

// use this for debugging
// TODO: Make it log to a file
void panic(const char *message, const char *file, const char *func, int line) {
	fprintf(stderr, "PANIC: %s\n", message);
	fprintf(stderr, "Occured at: %s:%d, in function %s\n", file, line, func);
	abort();
}
