#include "OfferCodes.h"

bool OfferCodes::IsValidOffer()
{
	if (m_AvailableOffersMap.find(m_OfferCode) != m_AvailableOffersMap.end()) { return true; }
	return false;
}
