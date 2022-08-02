//Corresponding header
#include "sdl_utils/InputEvent.h"

//C system includes

//C++ system includes
#include<iostream>
#include<cstring>

//3rd-party includes
#include<SDL_events.h>

//Own includes

//Forward Declaration


int32_t InputEvent::init(){
	_sdlEvent = new SDL_Event();
	memset(_sdlEvent, 0, sizeof(SDL_Event));
	if(_sdlEvent == nullptr){

		std::cerr << "Bad aloc for SDL_Event()" << std::endl;
	}

	return EXIT_SUCCESS;
}

void InputEvent::deinit(){

	if(_sdlEvent != nullptr){
		delete _sdlEvent;
		_sdlEvent = nullptr;
	}
}

bool InputEvent::pollEvent(){
	if(SDL_PollEvent(_sdlEvent) == 0){
		//no events currently
		return false;
	}

	SDL_GetMouseState(&pos.x,&pos.y);
	setEventTypeInternal();
	return true;
}



void InputEvent::setEventTypeInternal(){
	switch(_sdlEvent->type){
	case EventType::KEYBOARD_PRESS:
		key = _sdlEvent->key.keysym.sym;	//will scan the key that was pressed
		mouseButton = Mouse::UNKNOWN;
		type = TouchEvent::KEYBOARD_PRESS;
	break;

	case EventType::KEYBOARD_RELEASE:
		key = _sdlEvent->key.keysym.sym;	//will scan the key that was pressed
		mouseButton = Mouse::UNKNOWN;
		type = TouchEvent::KEYBOARD_RELEASE;
		break;

	case EventType::MOUSE_PRESS:
		key = Keyboard::KEY_UNKNOWN;
		mouseButton = _sdlEvent->button.button;
		type = TouchEvent::TOUCH_PRESS;
		break;

	case EventType::FINGER_PRESS:
		key = Keyboard::KEY_UNKNOWN;
		mouseButton = Mouse::UNKNOWN;
		type = TouchEvent::TOUCH_PRESS;
		break;

	case EventType::MOUSE_RELEASE:
		key = Keyboard::KEY_UNKNOWN;	//will scan the key that was pressed
		mouseButton = _sdlEvent->button.button;
		type = TouchEvent::TOUCH_RELEASE;
		break;

	case EventType::FINGER_RELEASE:
		key = Keyboard::KEY_UNKNOWN;
		mouseButton = _sdlEvent->button.button;
		type = TouchEvent::TOUCH_RELEASE;
		break;

		//X is pressed on the window(or CTRL-C signal is sent)
	case EventType::QUIT:
		type = TouchEvent::UNKNOWN;
		key = Keyboard::KEY_UNKNOWN;
		mouseButton = Mouse::UNKNOWN;
		break;

	default:
		key = Keyboard::KEY_UNKNOWN;
		mouseButton = Mouse::UNKNOWN;
		type = TouchEvent::UNKNOWN;
		break;
	}
}


bool InputEvent::checkForExitRequiest()const{

return  EventType::QUIT == _sdlEvent->type || Keyboard::KEY_ESCAPE == key;
}
