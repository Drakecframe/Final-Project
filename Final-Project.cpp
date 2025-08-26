/* ---------------------------------------------------------------------------
** I attest that this following code represents my own work and is subject to
** the plagiarism policy found in the course syllabus.
** 
** Class: 	CSC 242
** Assignment: 	
** File: 	source.cpp
** Description: 
**
** Author: 	Group not F
** Date: 	8/25/2025
** -------------------------------------------------------------------------*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    ifstream My_File("C:\\Users\\Nelphy\\Desktop\\words");//This will get the file and open it.
    
    if (My_File.is_open())//This will check if the file is not open.
    {
       cerr << "Error: Could not open the file" << endl;//This will output the error.
       return 1;
    }

    vector<string> words;



    return 0;
}