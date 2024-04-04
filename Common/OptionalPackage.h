#pragma once

#include <string>
#include "Package.h"

struct OptionalPackage
{
	bool		isValidPackage = true;
	std::string invalidPackageReason = "";
	Package		package;

	OptionalPackage(Package pkg) : package(pkg) {}
	OptionalPackage(std::string reason = "") : isValidPackage(false), invalidPackageReason(reason), package(Package("", -1, -1, "")) {}
};