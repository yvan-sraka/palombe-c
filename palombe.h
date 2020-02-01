#include <stdio.h>
#include <stdlib.h>

#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

#include<stdio.h>

char* __mkfifo(char* name) {
    char* prefix = "/tmp/palombe/";
    char* path = (char *) malloc(sizeof(prefix) + sizeof(name));
    strcat(path, prefix);
    strcat(path, name);
    mkdir(prefix, 0777);
    mkfifo(path, 0600);
    return path;
}

void send(char* name, char* value) {
    char* path = __mkfifo(name);
    printf("%s", path);
    printf("%s", path);
    FILE *fp;
    fp = fopen(path, "w");
    fwrite(value, 1, sizeof(value), fp);
    fclose(fp);
}