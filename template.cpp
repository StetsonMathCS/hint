// Author: Joey Mathison
// This code, when run, opens up a temporary text file containing a template for the user to enter data, which, upon saving, creates a text file containing all the relevant data under the name entered by the user.
// This is NOT the most efficient way to do this, but for what we are doing, it works.

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
    pEnv = getenv("EDITOR"); // Gets the user's EDITOR environment variable so that the text file opens in their preferred editor, if they have one set

    fs::create_directory("temp"); // Creates a new directory to store the data entry text file
    fs::copy("helptemplate.txt", "temp/newhelp.txt"); // Copies the data entry template from helptemplate.txt to a new text file within the temporary directory

    // The ftime variables are used to compare the time of newhelp.txt's creation with the time it was last overwritten.
    // Process IDs could also be used for the same purpose as the ftimes, and would likely be more efficient, but the ftimes work as well.

    auto ftime = fs::last_write_time("temp/newhelp.txt");
    auto ftime2 = fs::last_write_time("temp/newhelp.txt");

    if(pEnv != NULL) // Checks if the user has an EDITOR variable set, and opens newhelp.txt in their default editor if they have an EDITOR variable set
    {
	system("xdg-open temp/newhelp.txt"); // Runs system command to open newhelp.txt in the user's default editor
    }
    else
    {
        system("nano temp/newhelp.txt"); // Opens newhelp.txt in nano if no EDITOR variable is set up
    }

    while(ftime == ftime2){ // Compares the ftime variables while this process is still running to see if newhelp.txt has been saved since creation
	ftime2 = fs::last_write_time("temp/newhelp.txt");
    }

    ifstream tempf("temp/newhelp.txt"); // Opens newhelp.txt in this process to get the hint name entered by the user
    if(tempf.is_open()){
	for(int i = 1; i <= 2; ++i){
	    getline(tempf, full_name_line); // Writes the "name" line from the text file to the full_name_line string for creation of the permanent text file
        }
    }
    tempf.close(); 

    new_help_file_name = full_name_line.substr(6) + ".txt"; // (Assumes space between colon and name entered) takes just the name from full_name_line

    fs::copy("temp/newhelp.txt", new_help_file_name); // Copies the data entered by the user to a new file in the main directory under the name entered by the user
    fs::remove_all("temp"); // Deletes the temporary directory and everything contained within (newhelp.txt)
}
