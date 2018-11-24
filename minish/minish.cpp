#include "pch.h"
#include "shFunction.h"

using namespace std;
namespace fs = experimental::filesystem;

vector<string> cmd_parse(string);

int main(int argc, char argv[])
{
	signal(SIGINT, SIG_IGN);
	cout << "Minish version 1.0.0" << endl;
	cout << "copyrigrht@Jinwook Park" << endl;
	shFunction func;
	
	int flag = 1;
	while (flag)
	{
		string input;
		vector<string> parsed_input;
		fs::path cpath = fs::current_path();

		cout << cpath << "$" << " ";

		getline(cin, input); 
		parsed_input = cmd_parse(input);

		cout << parsed_input.at(0) << endl;

		if (input.compare("cd") == 0) {
			cout << "You try to cd." << endl;
		}
		else if (input.compare("pwd") == 0) {
			func.pwd();
		}
		else if (input.compare("path") == 0) {
			func.redirection();
		}
		/*else if (parsed_input.at(0).compare("parse") == 0)
		{
			for (auto str : parsed_input)
			{
				cout << str;
			}
		}*/
		else if (input.compare("quit") == 0) {
			flag = 0;
		}
		else {
			cout << input << endl;
		}
	}

	return 0;
}

vector<string> cmd_parse(string str)
{
	vector<string> parsed;
	string separator = " ";

	size_t pos = 0;
	while ((pos = str.find(separator)) != string::npos)
	{
		string token = str.substr(0, pos);
		parsed.push_back(token);
		str.erase(0, pos + separator.length());
	}
	parsed.push_back(str);

	return parsed;
}