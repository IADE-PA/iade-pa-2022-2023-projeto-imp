#ifndef CONTROLLERS_H
#define CONTROLLERS_H

#include "../utils/hash_table.h"

typedef struct {
    HashTable users;
} tApp, *App;

App new_app();

void free_app(App app);

bool has_user(App app, char* name);

void register_user(App app, char* name);

char* register_space(App app, char* user_name);

#endif