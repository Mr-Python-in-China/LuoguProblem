#include<bits/stdc++.h>
using namespace std;
using ui=unsigned int;
int main(void){
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    size_t n;
    cin>>n;
    unsigned long long int ans=0;
    vector<pair<int,int>> a(n);
    for (vector<pair<int,int>>::iterator it=a.begin();it<a.end();it++){
        cin>>it->first>>it->second;
        for (vector<pair<int,int>>::iterator jt=a.begin();jt<it;jt++)
            ans+=max(it->first,jt->first)*abs(it->second-jt->second);
    }
    cout<<ans;
    return 0;
}