#include "sltpch.h"
#include "InputManager.h"

namespace Scarlett {

InputManager::InputManager()
{
	m_input = std::unique_ptr<Input>(Input::Create());
}

void InputManager::PollInput()
{
	m_input->PollInput();
}

bool InputManager::IsKeyPressed(uint16 keyId)
{
	auto it = m_keyMap.find(keyId);

	return it != m_keyMap.end() ? it->second : false;
}

}