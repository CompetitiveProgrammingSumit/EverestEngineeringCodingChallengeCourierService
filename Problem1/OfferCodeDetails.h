#pragma once
#include <string>
#include <unordered_map>
#include <unordered_set>
#include "Range.h"

struct OfferCodeDetails
{
	std::string offerCode;
	Range		distanceRange;
	Range		weightRange;
	int			discountPercentageOffered;

	OfferCodeDetails(const std::string& offerCodeName)
	{
		offerCode = offerCodeName;
		distanceRange = offerCodeDistanceRangeMap[offerCodeName];
		weightRange = offerCodeWeightRangeMap[offerCodeName];
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