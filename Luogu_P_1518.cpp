#include<bits/stdc++.h>
using namespace std;
using ui=unsigned int;
struct Position;
struct Direction{
    unsigned char f;
    const static Position F[4];
    Direction(void):f(0){}
    Direction(char _f):f(_f%4){}
    Direction left(void){f=(f+3)%4;return *this;}
    Direction right(void){f=(f+1)%4;return *this;}
    Direction operator<<=(unsigned long long int x){x%=4;while (x--) left();return *this;}
    Direction operator>>=(unsigned long long int x){x%=4;while (x--) right();return *this;}
    Direction operator<<(unsigned long long int x)const{return Direction(*this)<<=x;}
    Direction operator>>(unsigned long long int x)const{return Direction(*this)>>=x;}
    operator unsigned char(void){return f;}
};
struct Position{
    int x,y;
    Position(void):x(0),y(0){}
    Position(int _x,int _y):x(_x),y(_y){}
    Position operator+=(const Position p){x+=p.x,y+=p.y;return *this;}
    Position operator-=(const Position p){x-=p.x,y-=p.y;return *this;}
    friend Position operator+(Position a,const Position b){return a+=b;}
    friend Position operator-(Position a,const Position b){return a-=b;}
    friend bool operator==(const Position a,const Position b){return a.x==b.x&&a.y==b.y;}
    friend bool operator!=(const Position a,const Position b){return a.x !=b.x||a.y!=b.y;}
    void up(void){operator+=(Direction::F[0]);}
    void left(void){operator+=(Direction::F[1]);}
    void down(void){operator+=(Direction::F[2]);}
    void right(void){operator+=(Direction::F[3]);}
    friend ostream& operator<<(ostream& out,const Position p){return out<<'('<<p.x<<','<<p.y<<')';}
    bool in_area(const Position UL,const Position DR){return x>=UL.x&&x<DR.x&&y>=UL.y&&y<DR.y;}
};
const Position Direction::F[4]={{-1,0},{0,-1},{1,0},{0,1}};
template<typename T> class Array2D{
    vector<vector<T>> arr;
    public:
    const size_t x,y;
    Array2D(size_t _x,size_t _y):arr(vector<vector<T>>(_x,vector<T>(_y))),x(_x),y(_y){}
    Array2D(size_t _x,size_t _y,T val):arr(vector<vector<T>>(_x,vector<T>(_y,val))),x(_x),y(_y){}
    T& operator[](Position p){return arr[p.x][p.y];}
    vector<T>& operator[](size_t x){return arr[x];}
};
struct actor{
    Array2D<char>& mp;
    Position pos;
    Direction f;
    actor(Array2D<char>& _mp):mp(_mp),f(0){};
    actor(Array2D<char>& _mp,const Position _pos,const Direction _f):mp(_mp),pos(_pos),f(_f){}
    void forward(void){pos+=f.F[f];}
    void backword(void){pos-=f.F[f];}
    void left(void){f.left();}
    void right(void){f.right();}
    void move(void){(pos+f.F[f]).in_area({0,0},{mp.x,mp.y})&&!mp[pos+f.F[f]]?forward():left();}
    friend bool operator==(const actor a,const actor b){return a.pos==b.pos;}
    friend bool operator!=(const actor a,const actor b){return a.pos!=b.pos;}
    friend ostream& operator<<(ostream& out,const actor a){return out<<a.pos<<','<<int(a.f.f);}
};
int main(void){
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    Array2D<char> mp(10,10);
    actor famer(mp),cow(mp);
    for (int i=0;i<10;i++) for (int j=0;j<10;j++){
        char c;
        cin>>c;
        mp[i][j]=c=='*';
        if (c=='F') famer.pos={i,j};
        if (c=='C') cow.pos={i,j};
    }
    ui i=0;
    while (i<10000000){
        i++;
        famer.move(),cow.move();
        //if (i<100) cout<<i<<':'<<famer<<' '<<cow<<' '<<'\n';
        if (famer==cow){
            cout<<i;
            return 0;
        }
    }
    cout<<'0';
    return 0;
}