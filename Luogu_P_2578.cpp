#include <bits/stdc++.h>
using namespace std;
struct board {
  array<array<unsigned char, 3>, 3> arr;
  friend istream& operator>>(istream& in, board& b) {
    for (array<unsigned char, 3>& i : b.arr)
      for (unsigned char& j : i) in >> j, j -= '0';
    return in;
  }
  friend ostream& operator<<(ostream& out, const board& b) {
    for (array<unsigned char, 3> const& i : b.arr) {
      for (unsigned char const& j : i) out.put(j + '0'), out.put(' ');
      out.put('\n');
    }
    return out;
  }
  board(board const& x, bool op) {
    *this = x;
    if (op) {
      unsigned char tmp = arr[0][0];
      arr[0][0] = arr[1][0], arr[1][0] = arr[2][0], arr[2][0] = arr[2][1],
      arr[2][1] = arr[2][2], arr[2][2] = arr[1][2], arr[1][2] = arr[0][2],
      arr[0][2] = arr[0][1], arr[0][1] = tmp;
    } else {
      unsigned char tmp = arr[1][0];
      arr[1][0] = arr[1][2], arr[1][2] = arr[1][1], arr[1][1] = tmp;
    }
  }
  board(void) {
    for (size_t i = 0; i < 3; i++)
      for (size_t j = 0; j < 3; j++) arr[i][j] = i * 3 + j;
  }
  inline friend bool operator==(const board& a, const board& b) {
    return a.arr[0][0] == b.arr[0][0] && a.arr[0][1] == b.arr[0][1] &&
           a.arr[0][2] == b.arr[0][2] && a.arr[1][0] == b.arr[1][0] &&
           a.arr[1][1] == b.arr[1][1] && a.arr[1][2] == b.arr[1][2] &&
           a.arr[2][0] == b.arr[2][0] && a.arr[2][1] == b.arr[2][1] &&
           a.arr[2][2] == b.arr[2][2];
  }
  inline friend bool operator!=(const board& a, const board& b) {
    return !(a == b);
  }
  const static board Target;
};
const board board::Target;
namespace std {
template <> struct hash<board> {
  size_t operator()(board const& b) const {
    return (b.arr[0][0] << 0) + (b.arr[0][1] << 2) + (b.arr[0][2] << 4) +
           (b.arr[1][0] << 6) + (b.arr[1][1] << 8) + (b.arr[1][2] << 10) +
           (b.arr[2][0] << 12) + (b.arr[2][1] << 14) + (b.arr[2][2] << 16);
  }
};
}  // namespace std
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  board bd;
  cin >> bd;
  unordered_map<board, board> from;
  from.reserve(362880 << 5);
  from[bd] = board();
  queue<board> q({bd});
  while (!q.empty()) {
    board p = q.front();
    q.pop();
    if (p == board::Target) {
      vector<board> ans;
      do ans.push_back(p), p = from[p];
      while (p != board::Target);
      cout << ans.size() - 1 << '\n';
      for (vector<board>::const_reverse_iterator it = ans.crbegin();
           it != ans.crend(); it++)
        cout << *it << '\n';
      return 0;
    }
    for (char i = 0; i < 2; i++) {
      board np(p, i);
      if (!from.count(np)) from[np] = p, q.push(np);
    }
  }
  cout << "UNSOLVABLE";
  return 0;
}