#pragma once
#include "Window.hpp"

namespace ef
{
	class Keyboard
	{
	public:
		enum Key
		{
			Unknown = -1, A = 0, B, C,
			D, E, F, G,
			H, I, J, K,
			L, M, N, O,
			P, Q, R, S,
			T, U, V, W,
			X, Y, Z, Num0,
			Num1, Num2, Num3, Num4,
			Num5, Num6, Num7, Num8,
			Num9, Escape, LControl, LShift,
			LAlt, LSystem, RControl, RShift,
			RAlt, RSystem, Menu, LBracket,
			RBracket, Semicolon, Comma, Period,
			Quote, Slash, Backslash, Tilde,
			Equal, Hyphen, Space, Enter,
			Backspace, Tab, PageUp, PageDown,
			End, Home, Insert, Delete,
			Add, Subtract, Multiply, Divide,
			Left, Right, Up, Down,
			Numpad0, Numpad1, Numpad2, Numpad3,
			Numpad4, Numpad5, Numpad6, Numpad7,
			Numpad8, Numpad9, F1, F2,
			F3, F4, F5, F6,
			F7, F8, F9, F10,
			F11, F12, F13, F14,
			F15, Pause, KeyCount
		};
	};

	class Mouse
	{
	public:
		enum Button {
  			Left, Right, Middle, XButton1,
  			XButton2, ButtonCount
		};
	};

	/*	Input Manager Class
	*	Manages Window Inputs
	*/
	class InputManager
	{
	private:
		ef::Window* win;

	public:
		/* 	Constructor
		*
		*/
		InputManager();

		/* 	Initializes the Input Manager
		*	@return Returns 0 if suceeded
		*/
		int init(ef::Window* win);

		/*  Tests for a key press
		*	@return Returns true if key is pressed
		*/
		bool isKeyPressed(ef::Keyboard::Key key);

		/*  Tests for a button press
		*	@return Returns true if button is pressed
		*/
		bool isButtonPressed(ef::Mouse::Button button);
	};
}