#include<stdio.h>

int f(char *s,int *a)

{
    if (s==NULL) return 0; //如果字符串为空，返回0
    int n=0; //记录找出的整数的个数
    char *p=s; //定义指针p指向字符串s的首地址
    while (*p!='\0') //当指针p没有指向字符串的末尾时，继续循环
    {
        if (*p>='0' && *p<='9') //如果指针p指向的字符是数字字符
        {
            a[n]=0; //将数组a的第n个元素初始化为0
            while (*p>='0' && *p<='9') //当指针p指向的字符是数字字符时，继续循环
            {
                a[n]=a[n]*10+(*p-'0'); //将指针p指向的数字字符转换为整数，并累加到数组a的第n个元素中
                p++; //指针p向后移动一个字符
            }
            n++; //找出一个整数，n加1
        }
        else p++; //如果指针p指向的字符不是数字字符，指针p向后移动一个字符
    }   
    return n; //返回值为找出的整数的个数

}

int main()

{

    char s[100]="";

    int a[50]={0};

    int n,i;

    fgets(s,sizeof(s),stdin); //从标准输入读取字符串s

    n=f(s,a);

    for(i=0;i<n;i++)

        printf("%d\n",a[i]);

    return 0;

 }