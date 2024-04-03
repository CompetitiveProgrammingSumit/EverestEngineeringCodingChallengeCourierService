#include "CostCalculator.h"

CostCalculator* CostCalculator::_CostCalulatorInstance = NULL;

CostCalculator* CostCalculator::SharedInstance()
{
	if (_CostCalulatorInstance == NULL)
	{
		_CostCalulatorInstance = new CostCalculator();
	}
	return _CostCalulatorInstance;
}

int CostCalculator::CalculateCost(Package& package, const int& baseDeliveryCost)
{
	int totalCostIncurred = baseDeliveryCost + (package.GetPackageWeight() * 10) + (package.GetPackageDistance() * 5);
	const OfferCodeDetails offerCodeDetail = package.GetOfferCode().GetOfferCodeDetail();
	return totalCostIncurred;
}
