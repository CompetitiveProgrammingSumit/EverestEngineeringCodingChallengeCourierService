#include "InputHandlerProblem2.h"
#include "CostCalculator.h"
#include "EstimatedDeliveryTimeCalculator.h"

void Print(std::vector<OptionalPackage> packages)
{
	for (OptionalPackage package : packages)
	{
		std::cout << package.package.GetPackageID() << "  " << package.package.GetPackageWeight() << "  " << package.package.GetPackageDistance() << "  " << package.package.GetOfferCode().GetOfferCodeDetail().offerCode << std::endl;
	}
}


bool Compare(OptionalPackage first, OptionalPackage second)
{
	if (first.package.GetPackageWeight() == second.package.GetPackageWeight())
	{
		return first.package.GetPackageDistance() < second.package.GetPackageDistance();
	}
	return first.package.GetPackageWeight() < second.package.GetPackageWeight();
}

void Solution()
{
	InputHandlerProblem2		 inputHandler;
	std::vector<OptionalPackage> packages = inputHandler.GetPackages();

	//std::sort(packages.begin(), packages.end(), Compare);
	//Print(packages);
	EstimatedDeliveryTimeCalculator estimatedDeliveryTimeCalculator(packages, inputHandler.GetNumberOfVehicles(), inputHandler.GetMaxSpeed(), inputHandler.GetMaxWeight(), inputHandler.GetNumberOfPackages());
}

int main()
{
	Solution();
	/*InputHandlerProblem2		 inputHandler;
	std::vector<OptionalPackage> packages = inputHandler.GetPackages();

	for (int i = 0; i < inputHandler.GetNumberOfPackages(); i++)
	{
		if (packages[i].isValidPackage)
		{
			CostCalculator::SharedInstance()->CalculateCost(packages[i].package, inputHandler.GetBaseDeliveryCost());
			std::cout << packages[i].package.GetPackageID() << "  " << packages[i].package.GetDiscountOffered() << "  " << packages[i].package.GetTotalCost() << std::endl;
		}
		else
		{
			std::cout << "PKG" << i + 1 << " is Invalid." << std::endl;
		}
	}*/
	return 0;
}



/*
100 5
PKG1 50 30 OFR001
PKG2 75 125 OFFR0008
PKG3 175 100 OFR003
PKG4 110 60 OFR002
PKG5 155 95 NA
2 70 200

----Sorted----
ID	  WT   DIST  CODE
PKG3  175  100   OFR003
PKG5  155  95    NA
PKG4  110  60    OFR002
PKG2  75   125   NA
PKG1  50   30	 OFR001


----Same weight eg----
100 5
PKG1 50 30 OFR001
PKG2 75 125 OFFR0008
PKG3 110 100 OFR003
PKG4 110 60 OFR002
PKG5 155 95 NA
2 70 200

----Sorted----
PKG5  155  95  NA
PKG4  110  60  OFR002
PKG3  110  100  OFR003
PKG2  75  125  NA
PKG1  50  30  OFR001
*/
