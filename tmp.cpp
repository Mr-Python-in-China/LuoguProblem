#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
istream &fin = cin;
ostream &fout = cout;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n, k;
  fin >> n >> k;
  mt19937 rd(random_device{}());
  long double sum = 0;
  for (size_t T = 0; T < k; ++T) {
    vector<size_t> h(n);
    for (size_t i = 1; i < n; ++i) {
      uniform_int_distribution<size_t> d(0, i - 1);
      h[i] = h[d(rd)] + 1;
    }
    sum += *max_element(h.begin(), h.end()) + 1;
  }
  fout << sum / k;
  return 0;
}