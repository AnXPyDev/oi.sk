#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> split(string input, string delimiter) {
	int dLen = delimiter.size();
	int lastFound = 0;
	int found = input.find(delimiter, lastFound);
	vector<string> result;
	while(found != string::npos) {
		found = input.find(delimiter, lastFound);
		result.push_back(input.substr(lastFound, found - lastFound));	
		lastFound = found + dLen;
	}

	return result;
}

vector<int> stones;

int main(int argc, char** argv) {
  vector<string> file;

  string line;
  for (int i = 0; i < 2; ++i) {
    getline(cin, line);
    file.push_back(string(line));
  }

  int min = 2000000000;

  vector<string> stones_s = split(file[1], " ");
  for (auto it = stones_s.begin(); it < stones_s.end(); ++it) {
    int stone = stoi(*it);
    stones.push_back(stone);
  }
  
  for (int i = 0; i < stones.size() - 1; ++i) {
    int max = stones[i] > stones[i + 1] ? stones[i] : stones[i + 1];
    if (min > max) {
      min = max;
    }
  }


  cout << min << "\n";
}
