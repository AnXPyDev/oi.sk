#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<vector<int>*> stack;
  vector<int> ivec({0,0});
  
  stack.push_back(&ivec);
  
  for(int i = 0; i < 10; i++) {
    vector<int> last = *(stack.back());
    cout << last[0] << " " << last[1] << " ";
    last[0] ++;
    last[1] += 2;
    cout << last[0] << " " << last[1] << "\n";
  }
  return 0;
}
