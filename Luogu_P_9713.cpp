#include<bits/extc++.h>
using namespace std;
namespace pbds=__gnu_pbds;
using ui=unsigned int;
using uli=unsigned long long int;
using li=long long int;
int main(void){
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    uli nowx=0,nowy=0,nowz=0,maxx,maxy,maxz;
    size_t m;
    cin>>maxx>>maxy>>maxz>>m;
    while (m--){
        char op;uli k;
        cin>>op>>k;
        uli& nowobj=(op=='1'?nowx:op=='2'?nowy:nowz);
        nowobj=max(nowobj,k);
        cout<<(maxx-nowx)*(maxy-nowy)*(maxz-nowz)<<'\n';
    }
    return 0;
}