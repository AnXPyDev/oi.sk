#include <iostream>
#include <fstream>
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

int get_distance(vector<int> steps, int current_step, int target_step) {
  int distance = 0;
  for(int i = current_step; i < target_step; i++) {
    distance += steps[i];
  }
  return distance;
}

void count_solutions(int* counter, vector<int> steps, int max_height, int current_step = 0) {
  int step_count = steps.size();
  int target_step = current_step + 1;

  if (current_step == step_count) {
    (*counter) ++;
    return;
  }

  while (get_distance(steps, current_step, target_step) <= max_height) {
    count_solutions(counter, steps, max_height, target_step);
    target_step ++;
    if (target_step > step_count) {
      break;
    }
  }
}

int main(int argc, char** argv) {
  vector<string> file;
  ifstream input_file;
  
  input_file.open(argv[1]);

  while(!input_file.eof()) {
    string LINE;
    getline(input_file, LINE);
    file.push_back(LINE);
  }

  vector<string> steps_s = split(file[1], " ");
  vector<int> steps;
  for (int i = 0; i < steps_s.size(); i++) {
    steps.push_back(stoi(steps_s[i]));
  }

  vector<string> l1 = split(file[0], " ");
  int max_height = stoi(l1[1]);

  int solution_count = 0;

  count_solutions(&solution_count, steps, max_height);

  cout << solution_count % (1000000000 + 7) << "\n";

  return 0;
}
