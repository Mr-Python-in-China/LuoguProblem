#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  char a, b, c;
  cin >> a >> b >> c;
  if (a == 'R' || (b == 'R' && c == 'M'))
    cout << "Yes";
  else
    cout << "No";
  return 0;
}