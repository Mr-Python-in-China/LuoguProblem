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
    list<pair<bool,list<size_t>>> blk;
    {
        bool lst;
        cin>>lst;
        blk.push_back({lst,{0}});
        for (size_t i=1;i<n;i++){
            bool now;
            cin>>now;
            if (lst!=now) blk.push_back({lst=now,{}});
            blk.back().second.push_back(i);
        }
    }
    while (!blk.empty()){
        for (list<pair<bool,list<size_t>>>::iterator it=blk.begin();it!=blk.end();){
            cout<<it->second.front()+1<<' ';
            it->second.pop_front();
            if (it->second.empty()) it=blk.erase(it);
            else ++it;
        }
        for (list<pair<bool,list<size_t>>>::iterator it=blk.begin();it!=blk.end();++it){
            while (next(it)!=blk.end()&&next(it)->first==it->first)
                it->second.splice(it->second.end(),next(it)->second),
                blk.erase(next(it));
        }
        cout.put('\n');
    }
   return 0;
}