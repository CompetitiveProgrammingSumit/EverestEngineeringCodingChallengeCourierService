#include "OfferCodes.h"

bool OfferCodes::IsValidOffer()
{
	for (int i = 0; i < 3; i++)
	{
		if (m_AvailableOffers[i].offerCode == m_OfferCode) { return true; }
	}
	return false;
}
