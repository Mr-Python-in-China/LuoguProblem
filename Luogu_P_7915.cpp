#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t T;
  cin >> T;
  while (T--) {
    size_t n;
    cin >> n;
    vector<ui> a(n << 1);
    for (ui& i : a) cin >> i;
    vector<bool> ans1, ans2;
    bool flag = true;
    {
      size_t p = 1;
      for (; p < a.size(); ++p)
        if (a[p] == a.front()) break;
      ans1.push_back(false), ans2.push_back(false);
      deque<size_t> ql, qr;
      for (size_t i = 1; i < p; ++i) ql.push_back(i);
      for (size_t i = p + 1; i < a.size(); ++i) qr.push_front(i);
      while (!ql.empty() && !qr.empty()) {
        if (ql.size() > 1 && a[ql.front()] == a[ql.back()])
          ql.pop_front(), ql.pop_back(), ans1.push_back(false),
              ans2.push_back(false);
        else if (a[ql.front()] == a[qr.back()])
          ql.pop_front(), qr.pop_back(), ans1.push_back(false),
              ans2.push_back(true);
        else if (a[qr.front()] == a[ql.back()])
          qr.pop_front(), ql.pop_back(), ans1.push_back(true),
              ans2.push_back(false);
        else if (qr.size() > 1 && a[qr.front()] == a[qr.back()])
          qr.pop_front(), qr.pop_back(), ans1.push_back(true),
              ans2.push_back(true);
        else {
          flag = false;
          break;
        }
      }
      if (ql.size() > 1) {
        if (!qr.empty() || ql.size() & 1) flag = false;
        while (!ql.empty()) {
          if (a[ql.front()] != a[ql.back()]) {
            flag = false;
            break;
          }
          ans1.push_back(false), ans2.push_back(false), ql.pop_front(),
              ql.pop_back();
        }
      }
      if (qr.size() > 1) {
        if (!ql.empty() || qr.size() & 1) flag = false;
        while (!qr.empty()) {
          if (a[qr.front()] != a[qr.back()]) {
            flag = false;
            break;
          }
          ans1.push_back(true), ans2.push_back(true), qr.pop_front(),
              qr.pop_back();
        }
      }
      if (ql.size() == 1 && qr.size() == 1)
        ans1.push_back(false), ans2.push_back(true);
    }
    if (flag) {
      for_each(ans1.cbegin(), ans1.cend(),
               [](bool b) { cout.put(!b ? 'L' : 'R'); });
      for_each(ans2.crbegin(), ans2.crend(),
               [](bool b) { cout.put(!b ? 'L' : 'R'); });
      cout.put('\n');
      continue;
    }
    flag = true;
    ans1.clear(), ans2.clear();
    reverse(a.begin(), a.end());
    {
      size_t p = 1;
      for (; p < a.size(); ++p)
        if (a[p] == a.front()) break;
      ans1.push_back(false), ans2.push_back(true);
      deque<size_t> ql, qr;
      for (size_t i = 1; i < p; ++i) ql.push_back(i);
      for (size_t i = p + 1; i < a.size(); ++i) qr.push_front(i);
      while (!ql.empty() && !qr.empty()) {
        if (qr.size() > 1 && a[qr.front()] == a[qr.back()])
          qr.pop_front(), qr.pop_back(), ans1.push_back(true),
              ans2.push_back(true);
        else if (a[qr.front()] == a[ql.back()])
          qr.pop_front(), ql.pop_back(), ans1.push_back(true),
              ans2.push_back(false);
        else if (a[ql.front()] == a[qr.back()])
          ql.pop_front(), qr.pop_back(), ans1.push_back(false),
              ans2.push_back(true);
        else if (ql.size() > 1 && a[ql.front()] == a[ql.back()])
          ql.pop_front(), ql.pop_back(), ans1.push_back(false),
              ans2.push_back(false);
        else {
          flag = false;
          break;
        }
      }
      if (ql.size() > 1) {
        if (!qr.empty() || ql.size() & 1) flag = false;
        while (!ql.empty()) {
          if (a[ql.front()] != a[ql.back()]) {
            flag = false;
            break;
          }
          ans1.push_back(false), ans2.push_back(false), ql.pop_front(),
              ql.pop_back();
        }
      }
      if (qr.size() > 1) {
        if (!ql.empty() || qr.size() & 1) flag = false;
        while (!qr.empty()) {
          if (a[qr.front()] != a[qr.back()]) {
            flag = false;
            break;
          }
          ans1.push_back(true), ans2.push_back(true), qr.pop_front(),
              qr.pop_back();
        }
      }
      if (ql.size() == 1 && qr.size() == 1)
        ans1.push_back(true), ans2.push_back(false);
    }
    if (flag) {
      for_each(ans1.cbegin(), ans1.cend(),
               [](bool b) { cout.put(b ? 'L' : 'R'); });
      for_each(ans2.crbegin(), ans2.crend(),
               [](bool b) { cout.put(b ? 'L' : 'R'); });
      cout.put('\n');
      continue;
    }
    cout << "-1\n";
  }
  return 0;
}