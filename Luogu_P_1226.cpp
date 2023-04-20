#include <bits/stdc++.h>
using namespace std;
using li = long long int;
long long int sqr(li x){return x*x;}
long long int fastpow(li a,li b,li p){
    if (b==0) return 1;
    if (b==1) return a%p;
    if (b&1) return a*fastpow(a,b-1,p)%p;
    else return sqr(fastpow(a,b>>1,p)%p)%p;
}
int main(){
    li a,b,p;
    cin>>a>>b>>p;
    cout<<a<<'^'<<b<<" mod "<<p<<'='<<fastpow(a,b,p);
    return 0;
}