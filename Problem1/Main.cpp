#include "InputHandler.h"
#include "CostCalculator.h"

int main()
{
	InputHandler inputHandler;
	const std::vector<Package> packages = inputHandler.GetPackages();
	
	for (int i = 0; i < inputHandler.GetNumberOfPackages(); i++)
	{
		std::cout << CostCalculator::SharedInstance()->CalculateCost(packages[i], inputHandler.GetBaseDeliveryCost()) << std::endl;
	}
	return 0;
}