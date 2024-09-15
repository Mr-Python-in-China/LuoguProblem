#include <bits/extc++.h>
using namespace std;
namespace pbds = __gnu_pbds;

using Shift = long long int;
// 指令
struct Instruction {
  // 指令集
  enum ISC {
    OUT,  // 输出
    MOV,  // 赋值
    JMP,  // 跳转
    JIN,  // 条件转移
    ADD,  // 加法
    SUB   // 减法
  } isc;
  struct Value {
    enum TYPE { CONST, SHIFT } type;
    union val {
      int con;
      Shift sft;
    };
  };
  struct Output {
    Value v;
  };
  struct Move {
    Value from;
    Shift to;
  };
  struct Jump {
    vector<Instruction>::const_iterator jp;
  };
  struct JumpIfNot {
    vector<Instruction>::const_iterator jp;
  };
  struct Add {
    Value num;
  };
  struct Sub {
    Value sub;
  };
  union Parm {
    Output out;
    Move mov;
    Jump jmp;
    JumpIfNot jin;
    Add add;
    Sub sub;
  };
};
vector<Instruction> exe;
namespace compile {
unordered_map<string, Shift> vars;
Shift stack = 0;
bool is_block_end(string const& s) {
  return regex_match(s.c_str(), regex(R"(\s*\}\s*)"));
}
bool is_varblock(string const& s) {
  return regex_match(s.c_str(), regex(R"(\s*\{\s*vars\s*)"));
}
bool is_yosoro(string const& s) {
  return regex_match(s.c_str(), regex(R"(\s*\:yosoro\s.*)"));
}
vector<string>::const_iterator varblock(vector<string>::const_iterator beg) {
  for (; !is_block_end(*beg); beg++) {
    string::const_iterator st = beg->cbegin();
    string varname, vartype;
    while (st < beg->cend() && !isalpha(*st)) ++st;
    while (st < beg->cend() && isalpha(*st)) varname += *(st++);
    while (st < beg->cend() && !isalpha(*st)) ++st;
    while (st < beg->cend() && isalpha(*st)) vartype += *(st++);
    if (vartype == "int") {
      vars[varname] = stack;
      ++stack;
    } else if (vartype == "array") {
      while (st < beg->cend() && !isalpha(*st)) ++st;
      string arrtype;
      while (st < beg->cend() && isalpha(*st)) arrtype += *(st++);
      if (arrtype == "int") {
        Shift ls = 0, rs = 0;
        while (st < beg->cend() && !isdigit(*st)) ++st;
        while (st < beg->cend() && isdigit(*st)) ls = ls * 10 + *(st++) - '0';
        while (st < beg->cend() && !isdigit(*st)) ++st;
        while (st < beg->cend() && isdigit(*st)) rs = rs * 10 + *(st++) - '0';
        Shift sz = rs - ls + 1;
        vars[varname] = stack - ls;
        stack += sz;
      } else
        cerr << "TypeError: Uknown type " << vartype << " of " << varname,
            exit(1);
    } else
      cerr << "TypeError: Uknown type " << vartype << " of " << varname,
          exit(1);
  }
  return beg;
}
vector<string>::const_iterator yosoro(vector<string>::const_iterator beg) {
  string::const_iterator expstart = beg->cbegin() + beg->find(' ');

  return beg;
}
vector<string>::const_iterator block(vector<string>::const_iterator beg) {
  for (; !is_block_end(*beg); beg++) {
    if (is_varblock(*beg)) beg = varblock(next(beg));
  }
  return beg;
}
};  // namespace compile
int main(void) {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  vector<string> code;
  while (code.push_back(""), getline(cin, code.back()));
  code.push_back("}");
  compile::block(code.cbegin());
  return 0;
}