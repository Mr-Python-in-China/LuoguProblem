#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
istream& fin = cin;
ostream& fout = cout;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  char ab, ac, bc;
  fin >> ab >> ac >> bc;
  array<char, 3> a = {'A', 'B', 'C'};
  if (ab == '<' && ac == '<' && bc == '<') fout << 'B';
  if (ab == '<' && ac == '<' && bc == '>') fout << 'C';
  if (ab == '>' && ac == '<' && bc == '<') fout << 'A';
  if (ab == '<' && ac == '>' && bc == '>') fout << 'A';
  if (ab == '>' && ac == '>' && bc == '<') fout << 'C';
  if (ab == '>' && ac == '>' && bc == '>') fout << 'B';
  return 0;
}