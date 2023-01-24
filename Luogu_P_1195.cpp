#include<bits/stdc++.h>
using namespace std;
using ui=unsigned int;
struct edge{
    ui u,v,w;
    friend bool operator<(const edge& a,const edge& b){return a.w<b.w;}
};
inline ui find(vector<ui>& fa,ui x){return fa[x]==x?x:fa[x]=find(fa,fa[x]);}
inline void link(vector<ui>& fa,ui x,ui y){fa[find(fa,x)]=find(fa,y);}
int main(void){
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    ui n,m,k;
    cin>>n>>m>>k;
    vector<edge> e(m);vector<ui> fa(n);
    for (ui i=0;i<n;i++) fa[i]=i;
    for (vector<edge>::reference i:e) cin>>i.u>>i.v>>i.w,i.u--,i.v--;
    sort(e.begin(),e.end());
    ui ans=0,tot=0;
    for (vector<edge>::reference i:e) if (find(fa,i.u)!=find(fa,i.v)){
        link(fa,i.u,i.v),ans+=i.w,tot++;
        if (tot>=n-k){
            cout<<ans;
            return 0;
        }
    }
    cout<<"No Answer";
    return 0;
}