#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <list>
#include <array>

using namespace std;

vector<string> split(string input, string delimiter)
{
	int dLen = delimiter.size();
	int lastFound = 0;
	int found = input.find(delimiter, lastFound);
	vector<string> result;
	while(found != string::npos) 
	{
		found = input.find(delimiter, lastFound);
		result.push_back(input.substr(lastFound, found - lastFound));	
		lastFound = found + dLen;
	}
	

	return result;
}

int main(int argc, char** argv)
{
	vector<string> file;
	ifstream infile;
	
	string fn2(argv[1]);
	string fn1("./input/");

	infile.open(fn1 + fn2);
	while(!infile.eof())
	{
		string LINE;
		getline(infile, LINE);
		file.push_back(LINE);
	}
	
	int line0[2] = {};
	vector<string> tm_ln0 = split(file[0], " ");	

	for(int i = 0; i < tm_ln0.size(); i++)
	{
		line0[i] = stoi(tm_ln0[i]);
	}

	vector<array<int,2>> shirts;

	vector<string> tm_ln1 = split(file[1], " ");

	for(int e = 0; e < tm_ln1.size(); e++)
	{
		array<int, 2> t = {e+1, stoi(tm_ln1[e])};
		shirts.push_back(t);
	}

	for(int f = 2; f < line0[1] + 2; f++)
	{
		if(file[f] == "L")
		{
			int minIx = shirts.size() -1;
			int min = shirts[minIx][1];
			for(int x = shirts.size() - 1; x > -1; x--)
			{
				if(shirts[x][1] <= min)
				{
					minIx = x;
					min = shirts[x][1];
				}
			}
			shirts.insert(shirts.begin(), shirts[minIx]);
			shirts.erase(shirts.begin() + minIx + 1);
		}
		shirts[0][1] += 1;
		cout << shirts[0][0] << " " << (float)(f - 1) / (float)line0[1] << '\n';


	}



}
