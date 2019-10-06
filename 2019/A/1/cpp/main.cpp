
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


int max_step_height;
int step_count;
long counter;
int overflow;


struct Step {
  int height;
  int index;
  bool is_solved;
  long long int solution_count;
  vector<Step*> reachable;
  bool is_end;
  
  Step(int index, int height) {
    this->index = index;
    this->height = height;
    this->is_solved = false;
    this->solution_count = 0;
    this->is_end = false;
  };

  void get_reachable();
  long long int get_solution_count();
  void identify();
  
};

vector<Step*> steps;

void Step::get_reachable() {
  //this->identify();
  if(this->index == step_count - 1) {
    //cout << "is the last one\n";
    this->is_end = true;
  } else {
    //cout << "found reachable steps: ";
    int height = 0;
    for(int i = this->index; i < step_count; i++) {
      if (steps[i]->height + height <= max_step_height && i + 1 < step_count) {
        //cout << i + 1 << ", ";
        this->reachable.push_back(steps[i + 1]);
        height += steps[i]->height;
      } else {
        break;
      }
    }
    //cout << "\n";
  }
}

long long int Step::get_solution_count() {
  //this->identify(); cout << "getting solution count\n";
  if(!this->is_solved) {
    for(int i = 0; i < this->reachable.size(); i++) {
      if(this->reachable[i]->is_end) {
        this->solution_count++;
      } else {
        this->solution_count += this->reachable[i]->get_solution_count();
      }
    }
    this->is_solved = true;
  }
  //this->identify(); cout << "returning " << this->solution_count << "\n";
  return this->solution_count % overflow;
}

void Step::identify() {
  cout << "Step " << this->index << " (" << this->height << ", " << (this->is_solved ? "solved" : "not solved") << ", " << (this->is_end ? "last" : "not last") << ") ";
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
    steps.push_back(new Step(i, stoi(steps_s[i])));
  }
  steps.push_back(new Step(steps.size(), 0));
  
  vector<string> l1 = split(file[0], " ");

  overflow = 1000000007;

  max_step_height = stoi(l1[1]);
  step_count = steps.size();
  counter = 0;

  for (int i = 0; i < steps.size(); i++) {
    steps[i]->get_reachable();
  }

  cout << steps[0]->get_solution_count() << "\n";


  return 0;
}
