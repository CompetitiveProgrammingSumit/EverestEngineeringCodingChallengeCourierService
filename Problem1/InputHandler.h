#pragma once

#include <iostream>
#include <vector>
#include "Package.h"

struct OptionalPackage
{
	bool		isValidPackage = true;
	std::string invalidPackageReason = "";
	Package		package;

	OptionalPackage(Package pkg) : package(pkg) {}
	OptionalPackage(std::string reason = "") : isValidPackage(false), invalidPackageReason(reason), package(Package("", -1, -1, "")) {}
};

class InputHandler
{
	public:
		InputHandler();

		inline const std::vector<OptionalPackage> GetPackages() const { return m_ValidPackages;	   }
		inline const int& GetBaseDeliveryCost()	const				  { return m_BaseDeliveryCost; }
		inline const int& GetNumberOfPackages()	const				  { return m_NumberOfPackages; }

	private:
		int							 m_BaseDeliveryCost;
		int							 m_NumberOfPackages;
		std::vector<std::string>	 m_PackagesDataArray;
		int							 m_shouldBePackageID;
		std::vector<OptionalPackage> m_ValidPackages;

		void ParseData();
		std::vector<std::string> SeperateData(const std::string& str, char delimiter = ' ');
		void PrintInput(std::vector<std::string> singleInputArray);
};