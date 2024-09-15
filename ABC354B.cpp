#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n;
  cin >> n;
  vector<string> s(n);
  unsigned short int sum = 0;
  for (string& i : s) {
    unsigned short int c;
    cin >> i >> c;
    (sum += c) %= n;
  }
  sort(s.begin(), s.end());
  cout << s[sum];
  return 0;
}