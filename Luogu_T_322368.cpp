#include<bits/stdc++.h>
using namespace std;
using ui=unsigned int;
inline double PVIFA(double i,int n){return (1-pow(1.0+i,-n))/i;}
int main(void){
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    ui n,i;
    cin>>n>>i;
    cout<<fixed<<setprecision(4);
    for (ui j=1;j<=i;j++) cout<<'\t'<<j<<'%';
    cout.put('\n');
    for (ui x=1;x<=n;x++){
        cout<<x;
        for (ui y=1;y<=i;y++) cout<<'\t'<<PVIFA(y*0.01,x);
        cout.put('\n');
    }
    return 0;
}