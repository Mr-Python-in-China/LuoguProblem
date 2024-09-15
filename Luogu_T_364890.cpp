#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned long long int;
using uli = unsigned long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t T;
  cin >> T;
  while (T--) {
    size_t n;
    string k;
    cin >> n >> k;
    bool of2 = false, of11 = false, of14 = false, of22 = false, of77 = false,
         of154 = false, of3 = false, of147 = false, of49 = false, of7a = false,
         of7b = false;
    size_t of21 = 0;
    uli sum = 0;
    for (size_t i = 0; i < n; i++) {
      ui x;
      cin >> x;
      if (x % 154 == 0)
        of154 = true;
      else if (x % 77 == 0)
        of77 = true;
      else if (x % 22 == 0)
        of22 = true;
      else if (x % 14 == 0)
        of14 = true;
      else if (x % 2 == 0)
        of2 = true;
      else if (x % 7 == 0)
        of7a = true;
      else if (x % 11 == 0)
        of11 = true;
      if (x % 147 == 0)
        of147 = true;
      else if (x % 21 == 0)
        of21++;
      else if (x % 49 == 0)
        of49 = true;
      else if (x % 3 == 0)
        of3 = true;
      else if (x % 7 == 0)
        of7b = true;
      sum += x;
    }
    if (n != 1 &&
        (of154 || (of14 && (of11 || of22 || of77)) ||
         (of22 && (of7a || of14 || of77)) || (of77 && (of2 || of14 || of22)) ||
         of147 || (of21 && (of7b || of49)) || (of49 && (of3 || of21)) ||
         of21 >= 2))
      cout << "Yes\n";
    else if (k.size() > 17)
      cout << "No\n";
    else {
      char const* tmp = k.c_str();
      uli ulk = strtoull(tmp, nullptr, 10);
      if (sum >= ulk)
        cout << "Yes\n";
      else
        cout << "No\n";
    }
  }
  return 0;
}