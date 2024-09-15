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
  cin >> n;
  vector<pair<ui, size_t>> a(n);
  for (size_t i = 0; i < n; ++i) cin >> a[i].first, a[i].second = i;
  sort(a.begin(), a.end());
  sort(a.begin(), a.end(), greater<>());
  cout << a[1].second + 1;
  return 0;
}