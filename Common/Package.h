#pragma once

#include "OfferCodes.h"

class Package
{
	public:
		Package(std::string packageID, int packageWeight, int distance, std::string offerCode) : m_PackageID(packageID), m_PackageWeightInKG(packageWeight), m_DistanceInKM(distance), m_OfferCode(OfferCodes(offerCode)) {}

		bool IsValidPackage(int id);

		void SetTotalCost(float totalCost);
		void SetDiscountOffered(float discountOffered);
		void SetEstimatedDeliveryTimeInHours(float deliveryTime);

		inline const std::string& GetPackageID()	   const { return m_PackageID; }
		inline const int& GetPackageWeight()		   const { return m_PackageWeightInKG; }
		inline const int& GetPackageDistance()		   const { return m_DistanceInKM; }
		inline const OfferCodes& GetOfferCode()		   const { return m_OfferCode; }
		inline const float& GetTotalCost()			   const { return m_TotalCost; }
		inline const float& GetDiscountOffered()	   const { return m_DiscountOffered; }
		inline const float& GetEstimatedDeliveryTime() const { return m_estimatedDeliveryTimeInHours; }

	private:
		std::string m_PackageID;
		int			m_PackageWeightInKG;
		int			m_DistanceInKM;
		OfferCodes	m_OfferCode;

		float m_TotalCost;
		float m_DiscountOffered;
		float m_estimatedDeliveryTimeInHours;

		bool IsValidPackageID(int id);
};