#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct empData
{
    int id;
    string firstName;
    string lastName;
    double salary;
    double bonus;
};

int main(int argc, char** argv)
{
    ifstream fin;
    ofstream fout;

    if (argc != 4)
    {
        cout << "Usage: m0050.exe inputCSVFile outputCSVFile sortMethod";
        return 0;
    }

    fin.open( argv[1] );
    if ( !fin.is_open() )
    {
        cout << "Unable to open input file: " << argv[1];
        return 0;
    }

    fout.open( argv[2] );
    if ( !fout.is_open() )
    {
        cout << "Unable to open output file: " << argv[2];
        fin.close();
        return 0;
    }

    if ( (strcmp( argv[3], "-i" ) != 0) && (strcmp( argv[3], "-n" ) != 0) &&
         (strcmp( argv[3], "-s" ) != 0) )
    {
        cout << "Invalid sort method:" << endl << "-i - sort by id" << endl
             << "-n - sort by name" << endl << "-s - sort by salary";
    }


    return 0;
}