#include"../headers/utils.hpp"
#include <iostream>
#include <algorithm>
#include <regex>
#include <fstream>
#include <string>
using namespace std;
string fixSpaces(string dir){
    return regex_replace (dir,regex{" "},"\\ ");
}

string toLower(string s) {
    transform(begin(s), end(s), begin(s), [](unsigned char c){ 
            return tolower(c);
            });
    return s;
}
list<string> split(string path){
    list<string> dirs;
    string s = path, delimiter = "/", token;
    size_t pos = 0;
    while ((pos = s.find(delimiter)) != std::string::npos) {
        token = s.substr(0, pos);
        dirs.push_back(token);
        s.erase(0, pos + delimiter.length());
    }
    dirs.push_back(s);
    return dirs;
}
