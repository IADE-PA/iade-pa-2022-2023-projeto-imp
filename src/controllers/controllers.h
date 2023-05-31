#ifndef CONTROLLERS_H
#define CONTROLLERS_H

#include "../utils/hash_table.h"
#include "../models/models.h"

typedef struct {
    HashTable users;
} tApp, *App;

App new_app();

void free_app(App app);

bool has_user(App app, char* name);

void register_user(App app, char* name);

char* register_space(App app, char* user_name);

// bool has_users(App app);

User* get_sorted_user_array(App app);

int get_num_users(App app);

#endif