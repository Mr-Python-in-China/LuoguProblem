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
  vector<size_t> cnt(n);
  vector<pair<unsigned short int, size_t>> item(n);
  for (auto &i : item) {
    cin >> i.second;
    ++cnt[--i.second];
  }
  for (auto &i : item) cin >> i.first;
  sort(item.begin(), item.end());
  ui ans = 0;
  for (auto const &i : item)
    if (cnt[i.second] > 1) --cnt[i.second], ans += i.first;
  cout << ans;
  return 0;
}