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
  unsigned short int lst;
  cin >> lst;
  for (size_t i = 1; i < n; ++i) {
    unsigned short int x;
    cin >> x;
    cout << lst * x << ' ';
    lst = x;
  }
  return 0;
}