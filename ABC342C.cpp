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
  vector<char> s(n);
  for (char& i : s) cin >> i;
  size_t m;
  cin >> m;
  array<char, 128> mapper;
  iota(mapper.begin(), mapper.end(), char(0));
  while (m--) {
    char c, d;
    cin >> c >> d;
    for (char& i : mapper)
      if (i == c) i = d;
  }
  for (char i : s) cout.put(mapper[i]);
  return 0;
}