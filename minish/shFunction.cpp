#include "pch.h"
#include "shFunction.h"

namespace fs = experimental::filesystem;

void shFunction::pwd()
{
	fs::path cpath = fs::current_path();
	cout << cpath << endl;
}

void shFunction::redirection()
{
	string pst = "C:\\Windows\\Sys";
	fs::path path(pst);
	cout << path << endl;
}