#ifndef MODELS_H
#define MODELS_H

#include "../utils/hash_table.h"

typedef struct {
    char* name;
    HashTable simulation_spaces;
    int next_space_id;
} tUser, *User;

typedef struct {
    char* id;
    // TODO: Mais coisas
} tSpace, *Space;

User new_user(char* name);

void free_user(User user);

int user_num_spaces(User user);

int user_num_simulations(User user);

char* user_get_name(User user);

Space new_space(char* space_id);

void free_space(void* space);

#endif