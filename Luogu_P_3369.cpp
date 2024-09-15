#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  vector<int> a;
  size_t n;
  cin >> n;
  while (n--) {
    char c;
    int x;
    cin >> c >> x;
    if (c == '1')
      a.insert(upper_bound(a.begin(), a.end(), x), x);
    else if (c == '2')
      a.erase(lower_bound(a.begin(), a.end(), x));
    else if (c == '3')
      cout << lower_bound(a.begin(), a.end(), x) - a.begin() + 1 << '\n';
    else if (c == '4')
      cout << a[x - 1] << '\n';
    else if (c == '5')
      cout << *prev(lower_bound(a.begin(), a.end(), x)) << '\n';
    else if (c == '6')
      cout << *upper_bound(a.begin(), a.end(), x) << '\n';
  }
  return 0;
}