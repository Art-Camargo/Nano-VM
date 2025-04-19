#include <stdio.h> 
#include <dirent.h> 
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100
#define MAX_FILENAME 256

int find_files(const char *relative_path, char files[][MAX_FILENAME], int max_files) {
    struct dirent *de;
    DIR *dr = opendir(relative_path);

    if (dr == NULL) {
        perror("Could not open directory");
        exit(EXIT_FAILURE);
    }

    int i = 0;
    while ((de = readdir(dr)) != NULL && i < max_files) {
        if (de->d_type == 8 && strstr(de->d_name, ".txt")) {
            strncpy(files[i], de->d_name, MAX_FILENAME - 1);
            files[i][MAX_FILENAME - 1] = '\0'; 
            i++;
        }
    }

    closedir(dr);
    return i;
}