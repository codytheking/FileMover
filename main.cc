
#include <iostream>
#include <fstream>
#include <sstream>
#include <sys/stat.h>
#include <string>
#include <vector>

using std::cout;
using std::endl;

// pre: 
// post: file is moved
void move(char*, char*);

// pre:
// post: returns true if dir exists, false otherwise
bool dirExists(const std::string &);

int main(int argc, char* argv[])
{
    if(argc == 1 || argc == 2)
    {
        cout << "usage:\t FileMover source target" << endl;
        return 1;
    }
    else if(argc == 3)
    {
        move(argv[1], argv[2]);
    }

    return 0;
}

void move(char* file, char* dest)
{
    std::string line;
    std::vector<std::string> lines;

    // TODO check that directory exists


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
        cout << "Unable to open file for reading";
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
        cout << "Unable to open file for writing" << endl;
        return;
    }
}

bool dirExists(const std::string &s)
{
  struct stat buffer;
  return (stat (s.c_str(), &buffer) == 0);
}
