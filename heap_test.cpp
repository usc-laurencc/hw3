#include "heap.h"
#include <iostream>

using namespace std;

struct Great {
  bool operator()(int val1, int val2) { return val1 > val2; }
};

int main() {
  Great greater;
  Heap<int> h(3);
  for (int i = 0; i < 5; i++) {
    h.push(5*i);
    cout << "PUSHED: " << 5*i << endl;
  }

  cout << "TOP: " << h.top() << endl;
  h.pop();
  cout << "TOP: " << h.top() << endl;
  h.pop();
  cout << "TOP: " << h.top() << endl;
  h.pop();
  cout << "TOP: " << h.top() << endl;
  h.pop();
  cout << "TOP: " << h.top() << endl;
}