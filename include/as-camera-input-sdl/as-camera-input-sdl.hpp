#pragma once

#include <as-camera-input/as-camera-input.hpp>

union SDL_Event;
struct SDL_MouseButtonEvent;

namespace asci_sdl
{

asci::InputEvent sdlToInput(const SDL_Event* event);
asci::MouseButton mouseFromSdl(const SDL_MouseButtonEvent* event);
asci::KeyboardButton keyboardFromSdl(int key);

} // namespace asci_sdl
