#include "Tutorial___PathfindingApp.h"

int main() {
	
	// allocation
	auto app = new Tutorial___PathfindingApp();

	// initialise and loop
	app->run("AIE", 1280, 720, false);

	// deallocation
	delete app;

	return 0;
}