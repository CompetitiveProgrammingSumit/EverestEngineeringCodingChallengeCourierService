#pragma once

#include <string>

class OfferCodes
{
	public:
		OfferCodes(std::string offerCode) : m_OfferCode(offerCode) {}
		bool IsValidOffer();

		inline const std::string GetOfferCode() const { return m_OfferCode; }

	private:
		std::string		  m_OfferCode;
		const std::string m_ValidOfferCodes[3] = { "OFR001", "OFR002", "OFR003"};
};