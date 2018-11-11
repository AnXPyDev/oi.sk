#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

struct Word {
	char border[2];
};

vector<char> alphabet = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

int posInAlphabet(char c) {
	for(int i = 0; alphabet.size(); i++) {
		if(alphabet[i] == c) {
			return i;
		}
	}
	return 0;
}

int maximums[27] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};

vector<Word> words;

Word newWord(string value, int index) {
	Word result;
	result.border[0] = value[0];
	result.border[1] = value[value.length() - 1];
	return result;
}

int GetBestSuccession(int index) {	
	int max = maximums[posInAlphabet(words[index].border[1])] + 1;
	if(max > maximums[posInAlphabet(words[index].border[0])]) {
		maximums[posInAlphabet(words[index].border[0])] = max;
	}
	return max;
}

int main(int argc, char** argv) {
	ifstream infile;
	string fn2(argv[1]);
	string fn1("./input/");

	infile.open(fn1 + fn2);
	int i = -1;
	while(!infile.eof()) {
		string LINE;
		getline(infile, LINE);
		if(i > -1) {
			words.push_back(newWord(LINE, i - 1));
		}
		i++;
	}
	
	int max = 0;

	for(int e = words.size() - 1; e > -1; e--) {
		int currentMax = GetBestSuccession(e);
		if(currentMax > max) {
			max = currentMax;
		}
	}

	cout << max - 1 << '\n';
	

	

}
