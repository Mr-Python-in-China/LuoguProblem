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
  vector<ui> a(n);
  for (ui& i : a) cin >> i;
  stack<size_t> slx, sln, srx, srn;
  vector<size_t> alx(n), aln(n), arx(n), arn(n);
  for (size_t i = 0; i < n; ++i) {
    while (!slx.empty() && a[slx.top()] < a[i]) slx.pop();
    alx[i] = slx.empty() ? -1 : slx.top();
    slx.push(i);
    while (!sln.empty() && a[sln.top()] >= a[i]) sln.pop();
    aln[i] = sln.empty() ? -1 : sln.top();
    sln.push(i);
  }
  for (size_t i = n - 1; i < n; --i) {
    while (!srx.empty() && a[srx.top()] <= a[i]) srx.pop();
    arx[i] = srx.empty() ? n : srx.top();
    srx.push(i);
    while (!srn.empty() && a[srn.top()] > a[i]) srn.pop();
    arn[i] = srn.empty() ? n : srn.top();
    srn.push(i);
  }
  li ans = 0;
  for (size_t i = 0; i < n; ++i)
    ans += li(a[i]) * (i - alx[i]) * (arx[i] - i) -
           li(a[i]) * (i - aln[i]) * (arn[i] - i);
  cout << ans;
  return 0;
}