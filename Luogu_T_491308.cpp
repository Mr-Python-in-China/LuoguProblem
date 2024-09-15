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
  size_t n, r;
  fin >> n >> r;
  vector<bool> a(n);
  for (auto i : a) {
    char c;
    fin >> c;
    i = c == '1';
  }
  vector<size_t> ans;
  size_t mid = n / 2;
  for (size_t i = 0; i + 1 < mid; ++i)
    if (a[i] != a[i + 1])
      for (size_t j = i; j < n; --j) ans.emplace_back(j), a[j] = !a[j];
  for (size_t i = n - 1; i - 1 >= mid; --i)
    if (a[i] != a[i - 1])
      for (size_t j = i; j < n; ++j) ans.emplace_back(j), a[j] = !a[j];
  if (a[mid - 1] != a[mid])
    for (size_t j = mid - 1; j < n; --j) ans.emplace_back(j), a[j] = !a[j];
  fout << ans.size() << '\n';
  for (size_t i : ans) fout << i + 1 << ' ';
  return 0;
}