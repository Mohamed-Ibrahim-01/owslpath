# owslpath ⚡

### About 💬
Open wslpath (owslpath) is a simple command line tool for wsl terminal to convert between windows and **WSL** `Windows Subsystem for Linux` path. 

### Installation

You can install it any way you want , but this a method you can use .

```bash
git clone https://github.com/Mohamed-Ibrahim-01/owslpath.git
cd owslpath
g++ -o owslpath owslpath.cpp
mkdir ~/.scripts/ # if it wasn't already created
mv owslpath ~/.scripts
# then add this alias in ~/.bash_aliases
alias owslpath="~/.scripts/./owslpath"
```

### Usage

```bash
#if you add the alias use it like that
owslpath '<WindowsPath>'
#or just use it like that
~/.scripts/./owslpath '<WindowsPath>'
```

## Languages and Tools 🛠
<p align="left"> 
<a href="https://www.w3schools.com/cpp/" target="_blank">
  <img src="https://raw.githubusercontent.com/devicons/devicon/master/icons/cplusplus/cplusplus-original.svg" alt="cplusplus" width="40" height="40"/> 
</a> 
<a href="https://www.linux.org/" target="_blank">
  <img src="https://raw.githubusercontent.com/devicons/devicon/master/icons/linux/linux-original.svg" alt="linux" width="40" height="40"/> 
</a> 
</p>

## License
[MIT](https://choosealicense.com/licenses/mit/)
