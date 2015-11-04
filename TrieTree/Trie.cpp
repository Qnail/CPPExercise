#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main()
{
	vector<string> files;
	string s;
	string sval;

	for(int i = 1;i<3;++i)
	{
		cin>>sval;
		files.push_back(sval);
	}

	vector<string>::const_iterator it = files.begin();
	ifstream input;
	while(it != files.end())
	{
		input.open(it->c_str());
		if(!input)
		{
			cerr<<"error"<<*it<<"error-end"<<endl;
			input.clear();
			++it;
		}else{
			cout<<"else"<<endl;
			input>>s;
			while(input>>s)
			{
				cout<<"ok"<<endl;
			}
			input.close();
			input.clear();
			++it;sfd
		}
	}
}