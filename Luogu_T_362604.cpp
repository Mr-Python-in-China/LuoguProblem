#include<bits/extc++.h>
using namespace std;
namespace pbds=__gnu_pbds;
using ui=unsigned int;
int main(void){
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    size_t n;
    cin>>n;
    multiset<pair<int,int>> m;
    while (n--){
        char c;int k,b;
        cin>>c>>k>>b;
        switch (c){
        case '1':
            m.insert({k,b});
            break;
        case '2':
            cout<<m.size()-distance(m.lower_bound({k,0x80000000}),m.upper_bound({k,0x7fffffff}))<<'\n';
        #ifdef debug
            cout<<flush;
        #endif
            break;
        case '3':
            m.erase(m.begin(),m.lower_bound({k,0x80000000})),m.erase(m.upper_bound({k,0x7fffffff}),m.end());
            m.erase({k,b});
        }
    }
    return 0;
}