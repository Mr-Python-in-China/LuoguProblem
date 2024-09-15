#include <bits/stdc++.h>
using namespace std;
struct SgTree {
  size_t l, r;         // 区间范围[l,r)
  int maxx;            // 存储区间范围最大值 根节点存储值
  int changed, added;  // lazy标记 分别存储标记1和标记2
  SgTree *lt, *rt;     // 左右子树
  SgTree(const size_t& _l, const size_t& _r, const vector<int>& vec)
      : l(_l), r(_r), changed(0), added(0) {
    if (r - l == 1) {
      maxx = vec[l];
      lt = rt = nullptr;
      return;
    }
    size_t mid = (l + r) >> 1;
    lt = new SgTree(l, mid, vec), rt = new SgTree(mid, r, vec);
    maxx = max(lt->maxx, rt->maxx);
  }
  ~SgTree() { delete lt, delete rt; }
  void change(const size_t& _l, const size_t& _r, const int& x) {
    if (_l <= l && r <= _r) {
      added = 0, changed = x;
    } else {
      size_t mid = (l + r) >> 1;
      if (_l < mid) lt->change(l, mid, x);
      if (mid < r) rt->change(mid, r, x);
    }
  }
  void add(const size_t& _l, const size_t& _r, const int& x) {
    if (_l <= l && r <= _r)
      added += x;
    else {
      size_t mid = (l + r) >> 1;
      if (_l < mid) lt->add(l, mid, x);
      if (mid < r) rt->add(mid, r, x);
    }
  }
  void update(void) {
    if (r - l == 1)
      maxx = changed + added;
    else
      lt->changed = rt->changed = changed, lt->added += added,
      rt->added += added;
    added = changed = 0;
  }
  int query(const size_t& _l, const size_t& _r, const int& x) { update(); }
};
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n;
  cin >> n;
  vector<size_t> a(n);
  for (vector<size_t>::reference i : a) cin >> i;

  return 0;
}