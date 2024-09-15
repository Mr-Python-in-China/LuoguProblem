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
    vector<bool> a(n);
    for (vector<bool>::reference i : a) {
      char c;
      cin >> c;
      i = c == '1';
    }
    size_t l = n;
    for (; l > 1; --l) {
      vector<bool> e(n + 1);
      bool flip = false;
      for (size_t i = 0; i < n; ++i) {
        if (e[i]) flip ^= 1;
        if (!(a[i] ^ flip)) {
          if (i + l <= n)
            flip ^= 1, e[i + l] = true;
          else
            goto failed;
        }
      }
      break;
    failed:;
    }
    cout << l << '\n';
  }
  return 0;
}