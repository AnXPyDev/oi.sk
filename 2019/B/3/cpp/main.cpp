#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> split_string(string str, string delimiter) {
  vector<string> result;

  size_t delimiter_len = delimiter.size();
  size_t last_found = -delimiter_len;

  while(true) {
    size_t current_found = str.find(delimiter, last_found + delimiter_len);

    if (current_found == string::npos) {
      result.push_back(str.substr(last_found + delimiter_len, str.size() - last_found - 1));
      break;
    } else {
      result.push_back(str.substr(last_found + delimiter_len, current_found - last_found - 1));
      last_found = current_found;
    };
  };
  
  return result;
};

struct Room {
  Room();
  vector<Room*> connections;
};
  
struct Level {
  Level();
  vector<Room*> rooms;
};

struct {
  Level* level;
  Room* room;
} pos;

int main(int argc, char** argv) {

  int level_count; {
    string s; getline(cin, s);
    level_count = stoi(s);
  };

  cout << "level_count " << level_count << endl;

  vector<Level*> levels; {
    string line;
    for (int n = 0; n < level_count; ++n) {
      vector<int> current_level;
      getline(cin, line);
      vector<string> splits = split_string(line, " ");
      cout << "level " << n << ": ";
      for (auto it = splits.begin(); it < splits.end(); ++it) {
        cout << *it << " ";
        current_level.push_back(stoi(*it));
      };
      cout << endl;
      levels.push_back(current_level);
    };
  };

  {
    string line; getline(cin, line);
    vector<string> splits = split_string(line, " ");
    pos.level = levels[stoi(splits[0])];
    pos.room = levels[pos.level]->connections[stoi(splits[1])];
  };

  cout << "level " << pos.level << endl;
  cout << "room " << pos.room << endl;

  // up (H) = false, down (D) = true;
  vector<bool> directions; {
    string line; getline(cin, line);
    for (int i = 0; i < line.size(); ++i) {
      cout << line[i];
    };
  };

  cout << endl;

  return 0;
  
}
