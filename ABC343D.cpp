#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n, t;
  cin >> n >> t;
  unordered_map<uli, size_t> c({
      {0, n}
  });
  vector<uli> score(n);
  while (t--) {
    size_t p;
    ui x;
    cin >> p >> x;
    --p;
    if (--c[score[p]] == 0) c.erase(score[p]);
    ++c[score[p] += x];
    cout << c.size() << '\n';
  }
  return 0;
}