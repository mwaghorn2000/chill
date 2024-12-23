#ifndef CONFIG_H
#define CONFIG_H

typedef struct config {
    char *cursor;
} *Config;

Config get_config(void);

#endif
