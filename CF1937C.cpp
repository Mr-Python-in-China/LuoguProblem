#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
signed char ask(size_t a, size_t b, size_t c, size_t d) {
  cout << "? " << a << ' ' << b << ' ' << c << ' ' << d << endl;
  char res;
  cin >> res;
  return res == '<' ? -1 : res == '=' ? 0 : res == '>' ? 1 : throw;
};

int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t T;
  cin >> T;
  while (T--) {
    size_t n;
    cin >> n;
    size_t pmx = 0;
    for (size_t i = 1; i < n; ++i)
      if (ask(pmx, pmx, i, i) < 0) pmx = i;
    vector<size_t> ts({0});
    for (size_t i = 1; i < n; ++i) {
      switch (ask(ts.front(), pmx, i, pmx)) {
        case -1: ts.clear();
        case 0: ts.push_back(i);
      }
    }
    size_t pas = ts.front();
    for (size_t i : ts)
      if (ask(pas, pas, i, i) > 0) pas = i;
    cout << "! " << pmx << ' ' << pas << endl;
  }
  return 0;
}