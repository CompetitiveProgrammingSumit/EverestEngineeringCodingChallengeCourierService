#pragma once

#include "OfferCodeDetails.h"

class OfferCodes
{
	public:
		OfferCodes(std::string offerCode);

		inline const OfferCodeDetails& GetOfferCodeDetail() const { return m_OfferCode; }

	private:
		std::string						m_OfferCodeName;
		OfferCodeDetails				m_OfferCode;
		std::unordered_set<std::string> m_OfferCodeNamesSet;
		bool IsValidOffer();
};



/*
100 5
PKG1 50 30 OFR001
PKG2 75 125 OFFR0008
PKG3 175 100 OFFR003
PKG4 110 60 OFR002
PKG5 155 95 NA
*/