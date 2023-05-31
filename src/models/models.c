#define _POSIX_C_SOURCE 200809L

#include "models.h"

#include <stdlib.h>
#include <string.h>

User new_user(char* name) {
    User user = malloc(sizeof(tUser));
    user->name = strdup(name);
    user->next_space_id = 1;
    user->simulation_spaces = hash_table_create(0, NULL, NULL, NULL, free_space);
    return user;
}

void free_user(User user) {
    free(user->name);
    hash_table_destroy(user->simulation_spaces);
    free(user);
    // TODO: Falta atualizar para os novos campos de User.
}

int user_num_spaces(User user) {
    return hash_table_size(user->simulation_spaces);
}

int user_num_simulations(User user) {
    // TODO: unimplemented function stub
    return 0;
}

char* user_get_name(User user) {
    return user->name;
}

Space new_space(char* space_id) {
    Space space = malloc(sizeof(tSpace));
    space->id = strdup(space_id);
    return space;
}

void free_space(void* space) {
    Space s = (Space)space;
    free(s->id);
    free(s);
}