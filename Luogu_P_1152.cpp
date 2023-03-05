#include<bits/stdc++.h>
using namespace std;
using ui=unsigned int;
int main(void){
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    size_t n;
    cin>>n;
    vector<ui> chk(n);
    int lst;
    cin>>lst;
    for (size_t i=1;i<n;i++){
        int x;
        cin>>x;
        ui t=abs(lst-x);
        if (t<1||t>n||chk[t]) 
            return cout<<"Not jolly",0;
        chk[t]=true;lst=x;
    }
    cout<<"Jolly";
    return 0;
}