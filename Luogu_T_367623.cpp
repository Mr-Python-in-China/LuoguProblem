#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using uli = unsigned long long int;
struct inst {
  uli l, r;
};
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t op, q;
  cin >> op >> q;
  deque<inst> realq;  // 实际存储区间的队列
  deque<uli> upperq;  // 单调队列，用于求最大值
  deque<uli> sum(1);  // 用于二分求元素下标的队列
  while (q--) {
    char op;
    cin >> op;
    switch (op) {
      case '1': {
        uli x;
        cin >> x;
        realq.push_back({1, x});
        sum.push_back(sum.back() + x);
        while (!upperq.empty() && upperq.back() < x) upperq.pop_back();
        upperq.push_back(x);
        break;
      }
      case '2': {
        size_t y;
        cin >> y;
        while (realq.front().r - realq.front().l + 1 <= y) {
          y -= realq.front().r - realq.front().l + 1;
          if (upperq.front() == realq.front().r) upperq.pop_front();
          realq.pop_front();
          sum.pop_front();
        }
        if (!realq.empty()) realq.front().l += y;
        sum.front() += y;
        break;
      }
      case '3': {
        size_t z;
        cin >> z;
        --z;
        deque<uli>::const_iterator it =
            prev(upper_bound(sum.cbegin(), sum.cend(), z + sum.front()));
        if (it == sum.cbegin())
          cout << realq.front().l + z << '\n';
        else
          cout << z + sum.front() - *it + 1 << '\n';
        break;
      }
      case '4': cout << upperq.front() << '\n';
    }
#ifdef debug
    cout << flush;
#endif
  }
  return 0;
}