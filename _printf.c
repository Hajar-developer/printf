#include "main.h"
#include <stdio.h>
#include <stdarg.h>

int _printf(const char *format, ...)
 {
    int counter = 0;
    va_list args;
    va_start(args, format);

    for (const char *ptr = format; *ptr; ++ptr) {
        if (*ptr != '%') {
            putchar(*ptr);
            counter++;
        } else {
            ptr++;
            switch (*ptr) {
                case 'c': {
                    char c = (char) va_arg(args, int);
                    putchar(c);
                    counter++;
                    break;
                }
                case 's': {
                    const char *s = va_arg(args, const char *);
                    for (; *s; ++s) {
                        putchar(*s);
                        counter++;
                    }
                    break;
                }
                case '%': {
                    putchar('%');
                    counter++;
                    break;
                }
                default: {
                    // error: unknown conversion specifier
                    break;
                }
            }
        }
    }

    va_end(args);
    return (counter);
}

int main() {
    _printf("Hello, World! %c %s %% %%%%\n", 'A', "example", "errors", 42);
    return (0);
}

