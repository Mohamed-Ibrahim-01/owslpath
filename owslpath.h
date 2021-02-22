#include <list>
#include <algorithm>
#include<regex>
#include<iostream>
#include <fstream>
using namespace std;
bool hasNoForbiddenChars(string path);
string winTolnx(string path);
string fixSpaces(string dir);
string toLower(string s);
string createWslPath(list<string> dirs);
string lnxToWin(string path);
list<string> extractWinDirs( string path );
list<string> extractLnxDirs( string path );
string createWinPath(list<string> dirs);
bool validLnxPath(string lnxPath);
bool validWinPath(string lnxPath);
bool dectedPath(string path);
