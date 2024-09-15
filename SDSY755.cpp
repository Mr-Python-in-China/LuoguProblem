#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
template <typename T> struct point {
  T x, y;
};
template <typename A, typename B> double dist(point<A> a, point<B> b) {
  return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
template <typename A, typename B> point<double> mid(point<A> a, point<B> b) {
  return {(a.x + b.x) / 2.0, (a.y + b.y) / 2.0};
}
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

  return 0;
}