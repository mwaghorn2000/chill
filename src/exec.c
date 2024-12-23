#include <exec.h>
#include <stdio.h>
#include <string.h>
#include <parser.h>

EXEC_ERR get_input(char *input, size_t size);

#define BUFFER 2048

EXEC_ERR run(Config config) {
    char *cursor = config->cursor;
    while(1) {
        printf("%s", cursor);
        fflush(stdout);

        char input[BUFFER];
        EXEC_ERR err = get_input(input, BUFFER);
        if (err) {
            return err;
        }

        parse_arg(input);
    }

    return ERR_OK;
}

/*
    Puts the users input of size into the input buffer
 */
EXEC_ERR get_input(char *input, size_t size) {
    if (fgets(input, size, stdin)) {
        // remove trailing newline if it exists
        input[strcspn(input, "\n")] = '\0';
    } else {
        return ERR_INPUT;
    }

    return ERR_OK;
}

char *get_exec_error_message(EXEC_ERR code) {
    switch (code) {
        case ERR_OK: return "No error";
        case ERR_INPUT: return "User input error";
        default: return "Unknown error";
    }
}

