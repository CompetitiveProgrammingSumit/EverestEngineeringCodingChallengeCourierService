#pragma once

#include "OfferCodeDetails.h"

class OfferCodes
{
	public:
		OfferCodes(std::string offerCode) : m_OfferCodeName(offerCode), m_OfferCode(OfferCodeDetails(offerCode)), m_OfferCodeNamesSet(OfferCodeDetails::offerCodeNamesSet) {}

		bool IsValidOffer();

		inline const OfferCodeDetails& GetOfferCodeDetail() const { return m_OfferCode; }

	private:
		std::string						m_OfferCodeName;
		OfferCodeDetails				m_OfferCode;
		std::unordered_set<std::string> m_OfferCodeNamesSet;
};