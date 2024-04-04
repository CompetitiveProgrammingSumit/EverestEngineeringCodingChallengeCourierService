#include "InputHandler.h"
#include "CostCalculator.h"

int main()
{
	InputHandler				 inputHandler;
	std::vector<OptionalPackage> packages = inputHandler.GetPackages();

	for (int i = 0; i < inputHandler.GetNumberOfPackages(); i++)
	{
		if(packages[i].isValidPackage)
		{
			const std::tuple<const float, const float> result = CostCalculator::SharedInstance()->CalculateCost(packages[i].package, inputHandler.GetBaseDeliveryCost());
			const float totalCost = std::get<0>(result);
			const float discountOffered = std::get<1>(result);
			std::cout << packages[i].package.GetPackageID() << "  " << discountOffered << "  " << totalCost << std::endl;
		}
		else
		{
			std::cout << "PKG" << i + 1 << " is Invalid." << std::endl;
		}
	}
	return 0;
}


/*
100 3
PKG1 5 5 OFR001
PKG2 15 5 OFR004
PKG3 10 100 OFR003
*/