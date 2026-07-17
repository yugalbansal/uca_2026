#include <stdio.h> 

void url_encode(char *str, int true_length){
    char *s = str;
    int count = 0;
    for (int i = 0; i < true_length; i++) {
    if (str[i] == ' ')
        count++;
    }
    int new_length = true_length + count * 2;
    int i = true_length - 1;
    int j = new_length - 1;
    while(i>=0){
        if(str[i] == ' '){
            str[j--] = '0';
            str[j--] = '2';
            str[j--] = '%';
        }
        else{
            str[j--] = str[i];
        }
        i--;
    }
}

int main(){
    char str[20] = "Hello World";
    url_encode(str, 11);
    printf("%s\n", str);
    return 0;
}