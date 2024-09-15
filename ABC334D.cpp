#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
using usi = unsigned short int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t t;
  string s;
  cin >> s >> t;
  vector<usi> a(s.size() + 1, numeric_limits<usi>::max() / 2);
  a[0] = 0;
  while (t--) {
    vector<usi> na(a);
    size_t k;
    cin >> k;
    for (size_t i = 0; i < k; ++i) {
      string t;
      cin >> t;
      for (size_t i = 0, j = t.size(); j < a.size(); ++i, ++j)
        if (equal(t.cbegin(), t.cend(), s.cbegin() + i))
          na[j] = min<usi>(na[j], a[i] + 1);
    }
    a = na;
  }
  a.back() == numeric_limits<usi>::max() / 2 ? cout << "-1" : cout << a.back();
  return 0;
}