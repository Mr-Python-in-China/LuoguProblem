#include<bits/stdc++.h>
using namespace std;
using li=long long int;
struct fangcheng{
    li a,b,c;
    inline friend istream& operator>>(istream& in,fangcheng& s){return in>>s.a>>s.b>>s.c;}
    inline bool check(li x) const{return x*x*x+a*x*x+b*x+c!=0;}
};
int main(void){
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    size_t n;
    cin>>n;
    vector<fangcheng> a(n);
    for (fangcheng& i:a) cin>>i;
    unsigned int x;
    bool flag;
    srand(time(nullptr));
    do{
        flag=false;
        x=(rand())%1000000;
        for (const fangcheng& i:a) if (!i.check(x)){
                flag=true;
                break;
            }
    }while (flag);
    cout<<x;
    return 0;
}