#ifndef Move_H_
#define Move_H_

#include <string>

// pre: 
// post: file is moved
void move(char*, char*);

// pre:
// post: returns true if dir exists, false otherwise
bool dirExists(const std::string &);

// pre:
// post: returns directory (possibly stripping filename)
std::string getDir(const std::string &);

#endif  // Move_H_