#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
enum class card : unsigned char { UNDEFINED, P, K, D, F, N, W, J, Z };
struct judger;
struct Pig {
  judger& jdr;
  int hp;
  unordered_multiset<card> cards;
  card wear;
  Pig(judger&);
  Pig(Pig const&) = delete;
  virtual void myturn(void);
  virtual void hurt(int, Pig*, card way);
  virtual void die(Pig*);

  void getK(Pig*);
  void getF(Pig*);
  void getN(Pig*);
  void getW(Pig*);
  bool useP(void);
  void useK(Pig*);
  void useD(Pig*);
  void useF(Pig*);
  void useN(Pig*);
  void useW(Pig*);
  void useJ(Pig*);
  bool throw_card(card);
};
struct MP: Pig {
  void clear_cards(void) {}
};
struct ZP: Pig {};
struct FP: Pig {
  bool jumped;
  FP(judger&);
};
struct judger {
  judger(vector<Pig*> const& p, vector<card> const& c);
  unsigned char mainloop(void);
  void pigdie(Pig* pig);
  struct {
    Pig* front;
    struct node {
      Pig *prev, *next;
    };
    unordered_map<Pig*, node> data;
    void erase(Pig* p) {
      dynamic_cast<MP*>(p)   ? --MPcount
      : dynamic_cast<ZP*>(p) ? --ZPcount
      : dynamic_cast<FP*>(p) ? --FPcount
                             : throw;
      data[data[p].prev].next = data[p].next,
      data[data[p].next].prev = data[p].prev;
      data.erase(p);
    }
    size_t MPcount, ZPcount, FPcount;
  } pigs;

  struct card_stack {
    card last;
    stack<card> stk;
    card_stack(vector<card> const& c): last(c.back()) {
      for_each(c.crbegin(), c.crend(), [&](card obj) { stk.push(obj); });
    }
    card get(void) { return stk.empty() ? last : stk.top(); }
  };

  unsigned char winner;  // 2:FP; 1:MP;
};

Pig::Pig(judger& _jdr): jdr(_jdr), hp(4) {}
void Pig::myturn(void) {
  while (hp <= 4)
    if (!useP()) break;
}
void Pig::hurt(int x, Pig* from, card way) {
  hp -= x;
  while (hp <= 0)
    if (!useP()) break;
  if (x <= 0) die(from);
}
void Pig::getF(Pig* from) {
  if (!throw_card(card::K)) hurt(1, from, card::F);
  from->getF(this);
}
void Pig::die(Pig* killer) { jdr.pigdie(this); }
void Pig::getK(Pig* from) {
  if (!throw_card(card::D)) hurt(1, from, card::K);
}
void Pig::getN(Pig* from) {
  if (!throw_card(card::K)) hurt(1, from, card::N);
}
void Pig::getW(Pig* from) {
  if (!throw_card(card::D)) hurt(1, from, card::W);
}
bool Pig::useP(void) { return throw_card(card::P); }
bool Pig::throw_card(card c) {
  auto it = cards.find(c);
  if (it == cards.end()) return false;
  cards.erase(it);
  return true;
}

void MP::clear_cards(void) { cards.clear(); }

FP::FP(judger& j): jumped(false), Pig(j) {}

judger::judger(vector<Pig*> const& p, vector<card> const& c): winner(0) {
  for (vector<Pig*>::const_iterator it = p.cbegin(), jt = next(it);
       jt != p.cend(); ++it, jt)
    pigs.data[*it].next = *jt, pigs.data[*jt].prev = *it;
  pigs.data[p.back()].next = p.front(), pigs.data[p.front()].prev = p.back();
  pigs.front = p.front();
}
unsigned char judger::mainloop(void) {
  for (Pig* i = pigs.front; !winner; i = pigs.data[i].next) i->myturn();
  return winner;
}
void judger::pigdie(Pig* pig) {
  pigs.erase(pig);
  if (!pigs.MPcount) winner = 2;
  if (!pigs.FPcount) winner = 1;
}

int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

  return 0;
}