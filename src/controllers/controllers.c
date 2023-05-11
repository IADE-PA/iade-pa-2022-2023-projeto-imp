#include "controllers.h"
#include "../models/models.h"

#include <stdlib.h>

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