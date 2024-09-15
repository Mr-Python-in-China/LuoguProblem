#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  char c;
  bool flag = true;
  while (cin >> c) {
    if (c == '|')
      flag = !flag;
    else if (flag)
      cout.put(c);
  }
  return 0;
}