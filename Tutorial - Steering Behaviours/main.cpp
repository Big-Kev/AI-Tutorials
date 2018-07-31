#include "Tutorial___Steering_BehavioursApp.h"

int main() {
	
	// allocation
	auto app = new Tutorial___Steering_BehavioursApp();

	// initialise and loop
	app->run("AIE", 1280, 720, false);

	// deallocation
	delete app;

	return 0;
}