#include "OfferCodes.h"

bool OfferCodes::IsValidOffer()
{
	if (m_OfferCodeNamesSet.find(m_OfferCodeName) != m_OfferCodeNamesSet.end()) { return true; }
	return false;
}
