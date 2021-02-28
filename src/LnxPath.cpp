#include"../headers/LnxPath.hpp"
#include <algorithm>
#include <regex>
#include <string>
#include <utility>
using namespace std;
bool LnxPath::validPath(){
    const auto subDirectories ="(" + nonforbiddenChars + "*/?)*"; 
    regex lnxPathFormat ("/mnt/"+ disk + "/" + subDirectories);
    return (hasNoForbiddenChars(path) && regex_match(path,lnxPathFormat));
}
list<string> LnxPath::extractDirs(){
    list<string> dirs;
    string s = path, delimiter = "/", token;
    size_t pos;
    while ((pos = s.find(delimiter)) != std::string::npos) {
        token = s.substr(0, pos);
        dirs.push_back(token);
        s.erase(0, pos + delimiter.length());
    }
    dirs.push_back(s);
    dirs.pop_front(); // skip ""
    dirs.pop_front(); // skip "mnt"
    return dirs;
}

string LnxPath::toWin(){
    list<string> dirs = extractDirs();
    string winPath, _disk;
    if(! dirs.empty()){
        _disk = toupper(dirs.front()[0]);
        winPath = _disk + ":\\";
        dirs.pop_front();
        for(const auto& dir : dirs){
            if(!dir.empty()) winPath += dir + "\\";
        }
    }
    return winPath;
}
string LnxPath::toLnx(){
    return path;
}

LnxPath::LnxPath(string p) : Path(std::move(p)) {

}
