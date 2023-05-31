#include<bits/stdc++.h>
using namespace std;
using ui=unsigned int;
int main(void){
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    size_t m,n,k,l,d;
    cin>>m>>n>>k>>l>>d;
    vector<pair<ui,ui>> x(--m),y(--n);
    for (size_t i=0;i<m;i++) x[i].second=i;
    for (size_t i=0;i<n;i++) y[i].second=i;
    while (d--){
        size_t x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        --x1,--y1,--x2,--y2;
             if (x1>x2) x.at(x2).first++;
        else if (x2>x1) x.at(x1).first++;
        else if (y1>y2) y.at(y2).first++;
        else if (y2>y1) y.at(y1).first++;
    }
    sort(x.begin(),x.end(),greater<pair<ui,ui>>()),
    sort(y.begin(),y.end(),greater<pair<ui,ui>>());
    sort(x.begin(),x.begin()+k,[](const pair<ui,ui>& a,const pair<ui,ui>& b){return a.second<b.second;}),
    sort(y.begin(),y.begin()+l,[](const pair<ui,ui>& a,const pair<ui,ui>& b){return a.second<b.second;});
    for (size_t i=0;i<k;i++) cout<<x[i].second+1<<' ';
    cout.put('\n');
    for (size_t i=0;i<l;i++) cout<<y[i].second+1<<' ';
    return 0;
}