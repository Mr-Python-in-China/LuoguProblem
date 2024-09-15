#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n;
  cin >> n;
  multiset<ui> a;
  for (size_t i = 0; i < n; ++i) {
    ui x;
    cin >> x;
    a.insert(x);
  }
  if (n == 2) cout << "1\n" << *a.begin() << "\n1\n" << *a.rbegin(), exit(0);
  {
    multiset<ui> s = a;
    vector<ui> r1;
    r1.push_back(*s.begin()), s.erase(s.begin());
    r1.push_back(*s.begin()), s.erase(s.begin());
    ui d1 = r1[1] - r1[0];
    while (true) {
      multiset<ui>::iterator it = s.find(r1.back() + d1);
      if (it == s.end()) break;
      r1.push_back(*it), s.erase(it);
    }
    vector<ui> r2(s.begin(), s.end());
    if (r2.size() >= 2) {
      ui d2 = r2[1] - r2[0];
      for (size_t i = 0, j = 1; j < r2.size(); ++i, ++j)
        if (r2[j] - r2[i] != d2) {
          vector<ui>::iterator it =
              lower_bound(r1.begin(), r1.end(), r2[i] + d2);
          vector<ui> tmp((r1.end() - it) + (r2.end() - (r2.begin() + 1)));
          merge(it, r1.end(), r2.begin() + 1, r2.end(), tmp.begin());
          r1.erase(it, r1.end());
          r2.erase(r2.begin() + 1, r2.end()),
              r2.insert(r2.end(), tmp.begin(), tmp.end());
          if (r2[j] - r2[i] != d2) goto next1;
        }
    }
    if (r1.size() == 0) r1.push_back(r2.back()), r2.pop_back();
    if (r2.size() == 0) r2.push_back(r1.back()), r1.pop_back();
    cout << r1.size() << '\n';
    for (ui i : r1) cout << i << ' ';
    cout << '\n' << r2.size() << '\n';
    for (ui i : r2) cout << i << ' ';
    return 0;
  }
next1:;
  {
    multiset<ui> s = a;
    vector<ui> r1;
    r1.push_back(*s.begin()), s.erase(s.begin());
    r1.push_back(*next(s.begin())), s.erase(next(s.begin()));
    ui d1 = r1[1] - r1[0];
    while (true) {
      multiset<ui>::iterator it = s.find(r1.back() + d1);
      if (it == s.end()) break;
      r1.push_back(*it), s.erase(it);
    }
    vector<ui> r2(s.begin(), s.end());
    if (r2.size() >= 2) {
      ui d2 = r2[1] - r2[0];
      for (size_t i = 0, j = 1; j < r2.size(); ++i, ++j)
        if (r2[j] - r2[i] != d2) {
          vector<ui>::iterator it =
              lower_bound(r1.begin(), r1.end(), r2[i] + d2);
          vector<ui> tmp((r1.end() - it) + (r2.end() - (r2.begin() + 1)));
          merge(it, r1.end(), r2.begin() + 1, r2.end(), tmp.begin());
          r1.erase(it, r1.end());
          r2.erase(r2.begin() + 1, r2.end()),
              r2.insert(r2.end(), tmp.begin(), tmp.end());
          if (r2[j] - r2[i] != d2) goto next2;
        }
    }
    if (r1.size() == 0) r1.push_back(r2.back()), r2.pop_back();
    if (r2.size() == 0) r2.push_back(r1.back()), r1.pop_back();
    cout << r1.size() << '\n';
    for (ui i : r1) cout << i << ' ';
    cout << '\n' << r2.size() << '\n';
    for (ui i : r2) cout << i << ' ';
    return 0;
  }
next2:;
  {
    multiset<ui> s = a;
    vector<ui> r1;
    r1.push_back(*next(s.begin())), s.erase(next(s.begin()));
    r1.push_back(*next(s.begin())), s.erase(next(s.begin()));
    ui d1 = r1[1] - r1[0];
    while (true) {
      multiset<ui>::iterator it = s.find(r1.back() + d1);
      if (it == s.end()) break;
      r1.push_back(*it), s.erase(it);
    }
    vector<ui> r2(s.begin(), s.end());
    if (r2.size() >= 2) {
      ui d2 = r2[1] - r2[0];
      for (size_t i = 0, j = 1; j < r2.size(); ++i, ++j)
        if (r2[j] - r2[i] != d2) {
          vector<ui>::iterator it =
              lower_bound(r1.begin(), r1.end(), r2[i] + d2);
          vector<ui> tmp((r1.end() - it) + (r2.end() - (r2.begin() + 1)));
          merge(it, r1.end(), r2.begin() + 1, r2.end(), tmp.begin());
          r1.erase(it, r1.end());
          r2.erase(r2.begin() + 1, r2.end()),
              r2.insert(r2.end(), tmp.begin(), tmp.end());
          if (r2[j] - r2[i] != d2) goto next3;
        }
    }
    if (r1.size() == 0) r1.push_back(r2.back()), r2.pop_back();
    if (r2.size() == 0) r2.push_back(r1.back()), r1.pop_back();
    cout << r1.size() << '\n';
    for (ui i : r1) cout << i << ' ';
    cout << '\n' << r2.size() << '\n';
    for (ui i : r2) cout << i << ' ';
    return 0;
  }
next3:;
  cout << "-1";
  return 0;
}