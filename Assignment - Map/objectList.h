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
	std::vector<Vector3> data;
	void addDat(Vector3 v);
};

