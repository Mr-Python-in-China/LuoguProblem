#include<bits/extc++.h>
using namespace std;
namespace pbds=__gnu_pbds;
using ui=unsigned int;
using uli=unsigned long long int;
using li=long long int;
int main(void){
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    uli n,m,p,q;
    cin>>n>>m>>p>>q;
    cout<<(p*m+q<n*m?"Program ends with return value 0.":"Segmentation fault.");
    return 0;
}