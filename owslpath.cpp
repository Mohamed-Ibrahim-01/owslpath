#include"owslpath.h"
#include<algorithm>

const string forbiddenChars = "{\\\\,:,\\*,\\\",\\?,\\>,\\<,\\|}";
const string nonforbiddenChars = "[^" + forbiddenChars + "]";
const string disk = "([a-zA-Z])";
const string bslash = "\\\\";
const bool WINDOWS = true;
const bool LINUX = false;

int main(int argc, char *argv[]){
    bool pathType = dectedPath(argv[1]);
    if(pathType == WINDOWS)
        cout << winTolnx(argv[1]) << endl;
    else 
        cout << lnxToWin(argv[1]) << endl;
    return 0;
}

string winTolnx(string path){
    bool validPath = validWinPath(path);

    if(validPath){
        list<string> dirs = extractWinDirs(path);
        return createWslPath(dirs);
    }
    return "\033[1;31mInvalid Path\033[0m\n";
}
bool dectedPath(string path){
    if(validLnxPath(path)) return LINUX;
    return WINDOWS;
}
bool validLnxPath(string path){
    const auto subDirectories ="(" + nonforbiddenChars + "*/?)*"; 
    regex lnxPathFormat ("/mnt/"+ disk + "/" + subDirectories);
    return (hasNoForbiddenChars(path) && regex_match(path,lnxPathFormat));
}
bool validWinPath(string path){
    const auto subDirectories ="(" + nonforbiddenChars+ "*" + bslash + "?)*"; 
    regex winPathFormat (disk + ":" + bslash + subDirectories);
    return (hasNoForbiddenChars(path) &&  regex_match(path,winPathFormat));
}

string lnxToWin(string path){
    bool validPath = validLnxPath(path);

    if(validPath){
        list<string> dirs = extractLnxDirs(path);
        return createWinPath(dirs);
    }
    return "\033[1;31mInvalid Path\033[0m\n";
}

list<string> extractWinDirs( string path){
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
list<string> extractLnxDirs( string path){
    list<string> dirs;
    std::string s = path;

    size_t pos = 0;
    std::string token;
    string delimiter = "/";
    while ((pos = s.find(delimiter)) != std::string::npos) {
        token = s.substr(0, pos);
        dirs.push_back(token);
        s.erase(0, pos + delimiter.length());
    }
    dirs.push_back(s);
    return dirs;
}
string createWslPath(list<string> dirs){
    string disk = toLower(dirs.front());
    string wslPath = "/mnt/" + disk + "/"; 
    dirs.pop_front();
    for(auto dir : dirs){
        string fixedDir = fixSpaces(dir);
        wslPath += fixedDir + "/";
    }
    return wslPath;
}
string createWinPath(list<string> dirs){
    string winPath, disk;
    if(! dirs.empty()){
        dirs.pop_front(); // skip ""
        dirs.pop_front(); // skip "mnt"
        disk = toupper(dirs.front()[0]);
        winPath = disk + ":\\"; 
        dirs.pop_front();
    }
    for(auto dir : dirs){
        if(dir != "") winPath += dir + "\\";
    }
    return winPath;
}

string fixSpaces(string dir){
    return regex_replace (dir,regex{" "},"\\ ");
}

string toLower(string s) {
    transform(begin(s), end(s), begin(s), [](unsigned char c){ 
            return tolower(c);
            });
    return s;
}
bool hasNoForbiddenChars(string path){
    string forbiddenChars[6] = {"?","|","<",">","\"",":"};
    for(auto forbidden : forbiddenChars){
        int containsForbidden = path.find_last_of(forbidden);
        if( containsForbidden != std::string::npos ) {
            if( forbidden == ":" && containsForbidden == 1) return true;
            cout << "Forbidden Character -> '"<<forbidden << "' found in the path" << endl;
            return false;
        }
    }
    return true;
}

