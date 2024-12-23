#ifndef ERRORS_H
#define ERRORS_H

void panic(const char *message, const char *file, const char *func, int line);

#define PANIC(msg) panic(msg, __FILE__, __func__, __LINE__)

#endif