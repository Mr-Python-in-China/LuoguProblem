#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
using uc = unsigned char;
enum class COLOR : uc { UNDEFINED = uc(~0), P0 = 0, P1 = 1 };
bool f(array<array<int, 3>, 3> const& board, array<array<COLOR, 3>, 3>& color,
       bool turn = false, li g0 = 0, li g1 = 0) {
  for (size_t i = 0; i < 3; ++i)
    if (color[i][0] != COLOR::UNDEFINED && color[i][0] == color[i][1] &&
        color[i][1] == color[i][2])
      return !turn;
  for (size_t i = 0; i < 3; ++i)
    if (color[0][i] != COLOR::UNDEFINED && color[0][i] == color[1][i] &&
        color[1][i] == color[2][i])
      return !turn;
  if (color[0][0] != COLOR::UNDEFINED && color[0][0] == color[1][1] &&
      color[1][1] == color[2][2])
    return !turn;
  if (color[0][2] != COLOR::UNDEFINED && color[0][2] == color[1][1] &&
      color[1][1] == color[2][0])
    return !turn;
  bool flag = true;
  for (size_t i = 0; i < 3; ++i)
    for (size_t j = 0; j < 3; ++j)
      if (color[i][j] == COLOR::UNDEFINED) {
        flag = false;
        color[i][j] = !turn ? COLOR::P0 : COLOR::P1;
        (!turn ? g0 : g1) += board[i][j];
        if (f(board, color, !turn, g0, g1) == turn) {
          color[i][j] = COLOR::UNDEFINED;
          return turn;
        }
        (!turn ? g0 : g1) -= board[i][j];
        color[i][j] = COLOR::UNDEFINED;
      }
  if (flag)
    return g0 < g1;
  else
    return !turn;
}
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  array<array<int, 3>, 3> board;
  for (array<int, 3>& i : board)
    for (int& j : i) cin >> j;
  array<array<COLOR, 3>, 3> c;
  c.fill({COLOR::UNDEFINED, COLOR::UNDEFINED, COLOR::UNDEFINED});
  cout << (f(board, c) ? "Aoki" : "Takahashi");
  return 0;
}