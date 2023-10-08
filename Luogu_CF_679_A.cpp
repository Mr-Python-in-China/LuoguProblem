#include<bits/extc++.h>
using namespace std;
namespace pbds=__gnu_pbds;
using ui=unsigned int;
using uli=unsigned long long int;
using li=long long int;
int main(void){
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    size_t cnt=0;ui x=-1;
    for (ui i:{2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53}){
        cout<<i<<endl;
        string s;
        cin>>s;
        if (s=="yes") ++cnt,x=i;
    }
    if (cnt>1) cout<<"composite";
    else if (x==-1) cout<<"prime";
    else if (x*x>100) cout<<"prime";
    else{
        cout<<x*x<<endl;
        string s;
        cin>>s;
        cout<<(s=="yes"?"composite":"prime");
    }
    return 0;
}