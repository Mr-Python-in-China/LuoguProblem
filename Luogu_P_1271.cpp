#include<bits/stdc++.h>
using namespace std;
using ui=unsigned int;
int main(void){
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    ui n, m;
    cin >> n >> m;
    vector<ui> btt(n+1);
    for (ui i = 0; i < m;i++){
        ui x;
        cin >> x;
        btt[x]++;
    }
    for (ui i = 0; i <= n;i++)
        for (ui j = 0; j < btt[i];j++)
            cout << i << ' ';
    return 0;
}