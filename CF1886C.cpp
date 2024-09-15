#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  uli T;
  cin >> T;
  while (T--) {
    list<char> s;
    uli p;
    {
      char c;
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      while (isalpha(c = cin.get())) s.push_back(c);
    }
    cin >> p;
    --p;
    uli t = s.size();
    for (; p >= t; p -= (t--));
    uli del = s.size() - t;
    for (list<char>::iterator it = next(s.begin()); it != s.end() && del; ++it)
      if (*prev(it) > *it) s.remove(*prev(it)), --del;
    while (del) s.pop_back(), --del;
    list<char>::const_iterator output = s.cbegin();
    advance(output, p);
    cout.put(*output);
  }
  return 0;
}