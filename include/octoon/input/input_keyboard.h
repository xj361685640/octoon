#ifndef OCTOON_INPUT_KEYBOARD_H_
#define OCTOON_INPUT_KEYBOARD_H_

#include <octoon/input/iinput_keyboard.h>

namespace octoon
{
	namespace input
	{
		class OCTOON_EXPORT DefaultInputKeyboard : public IInputKeyboard
		{
			OctoonDeclareSubInterface(DefaultInputKeyboard, IInputKeyboard)
		public:
			DefaultInputKeyboard() noexcept;
			virtual ~DefaultInputKeyboard() noexcept;

			virtual bool is_key_down(InputKey::Code key) const noexcept;
			virtual bool is_key_up(InputKey::Code key) const noexcept;
			virtual bool is_key_pressed(InputKey::Code key) const noexcept;

			virtual InputKeyboardPtr clone() const noexcept;

		protected:
			virtual void on_frame_end() noexcept;
			virtual void on_obtain_capture() noexcept;
			virtual void on_reset() noexcept;

			virtual void on_input_event(const InputEvent& event) noexcept;

		private:
			DefaultInputKeyboard(const DefaultInputKeyboard&) noexcept = delete;
			DefaultInputKeyboard& operator=(const DefaultInputKeyboard&) noexcept = delete;

		private:
			struct KeyState
			{
				bool pressed;
				bool down;
				bool up;
			};

			KeyState key_state_[InputKey::NumKeyCodes];
		};
	}
}

#endif