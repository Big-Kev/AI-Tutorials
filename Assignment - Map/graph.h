#pragma once
class graph
{
public:
	graph(float screenWidth, float screenHeight, float nSize = -1);
	~graph();

protected:
	float node_size;
	float node_diagonal_size;
};

