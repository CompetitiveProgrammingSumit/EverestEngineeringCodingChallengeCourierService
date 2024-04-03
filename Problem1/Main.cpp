#include "InputHandler.h"
#include "CostCalculator.h"
std::unordered_set<std::string> OfferCodeDetails::offerCodeNamesSet = { "OFR001", "OFR002", "OFR003" };

int main()
{
	InputHandler		 inputHandler;
	std::vector<Package> packages = inputHandler.GetPackages();
	
	for (int i = 0; i < inputHandler.GetNumberOfPackages(); i++)
	{
		const std::tuple<const float, const float> result = CostCalculator::SharedInstance()->CalculateCost(packages[i], inputHandler.GetBaseDeliveryCost());
		const float totalCost		= std::get<0>(result);
		const float discountOffered = std::get<1>(result);
		std::cout << packages[i].GetOfferCode().GetOfferCodeDetail().offerCode << " " << discountOffered << " " << totalCost << std::endl;
	}
	return 0;
}