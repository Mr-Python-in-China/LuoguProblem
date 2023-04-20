#include<bits/stdc++.h>
using namespace std;
using ui=unsigned int;
int main(void){
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    size_t n;
    cin>>n;
    vector<ui> a(n),b(n);
    for (size_t i=0;i<n;i++){
        double x,y;
        cin>>x>>y;
        a[i]=x*1000,b[i]=x*1000;
    }

    return 0;
}