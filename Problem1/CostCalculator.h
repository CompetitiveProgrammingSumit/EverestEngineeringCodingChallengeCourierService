#pragma once
#include "Package.h"

class CostCalculator
{
	private:
		static CostCalculator* _CostCalulatorInstance;

		CostCalculator() {}

	public:
		CostCalculator(const CostCalculator& costCalculatorObject) = delete;
		static CostCalculator* SharedInstance();

		int CalculateCost(Package& package, const int& baseDeliveryCost);
};
