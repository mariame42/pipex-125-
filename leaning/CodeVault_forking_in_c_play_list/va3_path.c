// #include <stdio.h>
// #include <unistd.h>
// #include <stdlib.h>
// #include <string.h>
// #include <sys/stat.h>

// // Function to get command path using environment variables
// char *get_command_path(const char *command, char **env) {
//     char *path_env = NULL;
//     // Loop through the env variables to find PATH
//     for (int i = 0; env[i] != NULL; i++) {
//         if (strncmp(env[i], "PATH=", 5) == 0) {
//             path_env = env[i] + 5;  // Skip the "PATH=" part
//             break;
//         }
//     }

//     if (!path_env) return NULL;

//     // Split PATH into directories
//     char *path = strdup(path_env);  // Duplicate the PATH string
//     printf("(strdup)path =    %s\n", path);
//     char *dir = strtok(path, ":");
//     printf("(strtok)dir =    %s\n", dir);

//     while (dir != NULL) {
//         // Create full path to the command by appending it to the directory
//         char full_path[1024];
//         snprintf(full_path, sizeof(full_path), "%s/%s", dir, command);

//         // Check if the file exists and is executable using access()
//         if (access(full_path, X_OK) == 0) {
//             free(path);  // Clean up memory
//             return strdup(full_path);  // Return the found path
//         }

//         dir = strtok(NULL, ":");
//         printf("fin (strtok)dir =    %s\n", dir);
//     }

//     free(path);
//     return NULL;  // Command not found
// }

// int main(int ac, char **av, char **env)
// {
//     char *cmd = get_command_path("ls", env);  // Find the path of ls using env
//     printf("cmd =    %s\n", cmd);
//     if (!cmd) {
//         printf("ls command not found in PATH\n");
//         return 1;
//     }

//     free(cmd);  // Clean up memory
//     return 0;
// }

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

char *get_command_path(const char *command, char **env) {
    char *path_env = NULL;

    // Find the PATH environment variable
    for (int i = 0; env[i] != NULL; i++) {
        if (strncmp(env[i], "PATH=", 5) == 0) {
            path_env = env[i] + 5;  // Skip "PATH="
            break;
        }
    }

    if (!path_env) return NULL;

    // Duplicate the PATH string and split into directories
    char *path = strdup(path_env);
    if (!path) return NULL;
    printf ("path : %s\n", path);
    char *dir = strtok(path, ":");
    printf ("dir : %s\n", dir);

    while (dir != NULL) {
        // Create full path to the command
        size_t dir_len = strlen(dir);
        size_t cmd_len = strlen(command);
        char *full_path = malloc(dir_len + cmd_len + 2);  // +2 for '/' and null terminator
        if (!full_path) {
            free(path);
            return NULL;
        }

        // Construct the full path
        memcpy(full_path, dir, dir_len);
        printf("1: fullpath b: %s\n", full_path);
        full_path[dir_len] = '/';
        printf("2: fullpath b: %s\n", full_path);

        memcpy(full_path + dir_len + 1, command, cmd_len);
        printf("3: fullpath b: %s\n", full_path);
        full_path[dir_len + cmd_len + 1] = '\0';
        printf("4: fullpath b: %s\n", full_path);
        // Check if the file exists and is executable
        int i = access(full_path, X_OK);
        if (i == 0) {
            free(path);
            return full_path;  // Return the found path
        }

        free(full_path);
        dir = strtok(NULL, ":");
    }

    free(path);
    return NULL;  // Command not found
}

int main(int ac, char **av, char **env) {
    char *cmd = get_command_path("ls", env);  // Find the path of ls using env
    if (cmd) {
        printf("Command path: %s\n", cmd);
        free(cmd);  // Clean up memory
    } else {
        printf("Command not found in PATH\n");
    }
    return 0;
}
