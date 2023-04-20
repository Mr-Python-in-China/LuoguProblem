#include<bits/stdc++.h>
using namespace std;
using uli=unsigned long long int;
using li=long long int;
struct pos{
    li x,y;
};
struct rect{
    pos ul,dr;
};
int main(void){
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    size_t n;
    cin>>n;
    vector<li> dstx,dsty;
    vector<rect> rects(n);
    for (rect& i:rects){
        cin>>i.ul.x>>i.ul.y>>i.dr.x>>i.dr.y;
        if (i.ul.x>i.dr.x) swap(i.ul.x,i.dr.x);
        if (i.ul.y>i.dr.y) swap(i.ul.y,i.dr.y);
        dstx.push_back(i.ul.x),dstx.push_back(i.dr.x),
        dsty.push_back(i.ul.y),dsty.push_back(i.dr.y);
    }

    // for (const rect& i:rects) cout<<i.ul.x<<','<<i.ul.y<<' '<<i.dr.x<<','<<i.dr.y<<'\n';
    // cout<<'\n';

    sort(dstx.begin(),dstx.end()),sort(dsty.begin(),dsty.end());
    size_t dstx_size=dstx.size(),dsty_size=dsty.size();
    for (rect& i:rects)
        i.ul.x=lower_bound(dstx.cbegin(),dstx.cend(),i.ul.x)-dstx.cbegin(),
        i.dr.x=lower_bound(dstx.cbegin(),dstx.cend(),i.dr.x)-dstx.cbegin(),
        i.ul.y=lower_bound(dsty.cbegin(),dsty.cend(),i.ul.y)-dsty.cbegin(),
        i.dr.y=lower_bound(dsty.cbegin(),dsty.cend(),i.dr.y)-dsty.cbegin();

    // for (const rect& i:rects) cout<<i.ul.x<<','<<i.ul.y<<' '<<i.dr.x<<','<<i.dr.y<<'\n';
    // cout<<'\n';

    vector<vector<li>> dif_cnt(dstx_size+1,vector<li>(dsty_size+1));
    for (const rect& i:rects)
        ++dif_cnt[i.ul.x][i.ul.y],
        --dif_cnt[i.ul.x][i.dr.y+1],
        --dif_cnt[i.dr.x+1][i.ul.y],
        ++dif_cnt[i.dr.x+1][i.dr.y+1];
    vector<vector<li>> cnt(dstx_size,vector<li>(dsty_size));
    cnt[0][0]=dif_cnt[0][0];
    for (size_t i=1;i<dstx_size;i++) cnt[i][0]=dif_cnt[i][0]+cnt[i-1][0];
    for (size_t i=1;i<dsty_size;i++) cnt[0][i]=dif_cnt[0][i]+cnt[0][i-1];
    for (size_t i=1;i<dstx_size;i++) for (size_t j=1;j<dsty_size;j++)
        cnt[i][j]=cnt[i][j-1]+cnt[i-1][j]-cnt[i-1][j-1]+dif_cnt[i][j];
    uli ans=0;
    for (size_t i=1;i<dstx_size;i++) for (size_t j=1;j<dsty_size;j++)
        if (cnt[i][j]&&cnt[i][j-1]&&cnt[i-1][j]&&cnt[i-1][j-1])
            cout<<i<<' '<<j<<'\n',ans+=(dstx[i]-dstx[i-1])*(dsty[j]-dsty[j-1]);
    cout<<ans;
    return 0;
}