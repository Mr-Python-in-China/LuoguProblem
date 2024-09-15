#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  char c;
  array<size_t, 26> s{};
  while (cin >> c) ++s[c - 'a'];
  map<size_t, size_t> t;
  for (size_t i : s)
    if (i) ++t[i];
  for (auto i : t)
    if (i.second == 0 || i.second == 2)
      ;
    else
      return cout << "No", 0;
  cout << "Yes";
  return 0;
}