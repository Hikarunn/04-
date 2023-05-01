#pragma once
#include <type_traits>

// �L�[���
enum class InputID
{
	Jump,
	Attack,
	MainTriger1,
	MainTriger2,
	MainTriger3,
	MainTriger4,
	SubTriger1,
	SubTriger2,
	SubTriger3,
	SubTriger4,
	LockOn,
	CameraFlont,
	Max
};

static InputID begin(InputID) { return InputID::Jump; }
static InputID end(InputID) { return InputID::Max; }
static InputID operator++(InputID& state) { return (state = static_cast<InputID>(std::underlying_type<InputID>::type(state) + 1)); }
static InputID operator*(const InputID& state) { return state; }
