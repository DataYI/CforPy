#include "test.h"
// #include <string>
#include <stdlib.h>
#include <cstring>

int WINAPI Add(int x, int y) {
    return x + y;
}

int WINAPI Del(int x, int y) {
    return x - y;
}

char * WINAPI Concat(char *s1, char *s2) {
    char *s = (char *)malloc(strlen(s1) + strlen(s2) + 1);
    if (s == NULL) exit(1);
    char *temp = s;
    while (*s1 != '\0') *s++ = *s1++;
    while (*s2 != '\0') *s++ = *s2++;
    return temp;
}