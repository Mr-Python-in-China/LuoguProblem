#include<bits/stdc++.h>
using namespace std;
using ui=unsigned int;
int main(void){
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    int taskId;
    cin >> taskId;
    if (taskId == 1) {
        cout << int(2e9)<<' '<<int(2e9);
    } else if (taskId == 2) {
        for (size_t i=0;i<1e6;i++) cout.put('a');
    } else if (taskId == 3) {
        cout << "100\n";
        for (size_t i=0;i<100;i++) cout<<"114514 "<<'\n';
    } else { // 这个 else 不会被执行
        cout << "OvoOvoovOovO";
    }
    cout<<flush;
    return 0;
}