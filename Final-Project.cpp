#include <math.h>
#include <iomanip>
#include <fstream>
#include <iostream> // For outputting to console
#include <string>   // For reading lines into a string

using namespace std;

int main()
{
    //const string path = R"(C:\Users\Nelphy\Documents\WordTest.xlsx)";
    //ifstream MyFile("C:\Users\Nelphy\Documents\WordTest.xlsx");
  
    ifstream MyFile;
    MyFile.open("C:\\Users\\Nelphy\\Documents\\WordTest.xlsx");

    if (MyFile.is_open())
    {
        cout << "The file is open" << endl;
    }
    if (!MyFile.is_open())
    {  
        cout << "The file is closed" << endl;    
    }
    return 0;
}