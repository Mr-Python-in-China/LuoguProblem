#include<bits/stdc++.h>
using namespace std;
using usi=unsigned short int;
using uc=unsigned char;
namespace pig{
    enum class pig_type{mp,zp,fp};
    struct BasePig{ //猪的基类
        usi hp;
        static const usi MAX_HP=4;
        bool die;
        Weapon wp;
        unordered_multiset<cards> card;
        BasePig(void):hp(4),die(false){};
        bool my_turn(void){ //该猪的回合
            while (hp!=MAX_HP&&card.count(cards::p)) use_card_p();
            while (card.count(cards::n)) use_card_n();
        }
        void use_card_p(void){hp++,card.erase(cards::p);} //使用【桃】
        void use_card_n(void){ //使用【南猪入侵】
            
        }
        void use_card_w(void){ //使用【万箭齐发】
            
        }
    };
    struct mp:public BasePig{ //主猪

    };
    struct zp:public BasePig{ //忠猪

    };
    struct fp:public BasePig{ //返猪

    };
    vector<BasePig*> pigs;
};
enum class cards:uc{
    p=1, //桃
    k,   //杀
    d,   //闪
    f,   //决斗
    n,   //南猪入侵
    w,   //万箭齐发
    j,   //无懈可击
    z    //猪哥连弩
};
enum class Weapon:uc{
    None,                       //无
    z=static_cast<uc>(cards::z) //猪哥连弩
};
int main(void){
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    
    return 0;
}