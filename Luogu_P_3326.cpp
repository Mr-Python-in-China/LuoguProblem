#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
struct cube {
  char color[3][4];
  static char constexpr shape[] =
      "       +-------+\n"
      "      /Y\YYYY'/|\n"
      "     /YY.*'YY/G|\n"
      "    /.YYYY\Y/G/|\n"
      "   +-------+G.G|\n"
      "   |\GGGGG/|\:G|\n"
      "   |G\GGG/G|G*G|\n"
      "   |GG\G/GG|G:\|\n";
  | GGGXGGG | G'G+-------+ | GG / G\GG | / G / G\YYYY'/| | G / GGG\G |
      G / GG.*'YY/G| | / GGGGG\| /.GGGG\Y / G / | +-- -- -- -+-- -- -- -+G.G |
};
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

  return 0;
}