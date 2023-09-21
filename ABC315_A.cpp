#include<bits/extc++.h>
using namespace std;
namespace pbds=__gnu_pbds;
using ui=unsigned int;
int main(void){
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    char c;
    while (cin>>c)
        if (c!='a'&&c!='e'&&c!='i'&&c!='o'&&c!='u') cout.put(c);
    return 0;
}