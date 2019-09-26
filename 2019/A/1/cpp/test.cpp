#include <iostream>
#include <vector>

using namespace std;

int x;

int main() {
  vector<vector<int>*> stack;
  stack.push_back(new vector<int>({0,0}));
  cout << &stack << "\n" << stack.back();

  for(int i = 0; i < 100; i++) {
    if(stack.size() == 0) {
      break;
    }

    vector<int>& current = *(stack.back());

    cout << current[0] << " " << current[1] << "\n";

    stack.push_back(new vector<int>({i, i}));
  }
}
