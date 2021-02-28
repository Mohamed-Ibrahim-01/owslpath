#pragma once
#include"Path.hpp"
class LnxPath : public Path{
    public:
        explicit LnxPath(string p);
        bool validPath() override;
        list<string> extractDirs() override;
        string toWin() override;
        string toLnx() override;
};