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
  vector<ui> a(n);
  for (ui& i : a) cin >> i;
  auto it =
      find_if(next(a.begin()), a.end(), [&](ui x) { return x > a.front(); });
  it == a.end() ? cout << "-1" : cout << it - a.begin() + 1;
  return 0;
}