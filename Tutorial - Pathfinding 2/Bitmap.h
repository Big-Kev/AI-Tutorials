#pragma once
#include <fstream>
#include <iostream>
#include "objectList.h"
using namespace std;
class Bitmap
{
public:
	Bitmap();
	~Bitmap();

	unsigned char * ReadBMP(char * filename, objectList* olist);
	void bmptest();

	



	



};

