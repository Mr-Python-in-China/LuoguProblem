#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  array<unsigned short int, 26> t = {};
  char c;
  while (cin >> c) ++t[c - 'a'];
  char ans = 0;
  for (size_t i = 0; i < 26; ++i)
    if (t[i] > t[ans]) ans = i;
  cout.put(ans + 'a');
  return 0;
}