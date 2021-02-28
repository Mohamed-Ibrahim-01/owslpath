#include"../headers/owslpath.hpp"
#include <iostream>
#include <string>
#include <utility>
using namespace std;
int main( int argc, char *argv[]){
    bool pathType = detectPath(argv[1]);
    if(pathType == WINDOWS){
        WinPath path (argv[1]);
        cout << winTolnx(path) << endl;
    }
    else{
        LnxPath path (argv[1]);
        cout << lnxToWin(path) << endl;
    }
    return 0;
}

bool detectPath(string path){
    LnxPath testPath (std::move(path));
    if( testPath.validPath() ) return LINUX;
    return WINDOWS;
}

string winTolnx(WinPath path){
    if( path.validPath() ) return path.toLnx();
    return "\033[1;31mInvalid Path\033[0m\n";
}
string lnxToWin(LnxPath path){
    if( path.validPath() ) return path.toWin();
    return "\033[1;31mInvalid Path\033[0m\n";
}



