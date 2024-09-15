#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
struct question {
  ui i, j;
  question(void): i(~0), j(~0) {}
  question(ui _i, ui _j): i(_i), j(_j) {}
};
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  ui n, l, r;
  cin >> n >> l >> r;
  ++r;
  queue<size_t> q({l});
  vector<size_t> from((1 << n) + 1, ~0);
  vector<question> t((1 << n) + 1);
  while (!q.empty()) {
    ui p = q.front();
    q.pop();
    for (ui j = 0; (p & ((1u << j) - 1)) == 0 && j <= n; ++j) {
      if (p + (1u << j) <= (1u << n) && p + (1u << j) != l &&
          !~from[p + (1u << j)])
        t[p + (1u << j)] = {j, p / (1u << j)}, from[p + (1u << j)] = p,
                     q.push(p + (1u << j));
      if (p - (1u << j) <= (1u << n) && p - (1u << j) != l &&
          !~from[p - (1u << j)])
        t[p - (1u << j)] = {j, p / (1u << j) - 1}, from[p - (1u << j)] = p,
                     q.push(p - (1u << j));
    }
  }
  ui sum = 0;
  for (size_t i = r; i != l; i = from[i]) {
    cout << "? " << t[i].i << ' ' << t[i].j << endl;
    ui x;
    cin >> x;
    (sum += 100 + ((1 << t[i].i) * t[i].j != i ? x : -x)) %= 100;
  }
  cout << "! " << sum;
  return 0;
}