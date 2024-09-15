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
    vector<bool> s(n), t(n);
    for (vector<bool>::reference i : s) {
      char c;
      cin >> c;
      i = c == '1';
    }
    for (vector<bool>::reference i : t) {
      char c;
      cin >> c;
      i = c == '1';
    }
    size_t f = find(s.begin(), s.end(), true) - s.begin();
    cout << (equal(s.begin(), s.begin() + f, t.begin()) ? "YES\n" : "NO\n");
  }
  return 0;
}