#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
const size_t K = 20;
unsigned long long int C[K][K];
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  for (size_t i = 1; i < K; i++) C[i][1] = C[i][i] = 1;
  for (size_t i = 3; i < K; i++)
    for (size_t j = 2; j < i; j++) C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
  size_t T;
  cin >> T;
  while (T--) {
    size_t n, k;
    cin >> n >> k;
    size_t cnt = 0;
    for (size_t i = 2; i * i <= n; i++) {
      cnt += n % i == 0;
      while (n % i == 0) n /= i;
    }
    if (n != 1) cnt++, n = 1;
    if (k > cnt)
      cout << '0' << '\n';
    else
      cout << C[cnt][k] << '\n';
  }
  return 0;
}