#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  string s;
  cin >> s;
  vector<vector<ui>> f(s.size() + 1, vector<ui>(s.size() + 1));
  for (size_t i = 0; i < s.size(); ++i)
    for (size_t j = 0; j < s.size(); ++j)
      f[i + 1][j + 1] = s.begin()[i] == s.rbegin()[j]
                            ? f[i][j] + 1
                            : max(f[i][j + 1], f[i + 1][j]);
  cout << s.size() - f.back().back();
  return 0;
}