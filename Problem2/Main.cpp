#include "InputHandler.h"

int main()
{
	InputHandler				 inputHandler;
	std::vector<OptionalPackage> packages = inputHandler.GetPackages();
	return 0;
}