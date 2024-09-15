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
  unordered_map<ui, ui> p;
  for (size_t i = 0; i < n; ++i) {
    ui x;
    cin >> x;
    p[x] = i;
  };
  vector<ui> a(n);
  for (ui& i : a) cin >> i, i = p[i];
  vector<ui> f;
  for (ui i : a) {
    vector<ui>::iterator it = upper_bound(f.begin(), f.end(), i);
    it == f.end() ? f.push_back(i) : void(*it = i);
  }
  cout << f.size();
  return 0;
}