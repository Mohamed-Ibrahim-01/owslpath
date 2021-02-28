#include"../headers/Path.hpp"
#include <iostream>
#include <string>
#include <utility>
using namespace std;
Path::Path(string p){
    path = std::move(p);
}
bool Path::hasNoForbiddenChars(const string& path) {
    string _forbiddenChars[6] = {"?", "|", "<", ">", "\"", ":"};
    for (const auto& forbidden : _forbiddenChars) {
        int containsForbidden = path.find_last_of(forbidden);
        if (containsForbidden != std::string::npos) {
            if (forbidden == ":" && containsForbidden == 1) return true;
            cout << "Forbidden Character -> '" << forbidden << "' found in the path" << endl;
            return false;
        }
    }
    return true;
}


