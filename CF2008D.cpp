#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
istream& fin = cin;
ostream& fout = cout;
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
    for (size_t& i : a) fin >> i, --i;
    vector<bool> c(n);
    for (auto i : c) {
      char c;
      fin >> c;
      i = c == '0';
    }
    vector<size_t> ans;
    vector<size_t> group(n, ~0);
    for (size_t i = 0; i < n; ++i) {
      if (!~group[i]) {
        group[i] = ans.size();
        ans.emplace_back(c[i]);
        for (size_t j = a[i]; j != i; j = a[j])
          ans.back() += c[j], group[j] = group[i];
      }
      fout << ans[group[i]] << ' ';
    }
    fout << '\n';
  }
  return 0;
}