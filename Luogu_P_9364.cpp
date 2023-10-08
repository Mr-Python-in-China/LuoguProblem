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
    vector<string> s(n);
    for (string& i:s) cin>>i;
    sort(s.begin(),s.end(),[](string const& a,string const& b){return a.size()<b.size();});
    unordered_set<string> perfect_word({""});
    for (string const& i:s)
        if (perfect_word.count(i.substr(1))&&perfect_word.count(i.substr(0,i.size()-1)))
            perfect_word.insert(i);
    size_t ans=0;
    for (string const& i:perfect_word) ans=max(i.size(),ans);
    cout<<ans;
    return 0;
}