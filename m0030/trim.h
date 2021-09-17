#define _CRT_SECURE_NO_WARNINGS
#include <cctype>
#include <cstring>
#include <string>

using namespace std;

enum trimType { BOTH, FRONT, END };

void cTrim(char *cString, trimType method);
void sTrim(string& cplusString, trimType method);