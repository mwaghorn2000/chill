#include <config.h>
#include <stdlib.h>

Config get_default_config(void) {
    Config new_config = malloc(sizeof(struct config));
    new_config->cursor = "> ";
    return new_config;
}

Config get_config(void) {
    return get_default_config();
}