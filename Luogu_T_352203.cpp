#include<bits/extc++.h>
using namespace std;
namespace pbds=__gnu_pbds;
using ui=unsigned int;
int main(void){
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    size_t n;
    cin>>n;
    vector<pair<int,int>> a(n);
    for (pair<int,int>& i:a) cin>>i.first>>i.second;
    sort(a.begin(),a.end());
    int l=a.front().first,r=a.back().first+1;
    while (l<r){
        int mid=(l+r)>>1;
        bool flag=false;
        int s=a.front().first,t=a.back().first;
        for (vector<pair<int,int>>::const_iterator i=a.begin();i<a.end();i++){
            vector<pair<int,int>>::const_iterator j=i;
            int k=-1;
            while (j<a.end()&&j->first<=s)
                k=max(j->first+j->second+mid,k),j++;
            if (k<s) goto out;
            if (k>=t) break;
            s=k,i=j-1;
        }
        flag=true;
        out:;
        if (flag) r=mid;
        else l=mid+1;
    }
    cout<<l;
    return 0;
}