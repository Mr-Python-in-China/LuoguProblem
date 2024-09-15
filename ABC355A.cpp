#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  char a, b;
  cin >> a >> b;
  if (a > b) swap(a, b);
  cout << (a == '1' && b == '2'   ? "3"
           : a == '1' && b == '3' ? "2"
           : a == '2' && b == '3' ? "1"
                                  : "-1");
  return 0;
}