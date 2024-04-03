#pragma once

#include <string>
#include <unordered_map>
#include <unordered_set>

struct Range
{
	int lowerLimit;
	int upperLimit;

	Range() : lowerLimit(0), upperLimit(0) {}

	Range(int lowLimit, int uppLimit) : lowerLimit(lowLimit), upperLimit(uppLimit) {}

	const bool IsInRange(int valueToBeChecked, bool isRangeInclusive = true) const
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

	OfferCodeDetails(const std::string& offerCodeName)
	{
		offerCode				  = offerCodeName;
		distanceRange			  = offerCodeDistanceRangeMap[offerCodeName];
		weightRange				  = offerCodeWeightRangeMap[offerCodeName];
		discountPercentageOffered = offerCodeDiscountMap[offerCodeName];
	}

	static std::unordered_set<std::string> offerCodeNamesSet;

	private:
		std::unordered_map<std::string, Range> offerCodeDistanceRangeMap = {
			{"OFR001", Range(0, 200)}, {"OFR002", Range(50, 150)}, {"OFR003", Range(50, 250)}
		};
		std::unordered_map<std::string, Range> offerCodeWeightRangeMap = {
			{"OFR001", Range(70, 200)}, {"OFR002", Range(100, 250)}, {"OFR003", Range(10, 150)}
		};
		std::unordered_map<std::string, int> offerCodeDiscountMap = {
			{"OFR001", 10}, {"OFR002", 7}, {"OFR003", 5}
		};
};


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