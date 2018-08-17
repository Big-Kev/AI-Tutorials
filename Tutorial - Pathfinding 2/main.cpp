#include "Tutorial___Pathfinding_2App.h"

int main() {
	
	// allocation
	auto app = new Tutorial___Pathfinding_2App();

	// initialise and loop
	app->run("AIE", 1280, 720, false);

	// deallocation
	delete app;

	return 0;
}