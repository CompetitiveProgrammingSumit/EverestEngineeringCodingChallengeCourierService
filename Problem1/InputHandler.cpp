#include "InputHandler.h"

InputHandler::InputHandler()
{
	m_shouldBePackageID = 0;
	std::string inputString;
	std::cin >> m_BaseDeliveryCost;
	std::cin >> m_NumberOfPackages;

	int i = 0;
	while(i < m_NumberOfPackages)
	{
		std::getline(std::cin, inputString);
		if (!inputString.empty())
		{
			m_PackagesDataArray.push_back(inputString);
			i++;
		}
	}
	ParseData();
}

void InputHandler::ParseData()
{
	std::vector<std::vector<std::string>> dataArray;
	for (int i = 0; i < m_NumberOfPackages; i++)
	{
		dataArray.push_back(SeperateData(m_PackagesDataArray[i]));
	}
	
	for (int i = 0; i < m_NumberOfPackages; i++)
	{
		int packageWeight   = std::atoi(dataArray[i][1].c_str());
		int packageDistance = std::atoi(dataArray[i][2].c_str());
		Package newPackage(dataArray[i][0], packageWeight, packageDistance, dataArray[i][3]);
		if (newPackage.IsValidPackage(i + 1))
		{
			m_ValidPackages.push_back(newPackage);
		}
		else
		{
			//TODO: - Handle Error in case of invalid Input.
			//Call Lambda which is implemented in Main
		}
	}
}

std::vector<std::string> InputHandler::SeperateData(const std::string& str, char delimiter)
{
	std::vector<std::string> result;
	int						 index	   = 0;
	std::string				 newString = "";
	while (str[index] != '\0')
	{
		if (str[index] == delimiter)
		{
			if (!newString.empty()) { result.push_back(newString); }
			newString = "";
			index++;
			continue;
		}
		newString += str[index];
		index++;
	}
	if (!newString.empty()) { result.push_back(newString); }
	return result;
}

void InputHandler::PrintInput(std::vector<std::string> singleInputArray)
{
	for (std::string str : singleInputArray)
	{
		std::cout << str << std::endl;
	}
	std::cout << "---------------------------" << std::endl;
}
