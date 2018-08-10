#pragma once
#include <vector>
#include "Vector3.h"
#include <fstream>
#include <iostream>

class objectList
{
public:
	objectList();
	~objectList();
	//vector3(xpos, ypos, type)
	std::vector<Vector3> data;
	void write();
};

