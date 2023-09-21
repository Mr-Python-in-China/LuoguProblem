#include<bits/extc++.h>
using namespace std;
namespace pbds=__gnu_pbds;
using ui=unsigned int;
class BasePig;
struct Player{
    struct node{
        BasePig* prev,*next;
        node(BasePig* p,BasePig* n):prev(p),next(n){}
    };
    unordered_map<BasePig*,node> lst;
    BasePig* head;
    Player(void):lst(),head(nullptr){};
    void push_back(BasePig* p){
        if (head){
            lst.insert({p,node(lst[head].prev,head)});
            lst[lst[head].prev].next=p;
            lst[head].prev=p;
        }else lst.insert({head=p,node(p,p)});
    }
    bool remove(BasePig* p){
        if (!lst.count(p)) return false;
        if (head==p) head=lst[p].next;
        lst[lst[p].prev].next=lst[p].next;
        lst[lst[p].next].prev=lst[p].prev;
        lst.erase(p);
        return true;
    }
    BasePig* getnext(BasePig* nw){
        if (!lst.count(nw)) return nullptr;
        else return lst[nw].next;
    }
} player;

enum class CARD:unsigned char{
    None,

    P, // 桃
    K, // 杀
    D, // 闪

    F, // 决斗
    N, // 南猪入侵
    W, // 万箭齐发
    J, // 无懈可击

    Z, // 猪哥连弩
};
enum class CARDTYPE:unsigned char{
    Null,Classic,Idea,Equip,
};
CARDTYPE const cardname[]={
    CARDTYPE::Null,
    CARDTYPE::Classic,
    CARDTYPE::Classic,
    CARDTYPE::Classic,
    CARDTYPE::Idea,
    CARDTYPE::Idea,
    CARDTYPE::Idea,
    CARDTYPE::Idea,
    CARDTYPE::Equip
};
// 桃
void Puse(BasePig& p){
    if (p.bld<p.upper_bld) p.bld++;
}
// 杀
void Kuse(BasePig& from){
    BasePig& to=*player.getnext(&from);
    if (!to.) to.hurted(1,from);
}

struct BasePig
{
    char bld; // 血量
    char const upper_bld; // 血量上限
    unordered_multiset<CARD> cards; // 手牌
    CARD equip;
    BasePig(BasePig const &) = delete;
    friend bool operator==(BasePig const &a, BasePig const &b) { return &a == &b; }
    virtual void hurted(char lessed,BasePig const &from){
        bld-=lessed;
        while (bld<=0&&removeCard(CARD::P)) ++bld;
        if (hurted) dead();
    }
    virtual void dead(void){
        
    }
    /// @brief 从手牌中删除一张卡牌
    /// @param c 要删除的卡牌
    /// @return 是否成功删除
    virtual bool removeCard(CARD c){
        unordered_multiset<CARD>::iterator it=cards.find(c);
        if (it!=cards.end()){
            cards.erase(it);
            return true;
        }else return false;
    }


};
// 主猪
struct MP:BasePig{

};
// 忠猪
struct ZP:BasePig{

};
// 反猪
struct FP:BasePig{
    
};

/// @brief 判断获胜状态。若游戏已经结束，则函数会直接结算、输出、结束进程。否则，正常退出。
void gameover(void){
    bool mp=false,fp=false;
    BasePig* it=player.head;
    do{
       if (!mp&&dynamic_cast<MP*>(it)) mp=true;
       else if (!fp&&dynamic_cast<FP*>(it)) fp=true;
    }while ((it=player.getnext(it))!=player.head);
    
}

class CardStack{
    stack<shared_ptr<CARD>> stk;

};
int main(void){
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    
    return 114514;
}
