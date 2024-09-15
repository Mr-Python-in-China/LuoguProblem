#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
istream &fin = cin;
ostream &fout = cout;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
struct trie {
  struct node {
    size_t cnt;
    node *son[2];
    node(node &) = delete;
    node(void): cnt(), son{nullptr, nullptr} {};
  } root;
  trie(void): root() {}
  void insert(ui x) {
    node *p = &root;
    for (size_t i = 0; i < sizeof(ui) * 8; ++i, x <<= 1) {
      ++p->cnt;
      bool v = x >> (sizeof(ui) * 8 - 1) & 1;
      if (!p->son[v]) p->son[v] = new node;
      p = p->son[v];
    }
    ++p->cnt;
  }
};
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t T;
  fin >> T;
  while (T--) {
    size_t n;
    fin >> n;
    vector<ui> a(n);
    for (ui &i : a) fin >> i;
    sort(a.begin(), a.end());
    trie t;
    {
      trie::node *p = &t.root;
      for (size_t i = 0; i < sizeof(ui) * 8; ++i)
        p = p->son[0] = new trie::node;
    }
    uli sum = count(a.begin(), a.end(), 0);
    sum *= sum;
    for (ui i : a) {
      t.insert(i);
      trie::node *p = &t.root;
      if (i == 0) continue;
      bitset<32> x = i;
      size_t j = 0;
      while (p->son[0]->son[0] && !x[31 - j]) p = p->son[0], ++j;
      p = p->son[0], ++j;
      while (p->son[0]) {
        if (x[31 - j]) sum += (p->son[1] ? p->son[1]->cnt : 0);
        p = p->son[0];
        ++j;
      }
      sum += p->cnt;
    }
    fout << sum << '\n';
  }
  return 0;
}