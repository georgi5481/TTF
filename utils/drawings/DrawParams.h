#ifndef UTILS_DRAWINGS_DRAWPARAMS_H_
#define UTILS_DRAWINGS_DRAWPARAMS_H_

//C system includes

//C++ system includes
#include<cstdint>

//3rd-party includes

//Own includes
#include "utils/drawings/Point.h"

//Forward Declaration


/*basically the next variable shouldnt be declared in the .h file, BUT
 *in c++ 17 the 'inline' declaration means - no matter how many times we include the .h file
 *we will always have only one instanse of the variable*/
inline constexpr auto INVALID_RSRC_ID = -1;
inline constexpr auto FULL_OPACITY = 255;
inline constexpr auto ZERO_OPACITY = 0;


enum class BlendMode: uint8_t {	//instead of using normal int, this way we can force the enum to be from uint8_t
	NONE = 0,	//Values for SDL_BLENDMODE_NONE
	BLEND = 1,	//SDL_BLENDMODE_BLEND
	ADD = 2,	//SDL_BLENDMODE_ADD
	MOD = 4 	//SDL_BLENDMODE_MODE
};



struct DrawParams {
	//Where to place the texture position on the screen.
	Point pos = Point::UNDEFINED;

	//Draw dimensions of the texture
	int32_t width = 0;
	int32_t height = 0;

	int32_t opacity = FULL_OPACITY;	//opacity is 8bit int, but in order not to cast it every time we use the int32

	union{
	//unique resourceId
	int32_t rsrcId = INVALID_RSRC_ID;
	//unique Id for the texts
	int32_t textId ;
	};

};



#endif /* UTILS_DRAWINGS_DRAWPARAMS_H_ */
