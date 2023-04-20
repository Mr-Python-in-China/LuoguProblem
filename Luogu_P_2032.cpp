#include<bits/stdc++.h>
using namespace std;
using ui=unsigned int;
int main(void){
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    size_t n,k;
    cin>>n>>k;
    vector<ui> a(n);
    for (vector<ui>::reference i:a) cin>>i;
    deque<size_t> q({0});
    for (size_t i=1;i<n;i++){
        if (i-q.front()>=k) q.pop_front();
        while (!q.empty()&&a[q.back()]<=a[i]) q.pop_back();
        q.push_back(i);
        // for (auto& i:q) cout<<a[i]<<' ';cout<<'\n';
        if (i>=k-1) cout<<a[q.front()]<<'\n';
    }
    return 0;
}