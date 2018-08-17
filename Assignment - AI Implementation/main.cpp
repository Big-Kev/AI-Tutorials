#include "Assignment___AI_ImplementationApp.h"

int main() {
	
	// allocation
	auto app = new Assignment___AI_ImplementationApp();

	// initialise and loop
	app->run("AIE", 1280, 720, false);

	// deallocation
	delete app;

	return 0;
}