#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
istream &fin = cin;
ostream &fout = cout;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n;
  cin >> n;
  vector<string> a(n);
  for (string &i : a) cin >> i;
  size_t i = 0;
  while (true) {
    vector<char> t;
    bool flag = false;
    for (string const &j : a)
      if (j.size() > i)
        flag = true, t.emplace_back(j[i]);
      else if (flag)
        t.emplace_back('*');
    if (flag == false) break;
    for_each(t.rbegin(), t.rend(), [](char c) { cout.put(c); });
    cout.put('\n');
    ++i;
  }
  return 0;
}