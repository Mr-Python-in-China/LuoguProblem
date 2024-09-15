#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
class DictTree {
  struct node {
    unordered_map<char, node*> nxt;
    size_t cnt;
    node(void): cnt(0) {}
    ~node() {
      for (auto const& i : nxt) delete i.second;
    }
  };
  node root;

 public:
  DictTree(void) {}
  void insert(const string& s) {
    node* ptr = &root;
    ptr->cnt++;
    for (const char& i : s) {
      if (!ptr->nxt[i]) ptr->nxt[i] = new node;
      ptr = ptr->nxt[i];
      ptr->cnt++;
    }
    return;
  }
  size_t frontsub_count(const string& s) {
    node* ptr = &root;
    for (const char& i : s) {
      if (!ptr->nxt[i])
        return 0;
      else
        ptr = ptr->nxt[i];
    }
    return ptr->cnt;
  }
};
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t T;
  cin >> T;
  while (T--) {
    size_t n, q;
    cin >> n >> q;
    DictTree dt;
    while (n--) {
      string s;
      cin >> s;
      dt.insert(s);
    }
    while (q--) {
      string s;
      cin >> s;
      cout << dt.frontsub_count(s) << '\n';
    }
  }
  return 0;
}