#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t T;
  cin >> T;
  while (T--) {
    size_t n;
    cin >> n;
    vector<int> a((n * n - n) >> 1);
    for (int& i : a) cin >> i;
    sort(a.begin(), a.end());
    for (vector<int>::iterator it = a.begin(); it < a.end(); it += (--n))
      cout << *it << ' ';
    cout << "1000000000\n";
  }
  return 0;
}