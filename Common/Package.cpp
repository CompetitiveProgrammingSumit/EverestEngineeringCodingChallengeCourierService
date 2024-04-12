#include "Package.h"

bool Package::IsValidPackage(int id)
{
	return IsValidPackageID(id);
	/*if (m_OfferCode.IsValidOffer() && IsValidPackageID(id)) { return true; }
	return false;*/
}

void Package::SetTotalCost(float totalCost)
{
	m_TotalCost = totalCost;
}

void Package::SetDiscountOffered(float discountOffered)
{
	m_DiscountOffered = discountOffered;
}

void Package::SetEstimatedDeliveryTimeInHours(float deliveryTime)
{
	m_estimatedDeliveryTimeInHours = deliveryTime;
}

void Package::SetIsDelivered(bool isDelivered)
{
	m_IsDelivered = isDelivered;
}

bool Package::IsValidPackageID(int id)
{
	if (m_PackageWeightInKG < 0 || m_DistanceInKM < 0) { return false; }
	int  packageIdLength = (int)m_PackageID.length();
	char initials[3]	 = { 'P', 'K', 'G' };
	int  idInInt		 = 0;
	if (packageIdLength < 4) { return false; }
	for (int i = 0; i < 3; i++)
	{
		if (m_PackageID[i] != initials[i]) { return false; }
	}
	for (int i = 3; i < packageIdLength; i++)
	{
		if (m_PackageID[i] < '0' || m_PackageID[i] > '9') { return false; }
		idInInt = (idInInt * 10) + (m_PackageID[i] - '0');
	}
	return (idInInt == id);
}
