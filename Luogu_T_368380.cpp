#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n;
  cin >> n;
  vector<bool> a(n);
  for (vector<bool>::reference i : a) {
    char c;
    cin >> c;
    i = c == '1';
  }
  size_t i;
  for (i = n - 1; i < n; i -= 2) cout << !a[i] << ' ';
  for (i = !(i + 2); i < n; i += 2) cout << a[i] << ' ';
  return 0;
}