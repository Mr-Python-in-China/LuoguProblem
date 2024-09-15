#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  string s;
  char t[4];
  cin >> s >> t;
  s.push_back('x');
  unsigned char version = 0;
  array<size_t, 26> c{};
  for (char i : s) {
    ++c[i];
    if (i == tolower(t[version])) {
      --c[i];
      if (++version == 3) return cout << "Yes", 0;
    }
  }
  cout << "No";
  return 0;
}