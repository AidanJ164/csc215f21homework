#include <iostream>
#include <fstream>
using namespace std;

int findMinimum(double a[], int size);
int findMaximum(double a[], int size);

int main(int argc, char* argv[])
{
    ifstream input;
    ofstream output;
    int size;
    float* fptr;

    if (argc != 3)
    {
        cout << "Usage: m0020.exe inputfile outputfile";
        return 0;
    }

    input.open(argv[1]);

    if (!input.is_open())
    {
        cout << "Unable to open input file: " << argv[1];
        return 0;
    }

    output.open(argv[2]);

    if (!output.is_open())
    {
        cout << "Unable to open output file: " << argv[2];
        return 0;
    }
}