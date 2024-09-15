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
  size_t T;
  fin >> T;
  while (T--) {
    size_t n;
    fin >> n;
    vector<size_t> block = {0};
    bool lst = false;
    for (size_t i = 0; i < n; ++i) {
      char c;
      cin >> c;
      bool b = c == '1';
      if (b != lst) block.emplace_back();
      ++block.back();
      lst = b;
    }
    if (block.front() == 0) block.erase(block.begin());

    size_t c1 = 0, c2 = block.size();
    for (size_t i = 0; i + 1 < block.size(); ++i) {
      if (block[i] & 1) {
        if (block[i] == 1)
          --block[i], ++block[i + 1], ++c1, --c2;
        else
          ++block[i], (--block[i + 1] == 0 ? --c2 : c2), ++c1;
      }
      if (i > 0 && block[i] == 0) {
        assert(block[i - 1]);
        block[i + 1] += block[i - 1], block[i - 1] = 0, --c2;
      }
    }
    fout << c1 << ' ' << c2 << '\n';
  }
  return 0;
}