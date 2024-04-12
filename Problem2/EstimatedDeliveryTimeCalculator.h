#pragma once
#include <algorithm>
#include "Package.h"
#include "OptionalPackage.h"

class EstimatedDeliveryTimeCalculator
{
	public:
		EstimatedDeliveryTimeCalculator(std::vector<OptionalPackage>& packages, int numberOfVehicles, int maxSpeed, int maxWeight, int numberOfPackages) : m_Packages(packages), m_MaxSpeed(maxSpeed), m_MaxWeight(maxWeight), m_NumberOfPackages(numberOfPackages)
		{
			ComputePackageTimeEstimations();
		}
	
	private:
		std::vector<OptionalPackage> m_Packages;
		int							 m_NumberOfVehicles;
		int							 m_MaxSpeed;
		int							 m_MaxWeight;
		int							 m_NumberOfPackages;
		int							 m_remainingPackages;

		void ComputePackageTimeEstimations();
		void CreatePackagesParcelsForDelivery();
};