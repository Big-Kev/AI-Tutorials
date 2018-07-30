#include "Tutorial___Finite_State_MachinesApp.h"

int main() {
	
	// allocation
	auto app = new Tutorial___Finite_State_MachinesApp();

	// initialise and loop
	app->run("AIE", 1280, 720, false);

	// deallocation
	delete app;

	return 0;
}