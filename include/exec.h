#ifndef EXEC_H
#define EXEC_H

#include <config.h>

typedef enum {
    ERR_OK = 0,
    ERR_INPUT,
} EXEC_ERR;

EXEC_ERR run(Config config);

char *get_exec_error_message(EXEC_ERR code);

#endif