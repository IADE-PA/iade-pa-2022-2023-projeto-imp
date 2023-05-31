#include "controllers.h"
#include "../models/models.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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

int compare_users(const void* u1, const void* u2) {
    User* user1 = (User*)u1;
    User* user2 = (User*)u2;
    return strcmp((*user1)->name, (*user2)->name);
}

User* get_sorted_user_array(App app) {
    List user_list = hash_table_values(app->users);
    int num_users = get_num_users(app);
    User* user_array = malloc(sizeof(User) * num_users);
    int idx = 0;
    list_iterator_start(user_list);
    while(list_iterator_has_next(user_list)) {
        User user = list_iterator_get_next(user_list);
        user_array[idx++] = user;
    }
    list_destroy(user_list, NULL);
    qsort(user_array, num_users, sizeof(User), compare_users);
    return user_array;
}

int get_num_users(App app) {
    return hash_table_size(app->users);
}
