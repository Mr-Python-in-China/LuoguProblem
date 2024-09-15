#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  array<short int, 9> a;
  array<short int, 8> b;
  for (auto& i : a) cin >> i;
  for (auto& i : b) cin >> i;
  cout << (accumulate(a.begin(), a.end(), 0) -
           accumulate(b.begin(), b.end(), 0) + 1);
  return 0;
}