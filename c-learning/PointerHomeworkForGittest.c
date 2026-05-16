#include <stdio.h>
int main(){
	char a[20], b[20];
	int n, i, count;
	char *p;
	gets(a);
	scanf("%d", &n);
	p = a;
	i=0;
	for(count=0;*p!='\0';count++)p++;
	if (count > n){
		p = a;
		p += n-1;
		for (;*p!='\0';p++){
			b[i] = *p;
			i++;
		}
		printf("%s,%s", a, b);
	}
	else printf("%s,",a);
	
	return 0;
}