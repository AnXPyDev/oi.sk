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
  if (result.size() == 0) {result.push_back(input);};

	return result;
}

vector<int> notes({50000, 20000, 10000, 5000, 2000, 1000, 500, 200, 100, 50, 20, 10, 5, 2, 1});
vector<int> needed_ammounts;

int solve_ammount_greedy(int ammount, vector<int> notes) {
  int result = 0;

  for (auto it = notes.begin(); it < notes.end(); ++it) {
    if (ammount >= *it) {
      result += ammount / (*it);
      ammount -= (ammount / (*it)) * (*it);
    }
  }

  return result;
}

int solve_ammount_recursive(int ammount, vector<int> notes, int depth = 0, int* min_solution = NULL) {
  if (min_solution == NULL) {
    min_solution = new int(solve_ammount_greedy(ammount, notes));
  }

  cout << depth << "\n";

  if (*min_solution < depth + 2) {
    return *min_solution;
  }

  for (auto it = notes.begin(); it < notes.end(); ++it) {
    if (ammount - *it == 0) {
      *min_solution = depth + 1;
      break;
    } else if (ammount - *it > 0) {
      solve_ammount_recursive(ammount - *it, notes, depth + 1, min_solution);
    }
  }

  return *min_solution;
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

  vector<string> needed_ammounts_s = split(file[2], " ");
  for (auto it = needed_ammounts_s.begin(); it < needed_ammounts_s.end(); ++it) {
    needed_ammounts.push_back(stoi(*it));
  }

  int new_note = stoi(file[0]);
  for (auto it = notes.begin(); it < notes.end(); ++it) {
    if (*it < new_note) {
      notes.insert(it, new_note);
      break;
    }
  }

  for (auto it = needed_ammounts.begin(); it < needed_ammounts.end(); ++it) {
    cout << solve_ammount_recursive(*it, notes) << "\n";
  }
  
  return 0;
}
