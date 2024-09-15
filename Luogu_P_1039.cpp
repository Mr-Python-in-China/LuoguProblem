#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;
using ui = unsigned int;
using uli = unsigned long long int;
using li = long long int;
const regex IAM_RE(R"(^[A-Z]+: I am guilty\.$)"),
    SBIS_RE(R"(^[A-Z]+: [A-Z]+ is guilty.$)"),
    IAMNOT_RE(R"(^[A-Z]+: I am not guilty\.$)"),
    SBISNOT_RE(R"(^[A-Z]+: [A-Z]+ is not guilty\.$)"),
    TODAY_RE(
        R"(^[A-Z]+: Today is (Monday|Tuesday|Wednesday|Thursday|Friday|Saturday|Sunday)\.$)");
vector<string> split(string const& s, char c) {
  vector<string> res(1);
  for (char i : s)
    if (i == c)
      res.push_back("");
    else
      res.back() += i;
  return res;
}
struct said {
  enum class TYPE : unsigned char { IS, ISNOT, TODAY, UNDEFINED } type;
  string owner, value;
  said() = default;
  said(string const& s): type(TYPE::UNDEFINED) {
    vector<string> p = split(s, ' ');
    owner = string(p.front().begin(), p.front().end() - 1);
    if (regex_match(s, IAM_RE))
      type = TYPE::IS, value = owner;
    else if (regex_match(s, IAMNOT_RE))
      type = TYPE::ISNOT, value = owner;
    else if (regex_match(s, SBIS_RE))
      type = TYPE::IS, value = p[1];
    else if (regex_match(s, SBISNOT_RE))
      type = TYPE::ISNOT, value = p[1];
    else if (regex_match(s, TODAY_RE))
      type = TYPE::TODAY,
      value = string(p.back().cbegin(), p.back().cend() - 1);
  }
};
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  size_t m, n, p;
  cin >> m >> n >> p;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  vector<string> student(m);
  vector<said> ss(p);
  for (string& i : student)
    getline(cin, i), (i.back() == '\r' ? i.pop_back() : void());
  for (said& i : ss) {
    string s;
    getline(cin, s);
    (s.back() == '\r' ? s.pop_back() : void());
    i = said(s);
  }
  string sus;
  for (string const& guilty : student)
    for (char const* day : {"Monday", "Tuesday", "Wednesday", "Thursday",
                            "Friday", "Saturday", "Sunday"}) {
      unordered_set<string> truly, falsly;
      for (said const& st : ss) {
        if (st.type == said::TYPE::IS)
          (st.value == guilty ? truly : falsly).insert(st.owner);
        else if (st.type == said::TYPE::ISNOT)
          (st.value != guilty ? truly : falsly).insert(st.owner);
        else if (st.type == said::TYPE::TODAY)
          (st.value == day ? truly : falsly).insert(st.owner);
        if (truly.count(st.owner) && falsly.count(st.owner)) goto oops;
      }
      if (falsly.size() > n || truly.size() > m - n) goto oops;
      if (sus != "" && sus != guilty) cout << "Cannot Determine", exit(0);
      sus = guilty;
    oops:;
    }
  cout << (sus == "" ? "Impossible" : sus);
  return 0;
}