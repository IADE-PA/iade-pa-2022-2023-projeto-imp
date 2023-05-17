#include "controllers.h"
#include "../models/models.h"

#include <stdlib.h>
#include <stdio.h>

App new_app() {
    App app = malloc(sizeof(tApp));
    app->users = hash_table_create(0, NULL, NULL, NULL, (void (*)(void*))free_user);
    return app;
}

void free_app(App app) {
    hash_table_destroy(app->users);
    free(app);
}

bool has_user(App app, char* name) {
    return hash_table_get(app->users, name) != NULL;
}

void register_user(App app, char* name) {
    User user = new_user(name);
    hash_table_insert(app->users, name, user);
}

char* register_space(App app, char* user_name) {
    User user = hash_table_get(app->users, user_name);
    // 0. Criar o identificador de espaço
    char space_id[80];
    sprintf(space_id, "%d", user->next_space_id);
    user->next_space_id++;
    // 1. Criar um novo espaço
    Space space = new_space(space_id);
    // 2. Colocar o espaço na tabela de dispersão de espaços de simulação, do utilizador
    hash_table_insert(user->simulation_spaces, space->id, space);
    return space->id;
}