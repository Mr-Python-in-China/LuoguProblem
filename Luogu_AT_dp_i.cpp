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
  size_t n;
  fin >> n;
  vector<double> f = {1};
  for (size_t i = 0; i < n; ++i) {
    double p;
    fin >> p;
    vector<double> g(f.size() + 1);
    for (size_t j = 0; j < f.size(); ++j)
      g[j] += (1 - p) * f[j], g[j + 1] += p * f[j];
    f = g;
  }
  fout << setprecision(15)
       << accumulate(f.begin() + (f.size() + 1) / 2, f.end(), 0.0);
  return 0;
}