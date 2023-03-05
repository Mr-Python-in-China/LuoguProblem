#include<bits/stdc++.h>
using namespace std;
using ui=unsigned int;
using uli=unsigned long int;
int main(void){
    //ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    ui T;
    cin>>T;
    while (T--){
        uli r,year,month,day;bool ren=false;
        cin>>r;
        if (r<1721423){
            year=r/1461*4;
            r%=1461;
            if (r>=1096) year+=3,r-=1096;
            else if (r>=731) year+=2,r-=731;
            else if (r>=365) year+=1,r-=365;
            else ren=true;
            const array<char,12> dofm={31,char(28+ren),31,30,31,30,31,31,30,31,30,31};
            for (month=0;r>=dofm[month];month++) 
                r-=dofm[month];
            month++;
            year=4713-year;
            day=r+1;
            cout<<day<<' '<<month<<' '<<year<<" BC"<<'\n';
        }else if (r<=2299159){
            r-=1721423;
            year=1+r/1461*4;
            r%=1461;
            if (r>=1095) ren=true,year+=3,r-=1096;
            else if (r>=730) year+=2,r-=731;
            else if (r>=365) year+=1,r-=365;
            const array<char,12> dofm={31,char(28+ren),31,30,31,30,31,31,30,31,30,31};
            for (month=0;r>=dofm[month];month++) 
                r-=dofm[month];
            month++;
            day=r+1;
            cout<<day<<' '<<month<<' '<<year<<'\n';
        }else{
            r-=1721401+24;
            year=1+r/146097*400;
            r%=146097;
            if (r>145731){
                year+=399,ren=true,r-=145731;
                const array<char,12> dofm={31,char(28+ren),31,30,31,30,31,31,30,31,30,31};
                for (month=0;r>=dofm[month];month++) 
                    r-=dofm[month];
                month++;
                day=r+1;
                cout<<day<<' '<<month<<' '<<year<<'\n';
                continue;
            }
            else if (r>109572) year+=300,r-=109572;
            else if (r>73048) year+=200,r-=73048;
            else if (r>36524) year+=100,r-=36524;
            year+=r/1461*4;
            r%=1461;
            if (r>=1095) ren=true,year+=3,r-=1096;
            else if (r>=730) year+=2,r-=731;
            else if (r>=365) year+=1,r-=365;
            const array<char,12> dofm={31,char(28+ren),31,30,31,30,31,31,30,31,30,31};
            for (month=0;r>=dofm[month];month++) 
                r-=dofm[month];
            month++;
            day=r+1;
            cout<<day<<' '<<month<<' '<<year<<'\n';
        }
    }
    return 0;
}