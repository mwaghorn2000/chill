#ifndef PARSER_H
#define PARSER_H

typedef enum {
    TOKEN_COMMAND = 0,
    TOKEN_ARGUMENT,
    TOKEN_PIPE,
    TOKEN_INPUT,
    TOKEN_OUTPUT,
    TOKEN_APPEND,
    TOKEN_HEREDOC,
    TOKEN_UNKNOWN,
} Token_type;

typedef struct token {
    Token_type type;
    char *contents;
} *Token;

typedef struct dep_tree {
    Token token;
    Token left;
    Token right;
} *Token_dep_tree;

Token_dep_tree parse_arg(char* arg);

#endif