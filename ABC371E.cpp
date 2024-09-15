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
  uli ans = 0, sum = 0;
  vector<size_t> pos(n, ~0);
  for (size_t i = 0; i < n; ++i) {
    size_t x;
    fin >> x;
    --x;
    (sum -= (pos[x] + 1)) += i + 1;
    pos[x] = i;
    ans += sum;
  }
  fout << ans;
  return 0;
}