#pragma once

#include <string>
#include <unordered_map>

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

struct OfferCodeDetails
{
	std::string offerCode;
	Range		distanceRange;
	Range		weightRange;
	int			discountPercentageOffered;

	OfferCodeDetails(const std::string& offerCodeName, const Range& distRange, const Range& wtRange, const int& discountOffered) : offerCode(offerCodeName), distanceRange(distRange), weightRange(wtRange), discountPercentageOffered(discountOffered) {}

	OfferCodeDetails() : offerCode(""), distanceRange(Range(0, 0)), weightRange(Range(0, 0)), discountPercentageOffered(0) {}
};

class OfferCodes
{
	public:
		OfferCodes(std::string offerCode) : m_OfferCode(offerCode) {}
		bool IsValidOffer();

		inline const std::string GetOfferCode() const { return m_OfferCode; }

		inline const OfferCodeDetails& GetOfferCodeDetail() { return m_AvailableOffersMap[m_OfferCode]; }

	private:
		std::string m_OfferCode;
		std::unordered_map<std::string, const OfferCodeDetails> m_AvailableOffersMap = {
			{ "OFR001", OfferCodeDetails("OFR001", Range(0, 200),  Range(70, 200), 10) },
			{ "OFR002", OfferCodeDetails("OFR002", Range(50, 150), Range(100, 250), 7) },
			{ "OFR003", OfferCodeDetails("OFR003", Range(50, 250), Range(10, 150),  5) }
		};
};