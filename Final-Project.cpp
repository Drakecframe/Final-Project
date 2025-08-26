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
    
    if (!My_File.is_open())//This will check if the file is not open(Just to be safe)
    {
       cerr << "Error: Could not open the file" << endl;//This will output the error.
       return 1;
    }

    //This will store the words from the file into the vector.
    vector<string> words;
    string read_lines;
    while (getline(My_File, read_lines))
    {
        words.push_back(read_lines);
    }
    
    My_File.close();

    //User Input Word
    string user_w;
    cout << "Enter your word here: "; cin >> user_w;
    
    //Checking words in the vector
    bool wordfound = false;
    for (const string& word : words)
    {
        if (word == user_w)
        {
            wordfound = true;
        }  
        break; 
    }
    
    //Check if the word is on the file and print the word
    if (found)
    {
        cout << user_w << "is in the file!" << endl;
    }
    else 
    {
        cout << user_w << " is not in the file!" << endl;
    }
    return 0;
}