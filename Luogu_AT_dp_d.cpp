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
  size_t n;
  ui W;
  cin >> n >> W;
  vector<uli> f(W + 1);
  while (n--) {
    ui v, w;
    cin >> w >> v;
    for (size_t i = W; i >= w; --i) f[i] = max(f[i], f[i - w] + v);
  }
  cout << f.back();
  return 0;
}