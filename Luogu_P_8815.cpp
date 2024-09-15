#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
struct expression_tree {
  struct node {
    bool val;
    node *l = nullptr, *r = nullptr;
  }* root;
  node* make_tree(string::const_iterator& expression) {
    stack<bool, vector<bool>> opt;
    stack<node*, vector<node*>> ptr;
    while (*expression != ')') {
      if (*expression == '(')
        ptr.push(make_tree(++expression));
      else if (*expression == '0' || *expression == '1')
        ptr.push(new node{*expression == '1'});
      else {
        while (!opt.empty() && opt.top() >= (*expression == '&')) {
          node* tmp = new node{opt.top()};
          tmp->r = ptr.top();
          ptr.pop();
          tmp->l = ptr.top();
          ptr.pop();
          ptr.push(tmp);
          opt.pop();
        }
        opt.push(*expression == '&');
      }
      ++expression;
    }
    while (!opt.empty()) {
      node* tmp = new node{opt.top()};
      tmp->r = ptr.top();
      ptr.pop();
      tmp->l = ptr.top();
      ptr.pop();
      ptr.push(tmp);
      opt.pop();
    }
    return ptr.top();
  }
  expression_tree(string expression) {
    expression += ')';
    string::const_iterator it = expression.cbegin();
    root = make_tree(it);
  }
};
size_t ansor, ansand;
bool getval(expression_tree::node const* tree) {
  if (!tree->l && !tree->r)
    return tree->val;
  else if (tree->val) {  // and
    bool ans1 = getval(tree->l);
    if (!ans1)
      return ++ansand, false;
    else
      return getval(tree->r);
  } else {
    bool ans1 = getval(tree->l);
    if (ans1)
      return ++ansor, true;
    else
      return getval(tree->r);
  }
}
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  string expression;
  cin >> expression;
  expression_tree tree(expression);
  cout << getval(tree.root) << "\n" << ansand << ' ' << ansor;
  return 0;
}