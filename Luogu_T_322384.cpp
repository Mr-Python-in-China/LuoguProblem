#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n, m;
  cin >> n >> m;
  vector<pair<double, string>> a(n);
  for (pair<double, string>& i : a) {
    cin >> i.second;
    vector<ui> exam(m);
    double ave = 0;
    for (ui& j : exam) cin >> j, ave += j;
    ave /= m;
    for (const ui& j : exam) i.first += (j - ave) * (j - ave);
    i.first = sqrt(i.first / m);
  }
  sort(a.begin(), a.end(),
       [](const pair<double, string>& a, const pair<double, string>& b) {
         return a.first == b.first ? a.second < b.second : a.first > b.first;
       });
  size_t len = min<size_t>(n, 20);
  for (ui i = 0; i < len; i++) cout << a[i].second << '\n';
  return 0;
}