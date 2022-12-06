#include "Line.h"

// default constructor
Line::Line()
{

}

// constructor for only two args, being the start point of the line
Line::Line(int startx, int starty)
{
	m_startX = startx;
	m_startY = starty;
}

// constructor with all attributes provided
Line::Line(int startx, int starty, int endx, int endy, std::string color)
{
	m_startX = startx;
	m_startY = starty;

	m_endX = endx;
	m_endY = endy;

	m_color = color;
}

// destructor
Line::~Line()
{

}

// maybe have a function to tell the line to draw itself?
void Line::drawSelf()
{
	// code here
}