#include <bits/stdc++.h>
using namespace std;
using uli = unsigned long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  uli a, b;
  cin >> a >> b;
  cout << uli(ceil((a - b) / 100.0));
  return 0;
}