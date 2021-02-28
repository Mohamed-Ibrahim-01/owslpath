#pragma once
#include <utility>

#include"utils.hpp"
class Path{
    public:
        string path;
        Path()= default;;
        explicit Path(string p);
        virtual bool validPath() = 0;
        virtual string toLnx() = 0;
        virtual string toWin() = 0;
        virtual list<string> extractDirs() = 0;
        static bool hasNoForbiddenChars(const string& path);
        void setPath(string p){
            path = std::move(p);
        }
};

const string forbiddenChars = R"({\\,:,\*,\",\?,\>,\<,\|})";
const string nonforbiddenChars = "[^" + forbiddenChars + "]";
const string disk = "([a-zA-Z])";
const string bslash = "\\\\";