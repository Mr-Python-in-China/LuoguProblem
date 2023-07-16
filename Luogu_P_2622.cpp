#include<bits/extc++.h>
using namespace std;
namespace pbds=__gnu_pbds;
using ui=unsigned int;
using status=bitset<10>;
#ifdef debug
template<size_t T> ostream& operator<<(ostream& out,bitset<T> const& b){
    for (size_t i=0;i<T;i++) out<<b[i];
    return out;
}
#endif
int main(void){
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    size_t n,m;
    cin>>n>>m;
    vector<vector<char>> a(m,vector<char>(n));
    for (vector<char>& i:a) for (char& j:i){
        short int x;
        cin>>x;
        j=x;
    }
    queue<status> q({(1ULL<<n)-1});
    unordered_set<status> vis;
    vis.insert(q.front());
    size_t ans=0;
    while (!q.empty()){
        for (size_t __cnt=q.size();__cnt>0;__cnt--){
            status const p=q.front();q.pop();
            #ifdef debug
            cout<<'\n'<<p<<':'<<'\n';
            #endif
            if (p==0) return cout<<ans,0;
            for (vector<char> const& i:a){
                status np=p;
                for (size_t j=0;j<i.size();j++){
                    if (i[j]==1&&np[j]) np.reset(j);
                    else if (i[j]==-1&&!np[j]) np.set(j);
                }
                #ifdef debug
                cout<<np<<'\n';
                #endif
                if (!vis.count(np)) vis.insert(np),q.push(np);
            }
        }
        ans++;
    }
    cout<<-1;
    return 0;
}