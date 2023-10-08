#include<bits/extc++.h>
using namespace std;
namespace pbds=__gnu_pbds;
using ui=unsigned int;
using uli=unsigned long long int;
using li=long long int;
struct plane{
    ui arrive,leave;
    bool type;
    struct cmp_arrive_less{bool operator()(plane const& a,plane const& b) const{return a.arrive<b.arrive;}};
    struct cmp_leave_greater{bool operator()(plane const& a,plane const& b) const{return a.leave>b.leave;}};
    friend bool operator==(plane const& a,plane const& b){return a.arrive==b.arrive;}
    struct hash{size_t operator()(plane const& a) const{return a.arrive;}};
};
int main(void){
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    size_t n,m1,m2;
    cin>>n>>m1>>m2;
    vector<plane> a(m1+m2);
    for (size_t i=0;i<m1;++i) cin>>a[i].arrive>>a[i].leave,a[i].type=false;
    for (size_t i=m1;i<m1+m2;++i) cin>>a[i].arrive>>a[i].leave,a[i].type=true;
    sort(a.begin(),a.end(),plane::cmp_arrive_less());
    pbds::priority_queue<plane,plane::cmp_leave_greater> q[2];
    unordered_map<plane,size_t,plane::hash> id;    // 飞机所在的机位编号
    vector<size_t> count;    // 该机位停靠的飞机数量
    pbds::priority_queue<size_t,greater<size_t>> pool[2];
    for (plane const& i:a){
        while (!q[0].empty()&&q[0].top().leave<i.arrive)
            pool[0].push(id[q[0].top()]),q[0].pop();
        while (!q[1].empty()&&q[1].top().leave<i.arrive)
            pool[1].push(id[q[1].top()]),q[1].pop();
        if (pool[i.type].empty()) pool[i.type].push(count.size()),count.push_back(0);
        id[i]=pool[i.type].top();
        ++count[pool[i.type].top()];
        q[i.type].push(i);
        pool[i.type].pop();
    }
    vector<size_t> ds[2];
    while (!q[0].empty())
        pool[0].push(id[q[0].top()]),q[0].pop();
    while (!q[1].empty())
        pool[1].push(id[q[1].top()]),q[1].pop();
    while (!pool[0].empty()) ds[0].push_back(pool[0].top()),pool[0].pop();
    while (!pool[1].empty()) ds[1].push_back(pool[1].top()),pool[1].pop();
    sort(ds[0].begin(),ds[0].end()),sort(ds[1].begin(),ds[1].end());
    uli sum=0,ans=0;
    if (ds[0].size()>n) ds[0].resize(n);
    if (ds[1].size()>n) ds[1].resize(n);
    for (size_t i=0;i<ds[1].size();++i) sum+=count[ds[1].at(i)];
    for (size_t i=0;i<n-ds[1].size()&&i<ds[0].size();++i) sum+=count[ds[0].at(i)];
    ans=max(ans,sum);
    for (size_t i=n-ds[1].size(),j=ds[1].size()-1;i<ds[0].size()&&j<ds[1].size();++i,--j)
        ans=max((sum-=count[ds[1].at(j)])+=count[ds[0].at(i)],ans);
    cout<<ans;
    return 0;
}