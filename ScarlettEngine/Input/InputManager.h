#pragma once

#include "Input.h"
// TODO (Christian): think about how mulitiple api might have different keyID
// Question (Christian): Should input manager be singleton? if so multi-threadding?
// Question (Christian): Is the different api classes too much and slower? Does it work?
namespace Scarlett {
class InputManager
{
public:
	InputManager();
	~InputManager() { }

	inline void Create() { m_input = std::unique_ptr<Input>(Input::Create()); };

	void PollInput();

	inline void PressKey(uint16 keyId)		{ m_keyMap[keyId] = true; }
	inline void ReleaseKey(uint16 keyId)		{ m_keyMap[keyId] = false; }

	bool IsKeyPressed(uint16 keyId);
private:
	std::unordered_map<uint16, bool> m_keyMap;
	std::unique_ptr<Input> m_input;
};
}
