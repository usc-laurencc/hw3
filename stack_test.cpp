#include "stack.h"
#include <iostream>

using namespace std;

int main() {
  Stack<int> s;
  for (int i = 1; i < 6; i++) {
    s.push(i);
  }

  while (!s.empty()) {
    cout << "SIZE: " << s.size() << endl;
    cout << s.top() << endl;
    s.pop();
  }
}