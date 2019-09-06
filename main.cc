
#include <iostream>

#include "move.h"

using std::cout;
using std::endl;


int main(int argc, char* argv[])
{
    if(argc == 1 || argc == 2)  // not enough arguments
    {
        cout << "usage:\t FileMover source target" << endl;
        return 1;
    }
    else if(argc == 3)  // two args, no flags
    {
        move(argv[1], argv[2]);
    }
    // TODO flag for copy

    return 0;
}

