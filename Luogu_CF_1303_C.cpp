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
    string s;
    cin >> s;
    array<set<char>, 26> mp = {};
    for (string::const_iterator it = s.cbegin(), jt = next(it); jt != s.cend();
         ++it, ++jt)
      mp[*it - 'a'].insert(*jt - 'a'), mp[*jt - 'a'].insert(*it - 'a');
    bitset<26> vis = {};
    char start = -1;
    for (char i = 0; i < 26; ++i)
      if (mp[i].size() > 2 || mp[i].count(i)) goto NO;

    cout << "YES\n";
    continue;
  NO:;
    cout << "NO\n";
  }
  return 0;
}