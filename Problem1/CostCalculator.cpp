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

int CostCalculator::CalculateCost(const Package& package, const int& baseDeliveryCost)
{
	int totalCostIncurred = baseDeliveryCost + (package.GetPackageWeight() * 10) + (package.GetPackageDistance() * 5);
	return totalCostIncurred;
}
