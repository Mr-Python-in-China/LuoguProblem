#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
using usi = unsigned short int;
using graph = vector<vector<pair<size_t, unsigned char>>>;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n;
  cin >> n;
  graph mp(n);
  for (size_t i = 1; i < n; ++i) {
    size_t a, b;
    usi c;
    cin >> a >> b >> c;
    --a, --b;
    mp[a].emplace_back(b, c), mp[b].emplace_back(a, c);
  }

  return 0;
}