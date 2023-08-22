#include "main.h"
#include <stdio.h>

int _printf(const char *format, ...) {
    va_list args;
    va_start(args, format);

    int count = 0;
    
    while (*format != '\0') {
        if (*format == '%') {
            format++; 
            switch (*format) {
                case 'c':
                    putchar(va_arg(args, int));
                    count++;
                    break;
                case 's': {
                    char *str = va_arg(args, char *); 
                    while (*str != '\0') {
                        putchar(*str); 
                        str++;
                        count++;
                    }
                    break;
                }
                case 'd':
                case 'i': {
                    int num = va_arg(args, int);
                    printf("%d", num); 
                    count += num < 0 ? 2 : 1;  
                    break;
                }
                case '%':
                    putchar('%'); 
                    count++;
                    break;
                default:
                    
                    break;
            }
