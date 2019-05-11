#include "MiniginPCH.h"
#include "InputManager.h"
#include <SDL.h>
#include <iostream>
#include <algorithm>

dae::InputManager::~InputManager()
{
	std::for_each(m_ButtonCommands.begin(), m_ButtonCommands.end(),
		[](auto pair) { delete pair.second; });
}

void dae::InputManager::ProcessInput()
{
	ZeroMemory(&m_State, sizeof(XINPUT_STATE));
	XInputGetState(0, &m_State);

	std::for_each(m_ButtonCommands.begin(), m_ButtonCommands.end(),
		[this](std::pair<ControllerButton, Command*> pair) { if (IsPressed(pair.first)) pair.second->Execute(); });
}

bool dae::InputManager::IsPressed(ControllerButton button) const
{
	return ((m_State.Gamepad.wButtons & (WORD)button) != 0);
}

void dae::InputManager::AssignButton(ControllerButton button, Command* command)
{
	m_ButtonCommands[button] = command;
}
