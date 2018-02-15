#include <stdlib.h>
#include <stdio.h>  // printf()
#include <unistd.h>  // geteuid()
#include <syslog.h>  // syslog()
#include <errno.h>
#include <string.h>  //strerror()
#include <sys/stat.h>  // umask()

#include "../includes/utils.h"

static void getRoot(void);

static void daemonize(void);

int main (int argc, char *argv[])
{
    daemonize();

    getRoot();

    /*const char *command = "grep -E 'Handlers|EV' /proc/bus/input/devices | \
                            grep -B1 120013 |  grep -Eo event[0-9]";
    */

    const char *command = "find /dev/input/by-id -name '*Device*'";

    get_kb_device_filename(command);

    return EXIT_SUCCESS;
}

static void getRoot(void)
{
    if(getuid() != 0)
    {
        printf("Must be Root nigga !\n");
        exit(-1);
    }
}


static void daemonize(void)
{
    /* PID après appelle de fork() */
    pid_t pid;

    /* Verification : est ce que le processus qui s'execute est déjà un démon, si oui on quit */
    if(getppid() == 1)
        return;

    /* duplication du processus via fork() */

    pid = fork();
    if(pid < 0)
    {
        syslog(LOG_ERR, "fork() failed : %d : %s", errno, strerror(errno));
        exit(EXIT_FAILURE);
    }

    /* on tue le processus père, dur la vie */
    if(pid > 0)
        exit(EXIT_SUCCESS);

    /* on donne tous les droits d'écriture/lecture au démon sur les fichiers qu'il crée */
    umask(0222);

    /*Création d'une nouvelle session, afin que le fils ne recoive pas les signaux destiné au père */
    if(setsid() < 0)
    {
        syslog(LOG_ERR, "setsid failed : %d : %s", errno, strerror(errno));
        exit(EXIT_FAILURE);
    }

    /* Redirection des E/S standard afin déviter toute sortie vers le terminal utilisateur */
    if( freopen("/dev/null", "r", stdin) == NULL )
        error("freopen() stdin\nFonction : main()");

    if( freopen("/dev/null", "w", stdout) == NULL )
        error("freopen() stdout\nFonction : main()");

    if( freopen("/dev/null", "w", stderr) == NULL )
        error("freopen stderr\nFonction : main");

    return;
}






