#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t T;
  cin >> T;
  while (T--) {
    size_t n;
    cin >> n;
    uli sum = 0;
    vector<ostringstream> s;
    for (size_t i = n - 1; i < n; --i) {
      s.emplace_back();
      s.back() << "1 " << i + 1 << ' ';
      for (size_t j = 0; j < n; ++j) s.back() << j + 1 << ' ';
      s.emplace_back();
      s.back() << "2 " << i + 1 << ' ';
      for (size_t j = 0; j < n; ++j) s.back() << j + 1 << ' ';
    }
    for (uli i = 1; i <= n; ++i) sum += i * (i * 2 - 1);
    cout << sum << ' ' << s.size() << '\n';
    for (ostringstream const& i : s) cout << i.str() << '\n';
  }
  return 0;
}