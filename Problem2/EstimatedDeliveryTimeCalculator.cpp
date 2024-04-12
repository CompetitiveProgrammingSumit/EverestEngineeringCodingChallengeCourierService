#include "EstimatedDeliveryTimeCalculator.h"

void EstimatedDeliveryTimeCalculator::ComputePackageTimeEstimations()
{
	m_remainingPackages = m_NumberOfPackages;
	for (int i = 0; i < m_NumberOfPackages; i++)
	{
		if (m_Packages[i].package.GetPackageWeight() > m_MaxWeight)
		{
			m_Packages[i].package.SetIsDelivered(true);
			m_remainingPackages--;
		}
	}
	CreatePackagesParcelsForDelivery();
}

void EstimatedDeliveryTimeCalculator::CreatePackagesParcelsForDelivery()
{
	int maxWeight = 0;
	int maxWeightIndex = 0;
	std::vector<std::vector<std::pair<int, std::string>>> matrix(m_NumberOfPackages, std::vector<std::pair<int, std::string>>(m_MaxWeight + 1, std::make_pair(INT_MAX, "")));
	matrix[0][m_Packages[0].package.GetPackageWeight()].first = m_Packages[0].package.GetPackageDistance();
	matrix[0][m_Packages[0].package.GetPackageWeight()].second = std::to_string(0) + ",";
	for (int i = 0; i < m_remainingPackages; i++)
	{
		matrix[i][0].first  = 0;
		matrix[i][0].second = "";
	}
	for (int i = 1; i < m_remainingPackages; i++)
	{
		for (int j = 0; j <= m_MaxWeight; j++)
		{
			if (j < m_Packages[i].package.GetPackageWeight())
			{
				matrix[i][j] = matrix[i - 1][j];
				if (matrix[i][j].first != INT_MAX && matrix[i][j].first > maxWeight)
				{
					maxWeight = matrix[i][j].first;
					maxWeightIndex = j;
				}
				continue;
			}
			if (matrix[i][j - m_Packages[i].package.GetPackageWeight()].first != INT_MAX && matrix[i][j - m_Packages[i].package.GetPackageWeight()].first + m_Packages[i].package.GetPackageDistance() < matrix[i - 1][j].first)
			{
				matrix[i][j].first  = matrix[i][j - m_Packages[i].package.GetPackageWeight()].first + m_Packages[i].package.GetPackageDistance();
				matrix[i][j].second = matrix[i][j - m_Packages[i].package.GetPackageWeight()].second + std::to_string(i) + ",";
			}
			else
			{
				matrix[i][j] = matrix[i - 1][j];
			}
			if (matrix[i][j].first != INT_MAX && matrix[i][j].first > maxWeight)
			{
				maxWeight = matrix[i][j].first;
				maxWeightIndex = j;
			}
		}
	}
}
