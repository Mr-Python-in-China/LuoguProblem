#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t n, m;
  cin >> n;
  unordered_set<string> mp;
  // mp.reserve(n);
  while (n--) {
    string s;
    cin >> s;
    mp.insert(s);
  }
  size_t word_count = 0;
  cin >> m;
  vector<string> passage(m);
  {
    unordered_set<string> used;
    // mp.reserve(n);
    for (vector<string>::reference i : passage) {
      cin >> i;
      if (mp.count(i) && !used.count(i)) used.insert(i), word_count++;
    }
  }
  cout << word_count << '\n';
  size_t l = 0, r = m;
  while (l < r) {
    size_t mid = (l + r) >> 1;
    size_t maxc = 0;
    for (vector<string>::iterator it = passage.begin(), jt = it + mid - 1;
         jt < passage.end(); it++, jt++) {
      unordered_set<string> used;
      // used.reserve(n);
      size_t find_count = 0;
      for (vector<string>::iterator ptr = it; ptr <= jt; ptr++)
        if (mp.count(*ptr) && !used.count(*ptr))
          used.insert(*ptr), find_count++;
      maxc = max(maxc, find_count);
    }
    if (maxc >= word_count)
      r = mid;
    else
      l = mid + 1;
  }
  cout << l;
  return 0;
}