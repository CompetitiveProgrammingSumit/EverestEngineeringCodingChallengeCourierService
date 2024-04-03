#pragma once

#include <string>

struct Range
{
	int lowerLimit;
	int upperLimit;

	Range(int lowLimit, int uppLimit) : lowerLimit(lowLimit), upperLimit(uppLimit) {}

	bool IsInRange(int valueToBeChecked, bool isRangeInclusive = true)
	{
		return (valueToBeChecked > lowerLimit - isRangeInclusive && valueToBeChecked < upperLimit + isRangeInclusive);
	}
};

class OfferCodes
{
	public:
		OfferCodes(std::string offerCode) : m_OfferCode(offerCode) {}
		bool IsValidOffer();

		inline const std::string GetOfferCode() const { return m_OfferCode; }

	private:
		struct OfferCodeDetails
		{
			std::string offerCode;
			Range		distanceRange;
			Range		weightRange;
			int			discountPercentageOffered;

			OfferCodeDetails(const std::string& offerCodeName, const Range& distRange, const Range& wtRange, const int& discountOffered) : offerCode(offerCodeName), distanceRange(distRange), weightRange(wtRange), discountPercentageOffered(discountOffered) {}
		};
		std::string		  m_OfferCode;
		const OfferCodeDetails m_AvailableOffers[3] = {
				OfferCodeDetails("OFR001", Range(0, 200),  Range(70, 200), 10),
				OfferCodeDetails("OFR002", Range(50, 150), Range(100, 250), 7),
				OfferCodeDetails("OFR003", Range(50, 250), Range(10, 150),  5)
		};
};