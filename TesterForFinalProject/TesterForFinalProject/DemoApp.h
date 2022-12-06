#pragma once

#include "includes.h"

class DemoApp
{
public:
    //DemoApp();
    //~DemoApp();

    // generate lines to be output to window
    void generateLines(int const numLines, float width, float height, std::string color, int length);

    //DEBUG
    // outputs Lines generated to console
    void outputLines();


private:
   
    std::vector<Line> lines{};
};