#include <iostream>

using namespace std;

int main(int argc, char** argv) {
  srand(time(NULL));

  int n = stoi(argv[1]);
  int d = stoi(argv[2]);

  cout << n << " " << d << "\n";

  for(int i = 0; i < n; i++) {
    cout << rand() % d + 1;

    if (i < n - 1) {
      cout << " ";
    }
  }
  return 0;
}
