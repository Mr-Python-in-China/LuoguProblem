#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
uli reverseNumber(uli x) {
  string s = to_string(x);
  reverse(s.begin(), s.end());
  return stoull(s);
}
const auto ReverseTimes = [] {
  array<uli, size_t(1e6 + 1)> a;
  for (uli i = 0; i < a.size(); ++i) a[i] = i * reverseNumber(i);
  return a;
}();
bool checkNumber(uli x) {
  string s = to_string(x);
  return equal(s.begin(), s.end(), s.rbegin()) &&
         find(s.begin(), s.end(), '0') == s.end();
  ;
}
vector<uli> stk;
void dfs(const vector<uli>::const_iterator beg,
         const vector<uli>::const_iterator end, const uli x) {
  if (beg == end)
    if (checkNumber(x)) {
      for_each(stk.begin(), stk.end(), [](uli i) { cout << i << '*'; });
      cout << x;
      for_each(stk.rbegin(), stk.rend(),
               [](uli i) { cout << '*' << reverseNumber(i); });
      exit(0);
    } else
      return;
  dfs(next(beg), end, x);
  if (x % ReverseTimes[*beg]) return;
  stk.push_back(*beg);
  dfs(beg, end, x / ReverseTimes[*beg]);
  stk.pop_back();
}
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  uli x;
  cin >> x;
  vector<uli> lst;
  for (uli i = 2; i < ReverseTimes.size(); ++i)
    if (x % ReverseTimes[i] == 0 && [i] {
          const string s = to_string(i);
          return find(s.begin(), s.end(), '0') == s.end();
        }())
      lst.emplace_back(i);
  dfs(lst.begin(), lst.end(), x);
  cout << "-1";
  return 0;
}