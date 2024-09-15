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
  size_t T;
  cin >> T;
  while (T--) {
    size_t n;
    uli l;
    cin >> n >> l;
    vector<pair<uli, uli>> a(n);
    for (pair<uli, uli> &i : a) cin >> i.first >> i.second;
    sort(a.begin(), a.end(),
         [](auto const &a, auto const &b) { return a.second < b.second; });
    size_t maxk = 0;
    for (size_t i = 0; i < n; ++i) {
      uli sum = 0;
      priority_queue<uli> used;
      for (size_t j = i; j < n && a[j].second - a[i].second <= l; ++j) {
        used.push(a[j].first), sum += a[j].first;
        while (sum + (a[j].second - a[i].second) > l)
          sum -= used.top(), used.pop();
        maxk = max(maxk, used.size());
      }
    }
    cout << maxk << '\n';
  }
  return 0;
}