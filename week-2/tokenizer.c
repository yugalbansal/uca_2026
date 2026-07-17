// strtok() that takes the string "C,C++,Java,Python,Rust" and prints each language on a new line
#include <stdio.h>
#include <string.h>

int main() {

    char str[] = "C,C++,Java,Python,Rust";

    char *token = strtok(str, ",");

    while (token != NULL) {
        printf("%s\n", token);
        token = strtok(NULL, ",");
    }

    return 0;
}