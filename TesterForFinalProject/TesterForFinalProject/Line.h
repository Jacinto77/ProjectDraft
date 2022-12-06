#pragma once

#include <string>

class Line
{
public:
    Line();

    Line(int startx, int starty);

    Line(int startx, int starty, int endx, int endy, std::string color);


    ~Line();

    // start coordinates
    int m_startX{};
    int m_startY{};

    // end coordinates
    int m_endX{};
    int m_endY{};

    // color of line
    std::string m_color{};

    void drawSelf();

};