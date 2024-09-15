#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
istream &fin = cin;
ostream &fout = cout;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n;
  fin >> n;
  vector<ui> a(n);
  for (ui &i : a) fin >> i;
  sort(a.begin(), a.end(), greater<>());
  size_t ans = 0;
  while (a[1]) {
    a[0]--, a[1]--;
    sort(a.begin(), a.end(), greater<>());
    ++ans;
  }
  fout << ans;
  return 0;
}