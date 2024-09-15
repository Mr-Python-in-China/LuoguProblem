#include <bits/extc++.h>
using namespace std;
using ui = unsigned int;
using timu = pair<double, ui>;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n, k;
  cin >> n >> k;
  vector<timu> a(n);
  for (size_t i = 0; i < n; i++) {
    ui sum = 0;
    for (size_t j = 0; j < k; j++) {
      ui tmp;
      cin >> tmp;
      sum += tmp;
    }
    a[i] = {double(sum) / k, n - i};
  }
  sort(a.begin(), a.end(), greater<timu>());
  cout << n - a[0].second + 1 << '\n' << n - a[1].second + 1;
  return 0;
}