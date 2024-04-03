#pragma once

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