#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
using usi = unsigned short int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  array<pair<usi, usi>, 6> k = {
      {{500, 0}, {100, 0}, {50, 0}, {10, 0}, {5, 0}, {1, 0}}
  };
  size_t n;
  cin >> k[5].second >> k[4].second >> k[3].second >> k[2].second >>
      k[1].second >> k[0].second >> n;
  vector<usi> d(n);
  for (usi& i : d) cin >> i;
  for (usi i : d) {
    auto p = k.begin();
    while (i) {
      while (p->first > i || p->second == 0)
        if (++p == k.end()) {
          cout << "No";
          return 0;
        }
      i -= p->first, --p->second;
    }
  }
  cout << "Yes";
  return 0;
}