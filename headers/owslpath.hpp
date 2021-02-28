#pragma once
#include"Path.hpp"
#include "WinPath.hpp"
#include "LnxPath.hpp"

string winTolnx(WinPath path);
string lnxToWin(LnxPath path);
bool detectPath(string path);

const bool WINDOWS = true;
const bool LINUX = false;
