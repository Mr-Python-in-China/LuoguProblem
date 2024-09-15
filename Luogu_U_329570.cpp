#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using uli = unsigned long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n;
  uli k;
  cin >> k >> n;
  vector<uli> a(n);
  for (uli& i : a) cin >> i;
  size_t max_cnt = 0;
  uli min_time = -1;
  sort(a.begin(), a.end());
  do {
    size_t i = 0;
    uli timer = 0, passt = 0;
    for (; i < n; ++i)
      if ((passt += a[i]) <= k)
        (timer += timer + a[i]) %= 1440;
      else
        break;
    if (max_cnt <= i) {
      max_cnt = i;
      min_time = min(min_time, timer % 1440);
    }
  } while (next_permutation(a.begin(), a.end()));
  cout << max_cnt << ' ' << min_time;
  return 0;
}