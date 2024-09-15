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
  size_t n;
  fin >> n;
  vector<int> d[2];
  ui ans[2] = {0, 0};
  for (size_t i = 0; i < n; ++i) {
    int x;
    char c;
    fin >> x >> c;
    if (!d[c == 'R'].empty()) ans[c == 'R'] += abs(d[c == 'R'].back() - x);
    d[c == 'R'].emplace_back(x);
  }
  fout << ans[0] + ans[1];
  return 0;
}