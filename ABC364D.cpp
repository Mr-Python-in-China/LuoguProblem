#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
struct q {
  size_t j;
  int b;
  size_t k;
  ui ans;
};
template <typename Fn1, typename Fn2>
auto getKthElement(size_t m, size_t n, Fn1 const &nums1, Fn2 const &nums2,
                   size_t k) {
  size_t index1 = 0, index2 = 0;
  while (true) {
    if (index1 == m) { return nums2(index2 + k - 1); }
    if (index2 == n) { return nums1(index1 + k - 1); }
    if (k == 1) { return min(nums1(index1), nums2(index2)); }
    size_t newIndex1 = min(index1 + k / 2 - 1, m - 1);
    size_t newIndex2 = min(index2 + k / 2 - 1, n - 1);
    auto pivot1 = nums1(newIndex1);
    auto pivot2 = nums2(newIndex2);
    if (pivot1 <= pivot2) {
      k -= newIndex1 - index1 + 1;
      index1 = newIndex1 + 1;
    } else {
      k -= newIndex2 - index2 + 1;
      index2 = newIndex2 + 1;
    }
  }
  throw;
}
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (int &i : a) cin >> i;
  sort(a.begin(), a.end());
  vector<q> s(m);
  for (size_t i = 0; i < m; ++i) {
    s[i].j = i;
    cin >> s[i].b >> s[i].k;
    --s[i].k;
  }
  sort(s.begin(), s.end(), [](q const &x, q const &y) { return x.b < y.b; });
  deque<int> l, r(a.begin(), a.end());
  for (q &i : s) {
    while (!r.empty() && r.front() < i.b)
      l.push_front(r.front()), r.pop_front();
    i.ans = getKthElement(
        l.size(), r.size(), [&l, &i](size_t p) { return i.b - l[p]; },
        [&r, &i](size_t p) { return r[p] - i.b; }, i.k + 1);
  }
  sort(s.begin(), s.end(), [](q const &a, q const &b) { return a.j < b.j; });
  for (q const &i : s) cout << i.ans << '\n';
  return 0;
}