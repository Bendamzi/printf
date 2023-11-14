#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
int _printf(const char *format, ...);
int _putchar(char c);
int check_specifier(const char *format, va_list args);
#endif
