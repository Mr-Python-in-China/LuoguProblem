#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
template <typename IT> size_t check_neq(IT beg1, IT end1, IT beg2) {
  size_t ans = 0;
  for (; beg1 != end1; ++beg1, ++beg2)
    if (*beg1 != *beg2) ++ans;
  return ans;
}
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t T;
  cin >> T;
  while (T--) {
    size_t n;
    string s;
    cin >> n >> s;
    for (size_t i = 1; i <= n / 3; ++i)
      if (n % i == 0) {
        int flag = 0;
        bool t = 0;
        for (string::iterator ht = s.begin(), it = ht + i, jt = it + i;
             jt < s.end(); ht += i, it += i, jt += i) {
          size_t x = check_neq(ht, it, it), y = check_neq(it, jt, jt);
          if (x == 0 && y == 0)
            ;
          else if (x > 1 || y > 1)
            goto failed;
          else if (x == 1 && y == 1) {
            if (t || !equal(ht, it, jt))
              goto failed;
            else
              t = true;
          } else if (flag == 2)
            goto failed;
          else if (x == 1) {
            if (flag == 0)
              flag = -1;
            else if (flag == -1)
              goto failed;
            else
              flag = 2;
          } else if (y == 1) {
            if (flag == 0)
              flag = 1;
            else if (flag == 1)
              goto failed;
            else
              flag = 2;
          }
        }
        {
          string::iterator ht = s.end() - i - i, it = ht + i, jt = s.begin();
          size_t x = check_neq(ht, it, it), y = check_neq(it, s.end(), jt);
          if (x == 0 && y == 0)
            ;
          else if (x > 1 || y > 1)
            goto failed;
          else if (x == 1 && y == 1) {
            if (t || !equal(ht, it, jt))
              goto failed;
            else
              t = true;
          } else if (flag == 2)
            goto failed;
          else if (x == 1) {
            if (flag == 0)
              flag = -1;
            else if (flag == -1)
              goto failed;
            else
              flag = 2;
          } else if (y == 1) {
            if (flag == 0)
              flag = 1;
            else if (flag == 1)
              goto failed;
            else
              flag = 2;
          }
        }
        {
          string::iterator ht = s.end() - i, it = s.begin(), jt = it + i;
          size_t x = check_neq(ht, s.end(), it), y = check_neq(it, jt, jt);
          if (x == 0 && y == 0)
            ;
          else if (x > 1 || y > 1)
            goto failed;
          else if (x == 1 && y == 1) {
            if (t || !equal(ht, s.end(), jt))
              goto failed;
            else
              t = true;
          } else if (flag == 2)
            goto failed;
          else if (x == 1) {
            if (flag == 0)
              flag = -1;
            else if (flag == -1)
              goto failed;
            else
              flag = 2;
          } else if (y == 1) {
            if (flag == 0)
              flag = 1;
            else if (flag == 1)
              goto failed;
            else
              flag = 2;
          }
        }
        cout << i << '\n';
        goto successful;
      failed:;
      }
    if (n % 2 == 0 && check_neq(s.begin(), s.begin() + s.size() / 2,
                                s.begin() + s.size() / 2) <= 1)
      cout << n / 2 << '\n';
    else
      cout << n << '\n';
  successful:;
  }
  return 0;
}