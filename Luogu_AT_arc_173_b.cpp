#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
double dist(pair<double, double> a, pair<double, double> b) {
  return sqrt((a.first - b.first) * (a.first - b.first) +
              (a.second - b.second) * (a.second - b.second));
}
bool check(pair<ui, ui> a, pair<ui, ui> b, pair<ui, ui> c) {
  return dist(a, b) + dist(a, c) > dist(b, c) &&
         dist(a, c) + dist(b, c) > dist(a, b) &&
         dist(a, b) + dist(b, c) > dist(a, c);
}
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n;
  cin >> n;
  vector<pair<ui, ui>> a(n);
  for (pair<ui, ui>& i : a) cin >> i.first >> i.second;
  for (size_t i = 0; i < n; ++i)
    for (size_t j = i + 1; j < n; ++j)
      for (size_t k = j + 1; k < n; ++k) {}
  return 0;
}