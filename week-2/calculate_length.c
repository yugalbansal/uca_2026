#include <stdio.h> 

int my_strlen(const char *str){
    int length = 0;
    while(*str != '\0'){
        length++;
        str++;
    }
    return length;
}

int main() {
    char str[] = "hello world";
    int length = my_strlen(str);
    printf("Length : %d\n", length);
    return 0;
}