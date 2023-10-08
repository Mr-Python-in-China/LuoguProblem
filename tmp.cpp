#include<bits/extc++.h>
using namespace std;
namespace pbds=__gnu_pbds;
using ui=unsigned int;
using uli=unsigned long long int;
using li=long long int;
int main(void){
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    while (true){
        cout<<">>> "<<flush;
        string s;
        getline(cin,s);
        vector<int> a({0});
        for (char const i:s)
            if (isdigit(i)) (a.back()*=10)+=i-'0';
            else a.push_back(0);
        sort(a.rbegin(),a.rend());
        while (!a.empty()&&!a.back()) a.pop_back();
        if (a.empty()){cout<<"\n";continue;}
        int ans=0;
        for (size_t i=0;i<a.size();++i) ans+=(i&1?-1:1)*a[i];
        cout<<ans<<'\n';
    }
    return 0;
}