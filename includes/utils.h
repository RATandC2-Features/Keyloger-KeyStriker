#ifndef UTILS_H_INCLUDED
#define UTILS_H_INCLUDED


void get_kb_device_filename(const char *command) __attribute__((noreturn));

void error(const char *expression) __attribute__((noreturn));

void open_kb_device(char *deviceFile);

#endif


