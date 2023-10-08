#include<bits/extc++.h>
using namespace std;
namespace pbds=__gnu_pbds;
using ui=unsigned int;
using uli=unsigned long long int;
using li=long long int;
using graph=vector<vector<size_t>>;
int main(void){
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    size_t n;
    cin>>n;
    vector<bool> type(n);
    vector<uli> ans(n);
    for (vector<bool>::reference i:type){
        char c;
        cin>>c;
        i=c==')';
    }
    vector<size_t> fa(n,-1),unpair(n),lst(n,-1),line(n);
    for (size_t i=1;i<n;++i) cin>>fa[i],--fa[i];
    uli rs=0;
    for (size_t i=0;i<n;++i){
		if (~fa[i]) ans[i]=ans[fa[i]],lst[i]=lst[fa[i]];
		if (!type[i]) lst[i]=i;
		else if (type[i]&&~lst[i])
			line[i]=(~fa[lst[i]]?line[fa[lst[i]]]:0)+1,
			lst[i]=(~fa[lst[i]]?lst[fa[lst[i]]]:-1),
			ans[i]+=line[i];
        rs^=(i+1)*ans[i];
    }
    cout<<rs;
    return 0;
}