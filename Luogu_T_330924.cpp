#include<bits/stdc++.h>
using namespace std;
using ui=unsigned int;
int main(void){
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    size_t n,ans=0;
    cin>>n;
    while (n--){
        size_t m;
        cin>>m;
        while (m--){
            string s;
            cin>>s;
            for (char& i:s){
                i=(isupper(i)?i+32:i);
                ans+=i=='a'||i=='e'||i=='i'||i=='o'||i=='u';
            }
        }
    }
    cout<<ans;
    return 0;
}