#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
struct node {
  enum class OPT : char { AND, OR };
  union {
    OPT opt;
    size_t varid;
  } val;
  node *l = nullptr, *r = nullptr;
  bool fw = false;   // 废物标记
  bool rev = false;  // 去反标记
};
node* make_expression(string& expression, vector<bool>& vars) {
  stack<node*> ptr;
  for (string::iterator it = expression.begin(); it != expression.end(); ++it) {
    if (*it == 'x') {
      size_t id = 0;
      ++it;
      while (*it != ' ') id = id * 10 + *(it++) - '0';
      ptr.push(new node);
      ptr.top()->val.varid = --id;
    } else {
      if (*it == '!')
        ptr.top()->rev ^= 1;
      else {
        node* r = ptr.top();
        ptr.pop();
        node* l = ptr.top();
        ptr.pop();
        ptr.push(new node);
        ptr.top()->val.opt = (*it == '&' ? node::OPT::AND : node::OPT::OR);
        ptr.top()->l = l, ptr.top()->r = r;
      }
      ++it;
    }
  }
  return ptr.top();
}
bool get_ans(node* root, vector<bool> const& vars) {
  bool res;
  if (root->l && root->r) {
    bool ans1 = get_ans(root->l, vars), ans2 = get_ans(root->r, vars);
    if (root->val.opt == node::OPT::AND) {
      res = ans1 && ans2;
      if (!ans1) root->r->fw = true;
      if (!ans2) root->l->fw = true;
    } else {
      res = ans1 || ans2;
      if (ans1) root->r->fw = true;
      if (ans2) root->l->fw = true;
    }
  } else
    res = vars[root->val.varid];
  if (root->rev) res ^= 1;
  return res;
}
void update_fw(node* root, vector<bool>& is_fw) {
  if (root->l && root->r) {
    if (root->fw) root->l->fw = root->r->fw = true;
    update_fw(root->l, is_fw), update_fw(root->r, is_fw);
  } else if (root->fw)
    is_fw[root->val.varid] = true;
}
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  string s;
  getline(cin, s);
  s += ' ';
  size_t n;
  cin >> n;
  vector<bool> vars(n);
  vector<bool> fw(n);
  copy_n(istream_iterator<bool>(cin), n, vars.begin());
  node* root = make_expression(s, vars);
  bool ans = get_ans(root, vars);
  update_fw(root, fw);
  size_t q;
  cin >> q;
  while (q--) {
    size_t x;
    cin >> x;
    --x;
    cout << (ans ^ fw[x] ^ 1) << '\n';
  }
  return 0;
}