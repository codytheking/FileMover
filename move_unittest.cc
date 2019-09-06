

#include <limits.h>
#include "move.h"
#include "gtest/gtest.h"
namespace {

// Tests dirExists()
// Current directory
TEST(dirExists, Current)
{
    EXPECT_EQ(1, dirExists("./"));
    EXPECT_EQ(1, dirExists("../"));
    EXPECT_EQ(1, dirExists("./build"));
    EXPECT_EQ(1, dirExists("build"));
    EXPECT_EQ(1, dirExists("build/"));
    EXPECT_EQ(1, dirExists("./main.cc"));
    EXPECT_EQ(0, dirExists("fake/"));
}

// System directories
TEST(dirExists, System)
{
    EXPECT_EQ(1, dirExists("/"));
    EXPECT_EQ(1, dirExists("/Users"));
    //EXPECT_EQ(1, dirExists("~/"));
    EXPECT_EQ(0, dirExists("/Fake"));
}


// Tests getDir()
// 
TEST(getDir, Tests)
{
    EXPECT_EQ("./", getDir("./"));
    EXPECT_EQ("./build", getDir("./build"));
    EXPECT_EQ("./build/", getDir("./build/"));
    EXPECT_EQ("./build/", getDir("./build/fake"));
}

}  // namespace

// Call RUN_ALL_TESTS() in main().
