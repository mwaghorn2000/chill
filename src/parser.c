#include <parser.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct token_list {
    Token token;
    struct token_list *next;
} *TokenList;

Token_dep_tree parse_arg(char* arg);
static TokenList get_token_list(char* arg);
static Token get_token(char* token);
static void free_token_list(struct token_list *head);
static void print_token_list(struct token_list *head);

Token_dep_tree parse_arg(char* arg) {
    TokenList token_list = get_token_list(arg);
    
    
    return NULL;
}

static TokenList get_token_list(char* arg) {
    char* token = strtok(arg, " ");

    TokenList head = NULL;
    TokenList curr = head;
    while (token != NULL) {
        TokenList new_node = malloc(sizeof(struct token_list));
        if (new_node == NULL) {
            fprintf(stderr, "Error: Failed to allocate memory\n");
            free_token_list(head);
            exit(EXIT_FAILURE);
        }

        new_node->token = get_token(token);
        new_node->next = NULL;

        if (head == NULL) {
            head = new_node;
        } else {
            curr->next = new_node;
        }
        curr = new_node;
        token = strtok(NULL, " ");
    }

    return head;
}

static Token get_token(char* token) {
    Token new_token = malloc(sizeof(struct token));
    if (new_token == NULL) {
        fprintf(stderr, "ERROR: Failed to allocate memory\n");
        exit(EXIT_FAILURE);
    }

    new_token->contents = strdup(token);
    if (new_token->contents == NULL) {
        fprintf(stderr, "ERROR: Failed to allocate memory\n");
        free(new_token);
        exit(EXIT_FAILURE);
    }

    if (strcmp(new_token->contents , "|") == 0) {
        new_token->type = TOKEN_PIPE;
    } else if (strcmp(new_token->contents, ">") == 0) {
        new_token->type = TOKEN_OUTPUT;
    } else if (strcmp(new_token->contents, "<") == 0) {
        new_token->type = TOKEN_INPUT;
    } else if (strcmp(new_token->contents, ">>") == 0) {
        new_token->type = TOKEN_APPEND;
    } else if (strcmp(new_token->contents, "<<") == 0) {
        new_token->type = TOKEN_HEREDOC;
    } else {
        new_token->type = TOKEN_UNKNOWN;
    }

    return new_token;
} 

static void free_token_list(struct token_list *head) {
    while (head) {
        TokenList temp = head;
        if (head->token) {
            free(head->token->contents);
            free(head->token);
        }
        head = head->next;
        free(temp);
    }
}

static void print_token_list(TokenList head) {
    TokenList curr = head;
    while (curr) {
        printf("Token: '%s', Type:'%d'\n", curr->token->contents, curr->token->type);
        curr = curr->next;
    }
}