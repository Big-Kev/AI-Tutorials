#pragma once
#include <fstream>
class bitmap
{
public:
	bitmap();
	~bitmap();
	void bitmapTest(int map_width, int map_height);
	void createBitmap(const char * filename, int width, int height);
	void bitmapTest();
	//bool data63 w 35 h
	bool data[35][63];
	
};

