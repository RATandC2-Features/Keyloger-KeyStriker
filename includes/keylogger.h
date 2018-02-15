#ifndef KEYLOGGER_H_INCLUDED
#define KEYLOGGER_H_INCLUDED

void keylogger(char *deviceFile) __attribute__((noreturn));

void Rshift_used(char *deviceFile) __attribute__((noreturn));

void Lshift_used(char *deviceFile) __attribute__((noreturn));

void Rshift_used_sustained(char *deviceFile) __attribute__((noreturn));

void Lshift_used_sustained(char *deviceFile) __attribute__((noreturn));

#endif // KEYLOGGER_H_INCLUDED


