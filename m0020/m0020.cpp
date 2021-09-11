#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

float* findMinimum(float a[], int size);
float* findMaximum(float a[], int size);

int main(int argc, char* argv[])
{
    ifstream fin;
    ofstream fout;
    int size;
    int i = 0;
    int j = 0;
    float* array = nullptr;
    float* minptr = nullptr;
    float* maxptr = nullptr;

    //Check command line args
    if (argc != 3)
    {
        cout << "Usage: m0020.exe inputfile outputfile";
        return 0;
    }

    //Open input file
    fin.open(argv[1]);

    if (!fin.is_open())
    {
        cout << "Unable to open input file: " << argv[1];
        return 0;
    }

    //Open output file
    fout.open(argv[2]);

    if (!fout.is_open())
    {
        cout << "Unable to open output file: " << argv[2];
        fin.close();
        return 0;
    }
    
    //receive initial size and allocate an array of that size
    fin >> size;
    array = new (nothrow) float [size];
    if (array == nullptr)
    {
        cout << "Unable to allocate memory";
        return 0;
    }

    
    while ((i != size) && (fin >> array[i]))
    {
        i++;
    }
    size = i;
    

    minptr = findMinimum(array, size);
    maxptr = findMaximum(array, size);


    fout << size << endl;
    fout << setprecision(3) << fixed << showpoint;
    fout << *minptr << " - " << *maxptr << endl;
    
    for (i = 0; i < size; i++)
    {
        fout << setw(15) << array[i];
        j++;
        if (j == 5)
        {
            fout << endl;
            j = 0;
        }
    }
    if ((size % 5) != 0)
    {
        fout << endl;
    }

    delete[] array;
    fin.close();
    fout.close();
    
    return 0;
}


float* findMinimum(float a[], int size)
{
    int i;
    float min = a[0];
    float * minptr = &a[0];

    for (i = 1; i < size; i++)
    {
        if (min > a[i])
        {
            min = a[i];
            minptr = &a[i];
        }
    }

    return minptr;
}


float* findMaximum(float a[], int size)
{
    int i;
    float max = a[0];
    float* maxptr = &a[0];

    for (i = 1; i < size; i++)
    {
        if (max < a[i])
        {
            max = a[i];
            maxptr = &a[i];
        }
    }

    return maxptr;
}
