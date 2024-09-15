#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
using uc = unsigned char;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t T;
  cin >> T;
  while (T--) {
    size_t n, m;
    cin >> n >> m;
    vector<uc> back_zero(n);
    size_t ans = 0;
    for (uc& i : back_zero) {
      string s;
      cin >> s;
      ans += s.size();
      while (s.back() == '0') ++i, s.pop_back();
    }
    sort(back_zero.begin(), back_zero.end());
    bool turn = 1;
    while (!back_zero.empty()) {
      if (turn) ans -= back_zero.back();
      back_zero.pop_back();
      turn = !turn;
    }
    cout << (ans > m ? "Sasha\n" : "Anna\n");
  }
  return 0;
}