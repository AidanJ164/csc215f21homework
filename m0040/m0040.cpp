#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

struct empData
{
    int id;
    char firstName[20];
    char lastName[40];
    double salary;
    double bonus;
};

void printFile(fstream& file);
bool applyBonus(fstream& file, int id);


int main(int argc, char** argv)
{
    fstream file;
    int id;

    if (argc != 3)
    {
        cout << "Usage: m0040.exe binaryData employeeID";
        return 0;
    }

    file.open(argv[1], ios::in | ios::out | ios::ate | ios::binary);
    if (!file.is_open())
    {
        cout << "Unable to open binary file: " << argv[1];
        return 0;
    }

    id = atoi(argv[2]);

    printFile(file);



    file.close();

    return  0;
}

void printFile(fstream& file)
{
    empData employee;

    file.seekg(0, ios::beg);
    cout << setprecision(2) << fixed << showpoint;

    while ( file.read( (char*) &employee, sizeof(empData) ) )
    {
        cout << setw(7) << employee.id << " "
            << left << setw(20) << employee.firstName
            << setw(40) << employee.lastName << right
            << " Salary: " << setw(10) << employee.salary
            << " Bonus: " << setw(10) << employee.bonus << endl;
    }
}

bool applyBonus(fstream& file, int id)
{
    return true;
}