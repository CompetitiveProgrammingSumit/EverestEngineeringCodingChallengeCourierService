#pragma once
#include "Package.h"

class CostCalculator
{
	private:
		static CostCalculator* _CostCalulatorInstance;

		CostCalculator() {}

		const float CalculateDiscount(Package& package, const float& totalCost);

	public:
		CostCalculator(const CostCalculator& costCalculatorObject) = delete;
		static CostCalculator* SharedInstance();
		void CalculateCost(Package& package, const int& baseDeliveryCost);
};
