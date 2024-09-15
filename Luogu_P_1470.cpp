#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  vector<string> a;
  {
    string t;
    while (cin >> t && t != ".") a.emplace_back(t);
  }
  string t;
  {
    string tmp;
    while (cin >> tmp) t += tmp;
  }
  vector<size_t> f(t.size() + 1);
  f[0] = true;
  for (size_t i = 0; i <= t.size(); ++i)
    for (string const &j : a)
      if (i >= j.size() && f[i - j.size()] &&
          t.substr(i - j.size(), j.size()) == j)
        f[i] = true;
  cout << f.rend() - find(f.rbegin(), f.rend(), true) - 1;
  return 0;
}