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

const std::tuple<const float, const float> CostCalculator::CalculateCost(Package& package, const int& baseDeliveryCost)
{
	float totalCostIncurred = baseDeliveryCost + (package.GetPackageWeight() * 10) + (package.GetPackageDistance() * 5);
	const float discount = CalculateDiscount(package, totalCostIncurred);
	return std::make_tuple(totalCostIncurred - discount, discount);
}

const float CostCalculator::CalculateDiscount(const Package& package, const float& totalCost)
{
	const OfferCodeDetails offerCodeDetails = package.GetOfferCode().GetOfferCodeDetail();
	const int packageDistance				= package.GetPackageDistance();
	const int packageWeight					= package.GetPackageWeight();
	if (offerCodeDetails.distanceRange.IsInRange(packageDistance) && offerCodeDetails.weightRange.IsInRange(packageWeight))
	{
		return (offerCodeDetails.discountPercentageOffered * 0.01 * totalCost);
	}
	return 0;
}
