#include <iostream>
#include <vector>
#include <string>
#include <cinttypes>

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

vector<uintmax_t> columns;

int main(int argc, char** argv) {
  vector<string> file;

  string line;
  for (int i = 0; i < 2; ++i) {
    getline(cin, line);
    file.push_back(string(line));
  }

  vector<string> columns_s = split(file[1], " ");
  for (auto it = columns_s.begin(); it < columns_s.end(); ++it) {
    uintmax_t column = stoll(*it);
    columns.push_back(column);
  }

  uintmax_t column_count = columns.size();
  

  uintmax_t rectangle_count = 0;
  uintmax_t max_area = 0;
  uintmax_t max_rectangle_count = 0;

  uintmax_t max = columns.size() * columns[0];

  for (uintmax_t x = 1; x <= column_count; ++x) {
    rectangle_count += columns[x - 1];
    uintmax_t area = x * columns[x - 1];
    if (area == max_area) {
      ++max_rectangle_count;
    } else if (area > max_area) {
      max_area = area;
      max_rectangle_count = 1;
    }
  }

  

  cout << rectangle_count << "\n" << max_rectangle_count << "\n" << max_area << "\n";
}  
