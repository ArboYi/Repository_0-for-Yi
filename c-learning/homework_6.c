#include <stdio.h>
void del(char *str, char *sub);
int main(){
    char str[100], sub[100];
    fgets(str,sizeof(str),stdin);
    fgets(sub, sizeof(sub), stdin);
    del(str, sub);
    return 0;
}
void del(char *str, char *sub){
    char *p = str;
    char new[100];
    char *q = new;
    char *r = sub;
    while (*p != '\0'){
        if (*p != *r){
            *q = *p;
            p++;
            q++;
        }    
        else p++;
    }
    *q = '\0'; // 在新字符串末尾添加空字符
    printf("%s", new);
}