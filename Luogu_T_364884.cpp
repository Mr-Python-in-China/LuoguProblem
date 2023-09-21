#include<bits/extc++.h>
using namespace std;
namespace pbds=__gnu_pbds;
using ui=unsigned int;
bool f(size_t ax,size_t ay,size_t bx,size_t by){
    return (ax+2==bx&&ay+1==by)||(ax-2==bx&&ay+1==by)||(ax+2==bx&&ay-1==by)||(ax-2==bx&&ay-1==by)||(ax+1==bx&&ay+2==by)||(ax-1==bx&&ay+2==by)||(ax+1==bx&&ay-2==by)||(ax-1==bx&&ay-2==by);
}
int main(void){
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    size_t sx,sy,cx,cy,mx,my;
    cin>>sx>>sy>>cx>>cy>>mx>>my;
    cout<<((f(sx+2,sy+1,cx,cy)&&f(sx+2,sy+1,mx,my))||(f(sx-2,sy+1,cx,cy)&&f(sx-2,sy+1,mx,my))||(f(sx+2,sy-1,cx,cy)&&f(sx+2,sy-1,mx,my))||(f(sx-2,sy-1,cx,cy)&&f(sx-2,sy-1,mx,my))||
            (f(sx+1,sy+2,cx,cy)&&f(sx+1,sy+2,mx,my))||(f(sx-1,sy+2,cx,cy)&&f(sx-1,sy+2,mx,my))||(f(sx+1,sy-2,cx,cy)&&f(sx+1,sy-2,mx,my))||(f(sx-1,sy-2,cx,cy)&&f(sx-1,sy-2,mx,my))
            ?"Yes":"No");

    return 0;
}