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
  s = '(' + s + ')';
  size_t const n = s.size();
  vector<size_t> a(n, ~0), b(n, ~0);
  {
    stack<size_t> t;
    for (size_t i = 0; i < n; ++i)
      if (s[i] == '(')
        t.push(i);
      else if (s[i] == ')')
        a[i] = t.top(), t.pop();
  }
  {
    stack<size_t> t;
    for (size_t i = n - 1; i < n; --i)
      if (s[i] == ')')
        t.push(i);
      else if (s[i] == '(')
        b[i] = t.top(), t.pop();
  }
  bool flag = false;
  for (size_t i = n - 1; i < n; flag ? ++i : --i) {
    if (s[i] == '(')
      if (flag)
        flag = false, i = b[i];
      else
        flag = true, i = b[i];
    else if (s[i] == ')')
      if (flag)
        flag = false, i = a[i];
      else
        flag = true, i = a[i];
    else
      cout.put(s[i] ^ ((!flag) * 32));
  }
  return 0;
}