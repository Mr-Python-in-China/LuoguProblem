#include<bits/stdc++.h>
using namespace std;
using ui=unsigned int;
int main(void){
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    string s,t;
    cin>>s>>t;
    vector<size_t> nxt(t.size());
    for (size_t i=1,j=-1;i<t.size();i++){
        while (~j&&t[i]!=t[j+1]) j=nxt[j]-1;
        if (t[i]==t[j+1]) j++;
        nxt[i]=j+1;
    }
    for (size_t i=0,j=-1;i<s.size();i++){
        while (~j&&s[i]!=t[j+1]) j=nxt[j]-1;
        if (s[i]==t[j+1]) j++;
        if (!t[j+1]) 
            cout<<i-j+1<<'\n',j=nxt[j]-1;
    }
    for (vector<size_t>::const_reference i:nxt)
        cout<<i<<' ';
    return 0;
}
