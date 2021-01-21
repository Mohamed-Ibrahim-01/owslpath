#include"owslpath.h"

int main(int argc, char *argv[]){
    string winPath =  winTolnxPath(argv[1]);
    cout << winPath;
    return 0;
}
string winTolnxPath(string path){
    string forbiddenChars = "{\\\\,\\/,:,\\*,\\\",\\?,\\>,\\<,\\|}";
    string nonforbiddenChars = "[^" + forbiddenChars + "]";
    string disk = "([a-zA-Z])";
    string bslash = "\\\\";
    auto subDirectories ="(" + nonforbiddenChars+ "*" + bslash + "*)*"; 

    smatch captured;
    regex reg_exp (disk + ":" + bslash + subDirectories);

    bool validPath = (noForbiddenChars(path) &&  regex_match(path,reg_exp));
    if(validPath){
        list<string> dirs;
        string str = path;
        while (regex_search(str,captured,regex{"(" + nonforbiddenChars + ")+"})){
            string capturedStr = captured[0].str();
            if(!capturedStr.empty()){
                dirs.push_back(capturedStr);
            }
            str = captured.suffix();
        }
        return createWslPath(dirs);
    }
    return "\033[1;31mInvalid Path\033[0m\n";
}

string createWslPath(list<string> dirs){
    string disk = toLower(dirs.front());
    string winPath = "/mnt/" + disk + "/"; 
    dirs.pop_front();
    for(auto dir : dirs){
        string fixedDir = fixSpaces(dir);
        winPath += fixedDir + "/";
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
bool noForbiddenChars(string path){
    if(path.find_last_of("/") != -1 ) return false;
    if(path.find_last_of("?") != -1 ) return false;
    if(path.find_last_of("|") != -1 ) return false;
    if(path.find_last_of("<") != -1 ) return false;
    if(path.find_last_of(">") != -1 ) return false;
    if(path.find_last_of("\"") != -1 ) return false;
    if(path.find_last_of(":") > 1 ) return false;
    else return true;
}

