#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

enum trait { POTENCY, ESSENCE, ASPECT};

struct rune
{
    string name;
    trait type;
};

void readFile(ifstream& fin, rune arr[], int& index);

int main(int argc, char** argv)
{
    rune arr[300];
    int used[300];
    int index = 0;
    int i;
    ifstream fin;

    if (argc != 2)
    {
        cout << "Usage: m0100.exe filename";
        return 0;
    }

    fin.open(argv[1]);
    if (!fin.is_open())
    {
        cout << argv[1] << " could not be opened.";
        return 0;
    }

    readFile(fin, arr, index);

    for (i = 0; i < index; i++)
    {
        cout << arr[i].name << "," << arr[i].type << endl;
    }
    

    fin.close();
    return 0;
}

void readFile(ifstream& fin, rune arr[], int& index)
{
    string line;
    string temp;

    getline(fin, line);
    while (getline(fin, line))
    {
        arr[index].name = line.substr(0, line.find(','));
        temp = line.substr(line.find(',') + 1);

        if (temp == "Potency")
        {
            arr[index].type = POTENCY;
        }
        else if (temp == "Essence")
        {
            arr[index].type = ESSENCE;
        }
        else
        {
            arr[index].type = ASPECT;
        }

        index++;
    }
}