#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
istream &fin = cin;
ostream &fout = cout;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
constexpr int MINA = -3e6 - 1, MAXA = 3e6 + 1;
vector<uli> f(vector<int> &a) {
  sort(a.begin(), a.end());
  size_t l = 0, r = a.size();
  int p = MINA;
  vector<uli> res;
  uli sum = 0;
  for (int i : a) sum += i - p;
  while (p < MAXA) {
    ++p, (sum += l) -= r;
    res.emplace_back(sum);
    size_t m =
        upper_bound(a.begin(), a.end(), p) - lower_bound(a.begin(), a.end(), p);
    r -= m, l += m;
  }
  return res;
}
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n;
  ui d;
  fin >> n >> d;
  vector<int> x(n), y(n);
  for (size_t i = 0; i < n; ++i) fin >> x[i] >> y[i];
  vector<uli> a = f(x), b = f(y);
  sort(a.begin(), a.end()), sort(b.begin(), b.end());
  uli ans = 0;
  for (uli i : a)
    if (i <= d) ans += upper_bound(b.begin(), b.end(), d - i) - b.begin();
  fout << ans;
  return 0;
}