#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void getLines(vector<string>& linesVec_, ifstream& inFile_)
{
	string line;
	while (getline(inFile_, line))
	{
		linesVec_.push_back(line);
	}
}

void printLines(vector<string>& linesVec_)
{
	for (int i = 0; i < linesVec_.size(); ++i)
	{
		cout << linesVec_[i] << "\n";
	}
}

int main(int argc, char* argv[])
{
	int fileCount = 1;
	if ((fileCount + 1) != argc)
	{
		cout << "Wrong argument\nUsage: " << argv[0] << " file\n";
		return 1;
	}
	
	vector<string> fileLines[fileCount];
	
	for(int i = 0; i < fileCount; i++) {
		ifstream inFile(argv[i + 1]);
		if (!inFile)
		{
			cout << "Cannot open input file " << argv[i + 1] << "\n";
			return 1;
		}
		
		vector<string> linesVec;
		getLines(linesVec, inFile);
		fileLines[i] = linesVec;
		
		inFile.close();
	}

	for(int i = 0; i < fileCount; i++) {
		cout << "Contents of file: " << argv[i + 1] << "\n";
		printLines(linesVec);
	}
		
	return 0;
}
