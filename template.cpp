#include <fstream>
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <cstdio>
#include <cstdlib>
#include <boost/filesystem.hpp>

namespace fs = boost::filesystem;

using namespace std;

int main()
{
    string new_help_file_name, full_name_line;
    char* pEnv;
    pEnv = getenv("EDITOR");

    fs::create_directory("temp");
    fs::copy("helptemplate.txt", "temp/newhelp.txt");

    auto ftime = fs::last_write_time("temp/newhelp.txt");
    auto ftime2 = fs::last_write_time("temp/newhelp.txt");

    if(pEnv != NULL)
    {
	system("xdg-open temp/newhelp.txt");
    }
    else
    {
        system("nano temp/newhelp.txt");
    }

    while(ftime == ftime2){
	ftime2 = fs::last_write_time("temp/newhelp.txt");
    }

    ifstream tempf("temp/newhelp.txt");
    if(tempf.is_open()){
	for(int i = 1; i <= 2; ++i){
	    getline(tempf, full_name_line);
        }
    }
    tempf.close();

    new_help_file_name = full_name_line.substr(6) + ".txt";

    fs::copy("temp/newhelp.txt", new_help_file_name);
    fs::remove_all("temp");
}
