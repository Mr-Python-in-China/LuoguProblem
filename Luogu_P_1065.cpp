#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
using usi = unsigned short int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  usi m, n;
  cin >> m >> n;
  vector<pair<usi, usi>> qwq(n * m);
  {
    vector<usi> cnt(n);
    for (vector<pair<usi, usi>>::reference i : qwq)
      cin >> i.first, i.first--, i.second = cnt[i.first]++;
  }

  return 0;
}