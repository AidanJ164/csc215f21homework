/*
#include <iostream>
#include <windows.h>
using namespace std;

int main()
{
    HANDLE hstdin;
    DWORD  mode;

    hstdin = GetStdHandle(STD_INPUT_HANDLE);
    GetConsoleMode(hstdin, &mode);
    SetConsoleMode(hstdin, ENABLE_ECHO_INPUT | ENABLE_PROCESSED_INPUT);  // see note below 

    cout << "Press any key..." << flush;
    int ch = cin.get();

    if (ch == 32) cout << "\nYou pressed SPACE\n";
    else          cout << "\n\nYou did not press SPACE\n";

    SetConsoleMode(hstdin, mode);
    return 0;
}
*/