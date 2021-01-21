#include <list>
#include <algorithm>
#include<regex>
#include<iostream>
#include <fstream>
using namespace std;
bool noForbiddenChars(string path);
string winTolnxPath(string path);
string fixSpaces(string dir);
string toLower(string s);
string createWslPath(list<string> dirs);
