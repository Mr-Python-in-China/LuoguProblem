#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
template <typename It> bool is_reverse_equal(It begin, It end) {
  return equal(begin, end, reverse_iterator<It>(end));
}
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n, k;
  string s;
  cin >> n >> k >> s;
  sort(s.begin(), s.end());
  ui ans = 0;
  do {
    for (string::iterator it = s.begin(), jt = it + k; jt <= s.end();
         ++it, ++jt)
      if (is_reverse_equal(it, jt)) goto failed;
    ++ans;
  failed:;
  } while (next_permutation(s.begin(), s.end()));
  cout << ans;
  return 0;
}