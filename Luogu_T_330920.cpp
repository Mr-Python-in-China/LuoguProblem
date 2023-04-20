#include<bits/stdc++.h>
using namespace std;
using ui=unsigned int;
int main(void){
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    size_t n;
    cin>>n;
    while (n--){
        unsigned long long int x;
        cin>>x;
        cout<<(x>=15&&x%14>=1&&x%14<=6?"Yes":"No")<<'\n';
    }
    return 0;
}