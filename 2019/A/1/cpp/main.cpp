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

vector<int> steps;
vector<vector<int>> step_possibilities;
int step_count;
int max_height;
int counter;

int get_distance(int current_step, int target_step) {
  int distance = 0;
  for(int i = current_step; i < target_step + 1; i++) {
    distance += steps[i];
  }
  return distance;
}

vector<int> get_possible_steps(int current_step) {
  vector<int> result;
  int target_step = current_step;
  while (target_step < step_count && get_distance(current_step, target_step) <= max_height) {
    target_step ++;
    result.push_back(target_step);
    if (target_step > step_count) {
      break;
    }
  }
  return result;
}

void traverse_tree() {
  int last_idx = 0;
  vector<vector<int>*> stack;
  vector<int> firstv({0,0});
  stack.push_back(new vector<int>({0,0}));

  while(true) {

    if(stack.size() == 0) {
      break;
    }

    vector<int>& current = *(stack.back());

    int current_max = step_possibilities[current[0]].size();

    cout << current[0] << " " << current[1] << " " << counter << "\n";

    if (current[1] == current_max) {
      delete stack.back();
      stack.pop_back();
      continue;
    }

    if (step_possibilities[current[0]][current[1]] == step_count) {
      counter++;
      current[1]++;
    } else {
      stack.push_back(new vector<int>({step_possibilities[current[0]][current[1]++], 0}));
    }
    

  }
}

void count_solutions() {
  for(int i = 0; i < step_count; i++) {
    auto ps = get_possible_steps(i);
    step_possibilities.push_back(ps);
  }

  traverse_tree();

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
  for (int i = 0; i < steps_s.size(); i++) {
    steps.push_back(stoi(steps_s[i]));
  }

  vector<string> l1 = split(file[0], " ");

  max_height = stoi(l1[1]);
  step_count = steps.size();
  counter = 0;

  count_solutions();

  cout << "\nresult: " << counter % (1000000000 + 7) << "\n";

  return 0;
}
