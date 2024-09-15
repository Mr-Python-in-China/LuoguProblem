#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t T;
  cin >> T;
  while (T--) {
    size_t n, k;
    cin >> n >> k;
    vector<bool> a(n);
    for (vector<bool>::reference i : a) {
      char c;
      cin >> c;
      i = c == '1';
    }
    vector<size_t> block;
    {
      bool flag = !a.front();
      for (bool i : a)
        if (i == flag)
          ++block.back();
        else
          flag = !flag, block.emplace_back(1);
    }
    vector<size_t> strange_block;
    for (size_t i = 0; i < block.size(); ++i)
      if (block[i] != k) strange_block.emplace_back(i);
    if (strange_block.size() == 2
            ? (strange_block[1] != block.size() - 1 ||
               block[strange_block[1]] > k || block[strange_block[0]] > k * 2 ||
               a[accumulate(block.begin(), block.begin() + strange_block[0],
                            size_t(0))] !=
                   a[accumulate(block.begin(), block.begin() + strange_block[1],
                                size_t(0))])
        : strange_block.size() == 1
            ? (block[strange_block[0]] != k * 2 ||
               (block[strange_block[0]] != k * 2 ||
                a[accumulate(block.begin(), block.begin() + strange_block[0],
                             size_t(0))] == a.back()))
        : strange_block.size() == 0 ? false
                                    : true) {
      cout << "-1\n";
      continue;
    }
    cout << (strange_block.size() == 0
                 ? n
                 : accumulate(block.begin(),
                              block.begin() + strange_block[0] + 1, size_t(0)) -
                       (block[strange_block[0]] > k ? k : 0))
         << '\n';
  }
  return 0;
}