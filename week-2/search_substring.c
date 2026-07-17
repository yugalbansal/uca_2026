#include <stdio.h>

int find_substring(const char *haystack, const char *needle){
    const char *n = needle;
    const char *ans = NULL;
    const char *h = haystack;
    if (*needle == '\0')
    return 0;
    while(*h != '\0'){
        if(*n == *h){
            ans = h;
            while(*n != '\0' && *h != '\0' && *n == *h){
                n++;
                h++;
            }
            if(*n == '\0'){
                return ans - haystack;
            }
            else {
                n = needle;
                h = ans + 1;
            }
        }
        else {
            h++;
        }
    }
    return -1;
}

int main(){
    char haystack[] = "Embedded Systems";
    char needle[] = "bed";
    int ans = find_substring(haystack, needle);
    printf("string found at : %d\n", ans);
    return 0;
}