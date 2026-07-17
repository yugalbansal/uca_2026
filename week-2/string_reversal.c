#include <stdio.h>
#include <string.h>

void reverse_string(char *str){
    char *left = str;
    char *right = str + strlen(str) - 1;
    while(left < right){
        char temp = *left;
        *left = *right;
        *right = temp;
        left++;
        right--;
    }
}

int main(){
    char str[] = "hello";
    reverse_string(str);
    printf("reversed string: %s\n", str);
    return 0;
}