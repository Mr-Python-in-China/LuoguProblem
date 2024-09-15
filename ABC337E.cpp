#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
using usi = unsigned short int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  usi n;
  cin >> n;
  size_t m = ceil(log2(n));
  cout << m << endl;
  vector<vector<ui>> friends(m);
  for (ui i = 0; i < n; ++i) {
    usi x = i;
    for (size_t j = 0; x; ++j, x >>= 1)
      if (x & 1) friends[j].push_back(i);
  }
  for (vector<ui> const& i : friends) {
    cout << i.size() << ' ';
    for (ui j : i) cout << j + 1 << ' ';
    cout << '\n';
  }
  cout << flush;
  vector<bool> b(m);
  for (vector<bool>::reference i : b) {
    char c;
    cin >> c;
    i = c == '1';
  }
  usi juice = 0;
  for (size_t i = 0; i < m; ++i)
    if (b[i]) juice |= 1 << i;
  cout << juice + 1;
  return 0;
}