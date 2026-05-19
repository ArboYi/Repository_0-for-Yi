#include <stdio.h>
#include <string.h>

void del(char *str, const char *sub);

int main(){
    char str[100];
    char sub[100];

    if (fgets(str, sizeof(str), stdin) == NULL) {
        return 0;
    }
    if (fgets(sub, sizeof(sub), stdin) == NULL) {
        return 0;
    }

    str[strcspn(str, "\n")] = '\0';    // strcspn
    sub[strcspn(sub, "\n")] = '\0';

    del(str, sub);
    return 0;
}

void del(char *str, const char *sub){
    char result[100];
    char *q = result;
    size_t len = strlen(sub);

    if (len == 0) {
        printf("%s", str);
        return;
    }

    while (*str != '\0'){
        if (strncmp(str, sub, len) == 0){
            str += len;
        } else {
            *q = *str;
            q++;
            str++;
        }
    }

    *q = '\0';
    printf("%s", result);
}
