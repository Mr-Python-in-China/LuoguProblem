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
    vector<size_t> a(n);
    for (size_t &i : a) fin >> i, --i;
    vector<size_t> stk0, stk1;
    auto const g = [&a](vector<size_t> const &stk) {
      return stk.empty() ? 0 : a[stk.back()];
    };
    for (size_t i = 0; i < n; ++i) {
      if (g(stk0) <= a[i] && g(stk1) <= a[i])
        (g(stk0) > g(stk1) ? stk0 : stk1).emplace_back(i);
      else if (g(stk0) <= a[i])
        stk0.emplace_back(i);
      else if (g(stk1) <= a[i])
        stk1.emplace_back(i);
      else {
        fout << "-1\n";
        goto failed;
      }
    }
    {
      vector<bool> ans(n);
      for_each(stk0.begin(), stk0.end(), [&](size_t x) { ans[x] = true; });
      for (auto i : ans) fout << i + 1 << ' ';
      fout << '\n';
    }
  failed:;
  }
  return 0;
}