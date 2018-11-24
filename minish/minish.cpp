#include "pch.h"
#include "shFunction.h"

#define MAX_SIZE 256

using namespace std;

string getCurrentDir();
void cmd_parse(int*, char*[], string);
bool check_redirection(string);
bool check_pipe(string);

int main(int argc, char* argv[])
{
	signal(SIGINT, SIG_IGN);
    signal(SIGTERM, SIG_IGN);
    signal(SIGQUIT, SIG_IGN);
    signal(SIGTSTP, SIG_IGN);

	cout << "Minish version 1.0.0" << endl;
	cout << "copyrigrht@Jinwook Park" << endl;
	shFunction func;

    pid_t pid;

    string dir = getCurrentDir();
    string input;
    int* sh_argc = 0;
    char* sh_argv[MAX_SIZE];
	
	int flag = 1;
	while (flag)
	{
        cout << dir << "$" << " ";

	    getline(cin, input);
        if (input.length() == 0) { continue; }
	    cmd_parse(sh_argc, sh_argv, input);

	    if (strcmp(sh_argv[0], "ls") == 0) {
            char* ch_argv[MAX_SIZE];

	    	pid = fork();
            if (pid == 0)
            {
                execvp(ch_argv[0], &ch_argv[0]);
            }
            else
            {
                wait( (int *) 0);
            }
	    }
	    else if (input.compare("pwd") == 0) {
	    }
	    else if (input.compare("path") == 0) {
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

string getCurrentDir()
{
    char buff[FILENAME_MAX];
    getcwd(buff, FILENAME_MAX);
    string current_working_dir(buff);
    return current_working_dir;
}

void cmd_parse(int* argc, char* argv[], string str)
{
	vector<string> parsed;
	string separator = " ";

	size_t pos = 0;
	while ((pos = str.find(separator)) != string::npos)
	{
        cout << "argc: " << *argc << endl;
		string token = str.substr(0, pos);
        strcpy(argv[*argc], token.c_str());
		str.erase(0, pos + separator.length());
        *argc++;
	}
    strcpy(argv[*argc], str.c_str());
    *argc++;
}
