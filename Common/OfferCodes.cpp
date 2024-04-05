#include "OfferCodes.h"

OfferCodes::OfferCodes(std::string offerCode) : m_OfferCodeName(offerCode), m_OfferCodeNamesSet(OfferCodeDetails::offerCodeNamesSet)
{
	m_OfferCode = IsValidOffer() ? OfferCodeDetails(offerCode) : OfferCodeDetails();
	/*if (!IsValidOffer())
	{
		m_OfferCode = OfferCodeDetails();
	}
	else
	{
		m_OfferCode = OfferCodeDetails(offerCode);
	}*/
}

bool OfferCodes::IsValidOffer()
{
	return m_OfferCodeNamesSet.find(m_OfferCodeName) != m_OfferCodeNamesSet.end();
	/*if (m_OfferCodeNamesSet.find(m_OfferCodeName) != m_OfferCodeNamesSet.end()) { return true; }
	return false;*/
}
