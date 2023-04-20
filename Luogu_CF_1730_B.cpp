#include<bits/stdc++.h>
using namespace std;
using ui=unsigned int;
const double INF=1e9;
int main(void){
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    size_t T;
    cin>>T;
    while (T--){
        size_t n;
        cin>>n;
        vector<pair<int,ui>> people(n);
        double l=0,r=INF;
        for (vector<pair<int,ui>>::reference i:people) cin>>i.first;
        for (vector<pair<int,ui>>::reference i:people) cin>>i.second,l=max<double>(l,i.second);
        double ans;
        while (r-l>1e-3){
            double mid=(l+r)/2;
            pair<double,double> pr={-INF,INF};
            for (pair<int,ui>& i:people)
                pr.first =max(pr.first, i.first-(mid-i.second)),
                pr.second=min(pr.second,i.first+(mid-i.second));
            ans=pr.first;
            (pr.first<=pr.second?r:l)=mid;
        }
        int ansx10=int(ans*10+0.5);
        cout<<ansx10/10;
        if (ansx10%10) cout<<'.'<<ansx10%10;
        cout<<'\n';
    }
    return 0;
}