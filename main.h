#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdarg.h>
int _printf(const char *format, ...);
int _putchar(char c);
int check_specifier(const char *format, va_list args);
int print_decimal(int num);
int print_int(int num);
#endif

