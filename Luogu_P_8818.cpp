#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
template <typename T, typename cmp = less<T>> class STtable {
  vector<vector<T>> table;
  static size_t lg2(size_t x) { return log2(max<size_t>(--x, 1)) + 1; }
  static T const& getcmp(T const& x, T const& y) { return cmp()(x, y) ? x : y; }

 public:
  template <typename InputIterator, typename = _RequireInputIter<InputIterator>>
  STtable(InputIterator it, size_t n): table(lg2(n)) {
    table.front().resize(n);
    std::copy_n(it, n, table.front().begin());
    for (size_t i = 1; i < table.size(); i++) {
      size_t k = 1 << i;
      table[i].resize(n - k + 1);
      for (size_t r = k; r <= n; r++)
        table[i][r - k] =
            getcmp(table[i - 1][r - k], table[i - 1][r - (k >> 1)]);
    }
  }
  T const& operator[](size_t p) { return table.front()[p]; }
  T const& get(size_t l, size_t r) {
    size_t k = lg2(r - l) - 1;
    return getcmp(table[k][l], table[k][r - (1 << k)]);
  }
};
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n, m, q;
  cin >> n >> m >> q;
  vector<li> a(n), b(m);
  for (li& i : a) cin >> i;
  for (li& i : b) cin >> i;
  vector<li> ap(a), aq(a);
  for (li& i : ap)
    if (i < 0) i = numeric_limits<li>::max();
  for (li& i : aq)
    if (i >= 0) i = numeric_limits<li>::min();
  STtable<li, greater<li>> stax(a.begin(), n), stbx(b.begin(), n),
      staq(aq.begin(), n);
  STtable<li, less<li>> stan(a.begin(), n), stbn(b.begin(), n),
      stap(ap.begin(), n);
  while (q--) {
    size_t l1, r1, l2, r2;
    cin >> l1 >> r1 >> l2 >> r2;
    --l1, --l2;
    li ansax = stax.get(l1, r1), ansbx = stbx.get(l2, r2),
       ansan = stan.get(l1, r1), ansbn = stbn.get(l2, r2),
       ansap = stap.get(l1, r1), ansaq = staq.get(l1, r1);
    li ans = max(ansax * (ansax >= 0 ? ansbn : ansbx),
                 ansan * (ansan >= 0 ? ansbn : ansbx));
    if (ansap != numeric_limits<li>::max())
      ans = max(ans, ansap * (ansap >= 0 ? ansbn : ansbx));
    if (ansaq != numeric_limits<li>::min())
      ans = max(ans, ansaq * (ansaq >= 0 ? ansbn : ansbx));
    cout << ans << '\n';
  }

  return 0;
}