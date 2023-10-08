#include<bits/extc++.h>
using namespace std;
namespace pbds=__gnu_pbds;
using ui=unsigned int;
using uli=unsigned long long int;
using li=long long int;
int main(void){
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    size_t n;
    cin>>n;
    vector<vector<size_t>> tree(n);
    char flag=1;  // 1：菊花图；2：无子树数量为1；3：有子树数量为1。
    for (size_t i=1;i<n;++i){
        size_t fa;
        cin>>fa;
        tree[--fa].push_back(i);
        if (fa!=0) flag=2;
    }
    if (flag!=0) for (vector<size_t> const& i:tree)
            if (i.size()==1) flag=3;
    vector<char> colors(n);
    switch (flag){
    case 1:{
        for (size_t i=1;i<n;++i) colors[i]=1;
        break;
    }case 2:{
        char ncolor=1;
        queue<size_t> q({0});
        while (!q.empty()){
            for (size_t i=q.size();i;--i){
                size_t p=q.front();q.pop();
                for (size_t i:tree[p]) colors[i]=ncolor,q.push(i);
            }
            if (++ncolor>2) ncolor=1;
        }
        break;
    }case 3:{
        char ncolor=1;
        queue<size_t> q({0});
        while (!q.empty()){
            for (size_t i=q.size();i;--i){
                size_t p=q.front();q.pop();
                for (size_t i:tree[p]) colors[i]=ncolor,q.push(i);
            }
            if (++ncolor>3) ncolor=1;
        }
        break;
    }}
    unordered_set<uli> tmp;
    for (size_t i=1;i<n;++i) tmp.insert(colors[i]);
    cout<<size_t(flag=tmp.size())<<'\n';
    for (size_t i=1;i<n;++i) cout<<ui(colors[i])<<' ';
    cout<<endl;
    short int status;
    while (cin>>status&&status==0){
        vector<size_t> e(flag);
        for (size_t& i:e) cin>>i;
        switch (flag){
        case 1:
            cout<<'1';
            break;
        case 2:
            cout<<(e[0]==1?1:2);
            break;
        case 3:{
            if (e[0]+e[1]+e[2]==1){
                cout<<(e[0]==1?1:e[1]==1?2:3);
                break;
            }
            size_t n1=(e[0]?0:e[1]?1:2),n2=(e[0]&&n1!=0?0:e[1]&&n1!=1?1:2);
            if (n1==0&&n2==1) cout<<1;
            if (n1==1&&n2==2) cout<<2;
            if (n1==2&&n2==0) cout<<3;
            if (n2==0&&n1==1) cout<<1;
            if (n2==1&&n1==2) cout<<2;
            if (n2==2&&n1==0) cout<<3;
        }
        }
        cout<<endl;
    }
    return 0;
}