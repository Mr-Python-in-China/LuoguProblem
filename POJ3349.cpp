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
  auto myhash = [](array<ui, 6> const& a) {
    return _Fnv_hash_impl::hash(a.begin(), a.size());
  };
  unordered_set<array<ui, 6>, decltype(myhash)> s(0, myhash);
  while (n--) {
    array<ui, 6> a;
    for (ui& i : a) cin >> i;
    array<ui, 6> b = a;
    reverse(a.begin(), a.end());
    rotate(a.begin(), min_element(a.begin(), a.end()), a.end()),
        rotate(b.begin(), min_element(b.begin(), b.end()), b.end());
    array<ui, 6> c = memcmp(a.data(), b.data(), 6) >= 0 ? a : b;
    if (s.count(c)) return cout << "Twin snowflakes found.", 0;
    s.insert(c);
  }
  cout << "No two snowflakes are alike.";
  return 0;
}