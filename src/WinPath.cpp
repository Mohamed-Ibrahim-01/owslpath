#include"../headers/WinPath.hpp"
#include <list>
#include <regex>
#include <string>
#include <utility>
using namespace std;
WinPath::WinPath( string p){
    path = std::move(p);
}
WinPath::WinPath()= default;
bool WinPath::validPath(){
    const auto subDirectories ="(" + nonforbiddenChars+ "*" + bslash + "?)*"; 
    regex winPathFormat (disk + ":" + bslash + subDirectories);
    return (hasNoForbiddenChars(path) &&  regex_match(path,winPathFormat));
}
list<string> WinPath::extractDirs(){
    list<string> dirs;
    string str = path;
    smatch captured;
    while (regex_search(str,captured,regex{"(" + nonforbiddenChars + ")+"})){
        string capturedStr = captured[0].str();
        if(!capturedStr.empty()){
            dirs.push_back(capturedStr);
        }
        str = captured.suffix();
    }
    return dirs;
}
string WinPath::toLnx(){
    list<string> dirs = extractDirs();
    string _disk = toLower(dirs.front());
    string wslPath = "/mnt/" + _disk + "/";
    dirs.pop_front();
    for(const auto& dir : dirs){
        string fixedDir = fixSpaces(dir);
        wslPath += fixedDir + "/";
    }
    return wslPath;
}

string WinPath::toWin(){
    return path;
}