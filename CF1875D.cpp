#include<bits/extc++.h>
using namespace std;
namespace pbds=__gnu_pbds;
using ui=unsigned int;
using uli=unsigned long long int;
using li=long long int;
int main(void){
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    size_t T;
    cin>>T;
    while (T--){
        size_t n;
        cin>>n;
        unordered_map<ui,size_t> num;
        for (size_t i=0;i<n;++i){
            ui x;
            cin>>x;
            ++num[x];
        }
        ui mex=0;
        for (;!num.count(mex);++mex);
        uli ans=0;
        for (ui i=0;i<mex;++i)
    }
    return 0;
}