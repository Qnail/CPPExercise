#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//read file word by word
void readFileWBW(string fileName){
	ifstream fin(fileName);
	string word;
	while (fin >> word){
		cout << "Read from file: " << word << endl;
	}
}

//read file line by line 
void readFileLBLIntoCharArray(string fileName){
	ifstream fin(fileName);
	const int LINE_LENGTH = 100;
	char str[LINE_LENGTH];
	while (fin.getline(str, LINE_LENGTH)){
		cout << "" << str << endl;
	}
}

//read file line by line special
void readFileLBLIntoCharArray_sp(string fileName){
	ifstream fin(fileName);
	const int LINE_LENGTH = 1000;
	char str[LINE_LENGTH];
	fin.getline(str, LINE_LENGTH);
	cout << str << endl;
}

//read file with error checking
void readFileWithErrorChecking(string fileName){
	ifstream fin(fileName.c_str());
	if (!fin){
		cout << "Error opening" << fileName << " for input" << endl;
		exit(-1);
	}
}

int main()
{
	readFileLBLIntoCharArray_sp("H:\\test.txt");
}