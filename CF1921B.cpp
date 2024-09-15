#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
istream& operator>>(istream& in, vector<bool>::reference b) {
  char c;
  in >> c;
  b = c == '1';
  return in;
}
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t T;
  cin >> T;
  while (T--) {
    size_t n;
    cin >> n;
    vector<bool> a(n), b(n);
    for (vector<bool>::reference i : a) cin >> i;
    for (vector<bool>::reference i : b) cin >> i;
    for (size_t i = 0; i < n; ++i)
      if (a[i] && b[i]) a[i] = b[i] = false;
    cout << max(accumulate(a.cbegin(), a.cend(), size_t(0)),
                accumulate(b.cbegin(), b.cend(), size_t(0)))
         << '\n';
  }
  return 0;
}