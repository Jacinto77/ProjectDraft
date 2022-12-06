#include "Includes.h"
#include "DemoApp.h"

int main()
{
	int const numLines = 300;
	int const width = 1000;
	int const height = 1000;
	int const length = 4;

	// create 4 objects to represent the different line colors
	// The vectors will be individual vectors within the DemoApp class, not requiring 4 instances of DemoApp
	// to be created, i.e. DemoApp.black/DemoApp.blue etc
	DemoApp black{};
	DemoApp red{};
	DemoApp yellow{};
	DemoApp blue{};

	// generate the lines for the "model" of data
	black.generateLines(numLines, width, height, "black", length);
	red.generateLines(numLines, width, height, "red", length);
	yellow.generateLines(numLines, width, height, "yellow", length);
	blue.generateLines(numLines, width, height, "blue", length);

	// output the lines to the console
	black.outputLines();
	red.outputLines();
	yellow.outputLines();
	blue.outputLines();

}