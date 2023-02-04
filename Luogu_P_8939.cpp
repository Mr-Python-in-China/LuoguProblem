#include<bits/stdc++.h>
using namespace std;
//#define debug
using ui=unsigned int;
int main(void){
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    ui n,q;
    cin>>n>>q;
    map<ui,ui> s;
    while (n--){
        ui x;
        cin>>x;
        s[x]++;
    }
    while (q--){
        char op;ui x;
        cin>>op>>x;
        if (op=='1'){
            if (s.count(x)){
                s[x]--;
                if (!s[x]) s.erase(x);
            }else{
                cout<<"-1\n";
                goto label;
            }
        }else if (op=='2') s[x]++;
        {
            ui ans=s.rbegin()->first-s.begin()->first;
            for (map<ui,ui>::iterator it=s.begin(),jt=next(it);jt!=s.end();it++,jt++)
            #ifdef debug
                cout<<jt->first<<','<<it->first<<jt->first-it->first<<' ',
            #endif
                ans+=jt->first-it->first;
            cout<<ans<<'\n';
        }label:;
    }
    return 0;
}