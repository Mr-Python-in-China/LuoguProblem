#include<bits/extc++.h>
using namespace std;
namespace pbds=__gnu_pbds;
int main(void){
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    size_t n,m,s;double u,v;size_t t;
    cin>>n>>m>>s>>u>>v>>t;
    double p=u/v;
    pbds::priority_queue<int> q;int add_tag=0;
    for (size_t i=0;i<n;i++){
        int x;
        cin>>x;
        q.push(x);
    }
    for (size_t i=1;i<=m;i++){
        int top=q.top()+add_tag;q.pop();
        add_tag+=s;
        q.push(int(p*top)-add_tag),q.push(top-int(p*top)-add_tag);
        if (i%t==0) cout<<top<<' ';
    }
    cout<<'\n';
    for (size_t i=1;!q.empty();i++){
        if (i%t==0) cout<<q.top()+add_tag<<' ';
        q.pop();
    }
    return 0;
}