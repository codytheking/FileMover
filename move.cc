
#include <iostream>
#include <fstream>
#include <sys/stat.h>
#include <string>
#include <vector>
#include <algorithm>

#include "move.h"

void move(char* file, char* dest)
{
    // check that directory exists
    std::string dir(dest);
    std::string src(file);
    std::string destDir = getDir(dir);
    
    if(!dirExists(src))
    {
        std::cout << "FileMover: " << src << ": No such file or directory" << std::endl; 
        return;
    }

    if(!dirExists(dest))
    {
        std::cout << "FileMover: " << dest << ": No such file or directory" << std::endl; 
        return;
    }

    // perform move
    std::string line;
    std::vector<std::string> lines;

    //create an input stream to read the file
    std::ifstream sourceFile (file);
    //During the creation of ifstream, the file is opened. 
    //So we do not have explicitly open the file.
    if(sourceFile.is_open())
    {
        while (std::getline(sourceFile, line))
        {
            lines.push_back(line);
        }
        sourceFile.close();
    }
    else 
    {
        std::cout << "Unable to open file for reading" << std::endl;
        return;
    }

    //create an output stream to write to the file
    std::ofstream newFile (dest, std::ios::app);
    //append the new lines to the end of the file
    if (newFile.is_open())
    {
        for(std::string s: lines)
        {
            newFile << s;
            newFile << "\n";
        }
        newFile.close();
    }
    else 
    {
        std::cout << "Unable to open file for writing" << std::endl;
        return;
    }
}

bool dirExists(const std::string &s)
{
  struct stat buffer;
  return (stat (s.c_str(), &buffer) == 0);
}

std::string getDir(const std::string &dest)
{
    int numSlashes = std::count(dest.begin(), dest.end(), '/');
    
    if(numSlashes <= 1)
        return dest;

    return dest.substr(0, dest.find_last_of("/") + 1);
}
