#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  char c;
  cin >> c;
  if (!isupper(c)) cout << "No\n", exit(0);
  while (cin >> c)
    if (!islower(c)) cout << "No\n", exit(0);
  cout << "Yes\n";
  return 0;
}