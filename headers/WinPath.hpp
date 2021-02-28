#pragma once
#include"Path.hpp"
class WinPath : public Path{
    public:
        explicit WinPath(string p);
        WinPath();
        bool validPath() override;
        list<string> extractDirs() override;
        string toLnx() override;
        string toWin() override;
};
