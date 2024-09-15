#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n, m;
  cin >> n >> m;
  vector<int> a(m);
  for (int &i : a) cin >> i;
  while (n--)
    for (size_t i = 0; i < m; ++i) {
      ui x;
      cin >> x;
      a[i] -= x;
    }
  cout << (!count_if(a.begin(), a.end(), [](int x) { return x > 0; }) ? "Yes"
                                                                      : "No");
  return 0;
}