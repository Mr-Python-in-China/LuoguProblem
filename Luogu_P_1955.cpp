#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
using uli = unsigned long long int;
struct dsds {
  vector<size_t> a;
  dsds(const size_t n) {
    a.resize(n);
    for (size_t i = 0; i < n; i++) a[i] = i;
  }
  inline size_t find(size_t p) { return a[p] == p ? p : a[p] = find(a[p]); }
  inline void link(size_t x, size_t y) { a[find(x)] = find(y); }
  inline bool in_one_set(size_t x, size_t y) { return find(x) == find(y); }
};
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr);
  size_t T;
  cin >> T;
  while (T--) {
    size_t n;
    cin >> n;
    vector<pair<uli, uli>> eq, neq;
    for (size_t i = 0; i < n; i++) {
      pair<uli, uli> qu;
      bool e;
      cin >> qu.first >> qu.second >> e;
      (e ? eq : neq).push_back(qu);
    }
    unordered_map<uli, size_t> dsc;
    size_t num_count = 0;
    for (vector<pair<uli, uli>>::const_reference i : eq) {
      if (!dsc.count(i.first)) dsc[i.first] = num_count++;
      if (!dsc.count(i.second)) dsc[i.second] = num_count++;
    }
    for (vector<pair<uli, uli>>::const_reference i : neq) {
      if (!dsc.count(i.first)) dsc[i.first] = num_count++;
      if (!dsc.count(i.second)) dsc[i.second] = num_count++;
    }
    dsds ds(num_count);
    for (vector<pair<uli, uli>>::const_reference i : eq)
      ds.link(dsc[i.first], dsc[i.second]);
    for (vector<pair<uli, uli>>::const_reference i : neq)
      if (ds.in_one_set(dsc[i.first], dsc[i.second])) {
        cout << "NO\n";
        goto out;
      }
    cout << "YES\n";
  out:;
  }
  return 0;
}