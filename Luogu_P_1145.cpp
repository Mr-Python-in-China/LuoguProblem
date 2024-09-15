#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
using uc = unsigned char;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t k;
  cin >> k;
  for (size_t m = 1;; ++m) {
    deque<bool> q(k * 2, false);
    fill(q.begin(), next(q.begin(), k), true);
    for (size_t i = 0; i < k; ++i) {
      for (size_t j = (m - 1) % q.size(); j > 0; --j)
        q.push_back(q.front()), q.pop_front();
      if (q.front()) goto failed;
      q.pop_front();
    }
    cout << m;
    return 0;
  failed:;
  }
  return 0;
}