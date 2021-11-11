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

void readFile(ifstream& fin, rune arr[], int& n);
void permute(int* p, rune arr[], int* used, int n, int k, int pos);

int main(int argc, char** argv)
{
    rune arr[300];
    int p[300] = { 0 };
    int used[300] = { 0 };
    int n = 0;
    int k = 3;
    int pos = 0;
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

    readFile(fin, arr, n);
    
    permute(p, arr, used, n, k, pos);

    fin.close();
    return 0;
}

void readFile(ifstream& fin, rune arr[], int& n)
{
    string line;
    string temp;

    getline(fin, line);
    while (getline(fin, line))
    {
        arr[n].name = line.substr(0, line.find(','));
        temp = line.substr(line.find(',') + 1);

        if (temp == "Potency")
        {
            arr[n].type = POTENCY;
        }
        else if (temp == "Essence")
        {
            arr[n].type = ESSENCE;
        }
        else
        {
            arr[n].type = ASPECT;
        }

        n++;
    }
}

void permute(int *p, rune arr[], int* used, int n, int k, int pos)
{
    int i;

    if (pos == k)
    {

        if (arr[p[0]].type == POTENCY && arr[p[1]].type == ESSENCE
            && arr[p[2]].type == ASPECT)
        {
            for (i = 0; i < k; i++)
            {
                cout << arr[p[i]].name << " ";
            }
            cout << endl;
        }
        
        return;
    }

    for (i = 0; i < n; i++)
    {
        if (used[i] == 0)
        {
            p[pos] = i;
            used[i] = 1;
            permute(p, arr, used, n, k, pos + 1);
            used[i] = 0;
        }
    }
}