#include<bits/stdc++.h>
using namespace std;
size_t mpsort(const vector<int>::iterator& l,const vector<int>::iterator& r){
    if (r-l<=1) return 0;
    size_t res=0;
    vector<int>::iterator mid=l+((r-l)>>1);
    res+=mpsort(l,mid)+mpsort(mid,r);
    {
        vector<int> tmp(r-l);
        vector<int>::iterator it=l,jt=mid,kt=tmp.begin();
        while (it!=mid&&jt!=r)
            if (*it<=*jt) *(kt++)=*(it++);
            else res+=(jt-l)-(kt-tmp.begin()),*(kt++)=*(jt++);
        while (it!=mid) *(kt++)=*(it++);
        while (jt!=r) *(kt++)=*(jt++);
        copy(tmp.begin(),tmp.end(),l);
    }
    return res;
}
int main(void){
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    size_t n;
    cin>>n;
    vector<int> a(n);
    for (int& i:a) cin>>i;
    cout<<mpsort(a.begin(),a.end());
    return 0;
}