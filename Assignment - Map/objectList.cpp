#include "objectList.h"



objectList::objectList()
{
}


objectList::~objectList()
{
}

void objectList::write()
{
	std::ofstream myfile;
	myfile.open("example.txt");
	myfile << "Writing this to a file.\n";
	myfile.close();

}
