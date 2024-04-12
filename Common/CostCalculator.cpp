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

void CostCalculator::CalculateCost(Package& package, const int& baseDeliveryCost)
{
	float totalCostIncurred = (float)(baseDeliveryCost + (package.GetPackageWeight() * 10) + (package.GetPackageDistance() * 5));
	const float discount = CalculateDiscount(package, totalCostIncurred);
	package.SetTotalCost(totalCostIncurred - discount);
	package.SetDiscountOffered(discount);
}

const float CostCalculator::CalculateDiscount(Package& package, const float& totalCost)
{
	const OfferCodeDetails offerCodeDetails = package.GetOfferCode().GetOfferCodeDetail();
	const int packageDistance				= package.GetPackageDistance();
	const int packageWeight					= package.GetPackageWeight();
	if (offerCodeDetails.distanceRange.IsInRange(packageDistance) && offerCodeDetails.weightRange.IsInRange(packageWeight))
	{
		return (offerCodeDetails.discountPercentageOffered * 0.01f * totalCost);
	}
	return 0;
}
