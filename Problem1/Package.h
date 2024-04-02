#pragma once

#include "OfferCodes.h"

class Package
{
	public:
		Package(std::string packageID, int packageWeight, int distance, std::string offerCode) : m_PackageID(packageID), m_PackageWeightInKG(packageWeight), m_DistanceInKM(distance), m_OfferCode(OfferCodes(offerCode)) {}

		bool IsValidPackage(int id);

	private:
		std::string m_PackageID;
		int			m_PackageWeightInKG;
		int			m_DistanceInKM;
		OfferCodes	m_OfferCode;

		bool IsValidPackageID(int id);
};