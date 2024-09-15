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
    size_t n;
    string s;
    cin >> n >> s;
    vector<char> charset(s.begin(), s.end());
    sort(charset.begin(), charset.end()),
        charset.erase(unique(charset.begin(), charset.end()), charset.end());
    for (char i : s)
      cout << charset.rbegin()[lower_bound(charset.begin(), charset.end(), i) -
                               charset.begin()];
    cout << '\n';
  }
  return 0;
}