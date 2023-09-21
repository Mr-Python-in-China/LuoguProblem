#include<bits/extc++.h>
using namespace std;
namespace pbds=__gnu_pbds;
using ui=unsigned int;
int main(void){
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    set<ui> find_unique;
    for (size_t i=0;i<=2e6;i++) find_unique.insert(i);
    size_t n;
	cin>>n;
	for (size_t i=0;i<n;++i) {
		ui x;
        cin>>x;
		set<ui>::iterator it=find_unique.lower_bound(x);
		cout<<*it<<' ';
		find_unique.erase(*it);
	}
    return 0;
}