#include "Assignment___MapApp.h"

int main() {
	
	// allocation
	auto app = new Assignment___MapApp();

	// initialise and loop
	app->run("AIE", 1280, 720, false);

	// deallocation
	delete app;

	return 0;
}