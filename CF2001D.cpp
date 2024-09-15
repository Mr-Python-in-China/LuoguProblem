#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
istream &fin = cin;
ostream &fout = cout;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t T;
  fin >> T;
  while (T--) {
    size_t n;
    fin >> n;
    vector<ui> a(n);
    map<ui, size_t> lstappear;
    for (size_t i = 0; i < n; ++i) {
      fin >> a[i];
      lstappear[a[i]] = i;
    }
    set<size_t> keypos;
    for (auto const &i : lstappear) keypos.emplace(i.second);
    vector<size_t> ans;
    map<ui, list<size_t>> q;
    size_t r = 0;
    vector<pair<map<ui, list<size_t>>::iterator, list<size_t>::iterator>> its;
    size_t l = 0;
    while (!lstappear.empty()) {
      {
        size_t i = r;
        r = *keypos.begin() + 1;
        for (; i < r; ++i)
          if (lstappear.count(a[i])) {
            auto it = q.emplace(a[i], list<size_t>()).first;
            it->second.emplace_back(i);
            its.emplace_back(it, prev(it->second.end()));
          } else
            its.emplace_back();
      }

      size_t p =
          (ans.size() & 1 ? q.begin()->second : q.rbegin()->second).front();
      q.erase(a[p]);
      ans.emplace_back(a[p]);
      keypos.erase(lstappear[a[p]]);
      lstappear.erase(a[p]);
      for (; l <= p; ++l) try {
          if (q.at(a[l]).front() < r) {
            its[l].first->second.erase(its[l].second);
            if (its[l].first->second.empty()) q.erase(its[l].first);
          }
        } catch (out_of_range const &) {}
    }
    fout << ans.size() << '\n';
    for (auto i : ans) fout << i << ' ';
    fout << '\n';
  }
  return 0;
}