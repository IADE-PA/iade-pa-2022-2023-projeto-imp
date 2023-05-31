#include "cli.h"
#include "../controllers/controllers.h"
#include "../models/models.h"

#define _POSIX_C_SOURCE 200809L
#include <stdio.h>

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

void run_cli() {
    char* line = NULL;
    size_t len = 0;
    App app = new_app();
    while (true) {
        getline(&line, &len, stdin);
        line[strlen(line) - 1] = '\0';
        if (strlen(line) == 0) {
            break;
        }
        char* command = strtok(line, " ");
        if (strcmp(command, "RJ") == 0) {
            char* name = strtok(NULL, " ");
            if (has_user(app, name)) {
                printf("Utilizador existente.\n");
            } else {
                register_user(app, name);
                printf("Utilizador registado com sucesso.\n");
            }
        } else if (strcmp(command, "EJ") == 0) {
        } else if (strcmp(command, "LJ") == 0) {
            // if(!has_users(app)) {
            if(get_num_users(app) == 0) {
                printf("Não existem utilizadores registados.\n");
            }
            else {
                User* users = get_sorted_user_array(app);
                int num_users = get_num_users(app);
                for(int i=0; i<num_users; i++) {
                    User user = users[i];
                    int num_spaces = user_num_spaces(user);
                    int num_simulations = user_num_simulations(user);
                    char* name = user_get_name(user);
                    printf("%s %d %d\n", name, num_spaces, num_simulations);
                }
                free(users);
            }
        } else if (strcmp(command, "RE") == 0) {
            char* name = strtok(NULL, " ");
            if (!has_user(app, name)) {
                printf("Utilizador inexistente.\n");
            } else {
                char* space_id = register_space(app, name);
                printf("Espaço de simulação registado com identificador %s.\n", space_id);
            }
        } else if (strcmp(command, "EE") == 0) {
        } else if (strcmp(command, "RP") == 0) {
        } else if (strcmp(command, "AP") == 0) {
        } else if (strcmp(command, "S") == 0) {
        } else {
            printf("Instrução inválida.\n");
        }
        free(line);
        line = NULL;
    }
    if (line != NULL) {
        free(line);
    }
    free_app(app);
}