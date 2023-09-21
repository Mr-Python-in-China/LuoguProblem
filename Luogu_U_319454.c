#include<stdio.h>
#include<string.h>
#define N ((size_t)4.5e7)
char s[N];
int main(void){
    int res=fread(s,N,1,stdin);
    if (res==0)
        fwrite(s,strlen(s),1,stdout);
    return 0;
}