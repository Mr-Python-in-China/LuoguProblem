#include <iostream>

using namespace std;

int main() {
  int taskId;
  cin >> taskId;
  if (taskId == 1) {
    cout << "1000000000 999999999" <<endl;
  } else if (taskId == 2) {
    cout << "ac" << endl;
  } else { // 这个 else 不会被执行
    cout << "Stupid fentu!" << endl;
  }
}
