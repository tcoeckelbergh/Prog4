#pragma once
#include <XInput.h>
#include "Singleton.h"
#include "Command.h"
#include <unordered_map>

namespace dae
{
	enum class ControllerButton
	{
		ButtonA = XINPUT_GAMEPAD_A,
		ButtonB = XINPUT_GAMEPAD_B,
		ButtonX = XINPUT_GAMEPAD_X,
		ButtonY = XINPUT_GAMEPAD_Y
	};

	class InputManager : public Singleton<InputManager>
	{
	public:
		~InputManager();

		void ProcessInput();
		bool IsPressed(ControllerButton button) const;
		void AssignButton(ControllerButton button, Command* command);

	private:
		XINPUT_STATE m_State;
		std::unordered_map<ControllerButton, Command*> m_ButtonCommands;
	};
}