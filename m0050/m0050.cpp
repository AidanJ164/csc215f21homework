#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;

struct empData
{
    int id;
    string firstName;
    string lastName;
    double salary;
    double bonus;
};

bool sortByID( empData lhs, empData rhs );
bool sortBySalary( empData lhs, empData rhs );
bool sortByName( empData lhs, empData rhs );

int main(int argc, char** argv)
{
    ifstream fin;
    ofstream fout;
    vector<empData> vemployee;
    string header;
    string line;
    empData employee;
    int i = 0;
    long long pos;

    if ( argc != 4 )
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

    if ( ( strcmp( argv[3], "-i" ) != 0 ) && ( strcmp( argv[3], "-n" ) != 0 )
        && ( strcmp( argv[3], "-s" ) != 0 ) )
    {
        cout << "Invalid Sort Method:" << endl << "-i - sort by id" << endl
             << "-n - sort by name" << endl << "-s - sort by salary";
        return 0;
    }

    //Read in header
    getline( fin, header );

    //Read in employee data
    i = 0;
    while ( getline( fin, line ) )
    {
        pos = line.find( "," );
        employee.id = stoi( line.substr( 0, pos ) );
        line.erase( 0, pos + 1 );

        pos = line.find( "," );
        employee.firstName = line.substr( 0, pos );
        line.erase( 0, pos + 1 );

        pos = line.find( "," );
        employee.lastName = line.substr( 0, pos );
        line.erase( 0, pos + 1 );

        pos = line.find( "," );
        employee.salary = stod( line.substr( 0, pos ) );
        line.erase( 0 , pos + 1 );

        employee.bonus = stod( line );

        vemployee.push_back( employee );
    }

    //Sort
    if ( strcmp( argv[3], "-i" ) == 0 )
    {
        sort( vemployee.begin(), vemployee.end(), sortByID );
    }
    else if ( strcmp( argv[3], "-s" ) == 0 )
    {
        sort( vemployee.begin(), vemployee.end(), sortBySalary );
    }
    else if ( strcmp( argv[3], "-n" ) == 0 )
    {
        sort( vemployee.begin(), vemployee.end(), sortByName );
    }

    //Output to file
    fout << header << endl;
    fout << setprecision(2) << fixed << showpoint;
    
    for ( i = 0; i < vemployee.size(); i++ )
    {
        fout << vemployee[i].id << "," << vemployee[i].firstName << ","
             << vemployee[i].lastName << "," << vemployee[i].salary
             << "," << vemployee[i].bonus << endl;
    }

    fin.close();
    fout.close();

    return 0;
}

bool sortByID(empData lhs, empData rhs)
{
    return (lhs.id < rhs.id);
}

bool sortBySalary( empData lhs, empData rhs )
{
    return ( lhs.salary > rhs.salary );
}

bool sortByName( empData lhs, empData rhs )
{
    if ( lhs.lastName.compare( rhs.lastName ) < 0 )
    {
        return true;
    }
    else if ( lhs.lastName == rhs.lastName )
    {
        return ( lhs.firstName.compare( rhs.firstName ) < 0 );
    }

    return false;
}