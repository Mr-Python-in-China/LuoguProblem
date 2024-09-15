#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
typedef unsigned int ui;
int main(void){
    ui n,m;scanf("%d%d",&n,&m);
    ui *a=(ui*)malloc(n*sizeof(ui)),
       *b=(ui*)malloc(n*sizeof(ui)),
       *c=(ui*)malloc(n*sizeof(ui));
    for (size_t i=0;i<n;++i) a[i]=i+1,b[i]=n-i;
    while (m--){
        ui l,r;scanf("%d%d",&l,&r);--l;
        memmove(c,a+l,(r-l)*sizeof(ui));
        memmove(a+l,b+n-r,(r-l)*sizeof(ui));
        memmove(b+n-r,c,(r-l)*sizeof(ui));
    }
    for (size_t i=0;i<n;++i) printf("%d ",a[i]);
    return 0;
}