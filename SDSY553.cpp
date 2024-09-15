#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  array<bitset<9>, 9> b;
  for (bitset<9>& i : b) {
    char s[10];
    cin >> s;
    b = bitset<9>(s);
  }
  return 0;
}