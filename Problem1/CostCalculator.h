#pragma once
#include "../Common/Package.h"

class CostCalculator
{
	private:
		static CostCalculator* _CostCalulatorInstance;

		CostCalculator() {}

		const float CalculateDiscount(const Package& package, const float& totalCost);

	public:
		CostCalculator(const CostCalculator& costCalculatorObject) = delete;
		static CostCalculator* SharedInstance();
		const std::tuple<const float, const float> CalculateCost(Package& package, const int& baseDeliveryCost);
};
