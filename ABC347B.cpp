#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  string s;
  cin >> s;
  unordered_set<string> t;
  for (string::const_iterator it = s.cbegin(); it < s.cend(); ++it)
    for (string::const_iterator jt = it; jt < s.cend(); ++jt)
      t.insert(string(it, next(jt)));
  cout << t.size();
  return 0;
}