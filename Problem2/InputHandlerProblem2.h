#pragma once
#include "InputHandler.h"

class InputHandlerProblem2 : public InputHandler
{
	public:
		InputHandlerProblem2();

		inline const int& GetNumberOfVehicles() const { return m_NumberOfVehicles; }
		inline const int& GetMaxSpeed() const { return m_MaxSpeed; }
		inline const int& GetMaxWeight() const { return m_MaxWeight; }

	private:
		int m_NumberOfVehicles;
		int m_MaxSpeed;
		int m_MaxWeight;

		void InputVehiclesDetails();
};