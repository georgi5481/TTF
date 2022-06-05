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


struct DrawParams {
	// Top left position of texture
	Point pos = Point::UNDEFINED;

	//Draw dimensions of the texture
	int32_t width = 0;
	int32_t height = 0;

	//unique resourceId
	int32_t rsrcId = INVALID_RSRC_ID;
};



#endif /* UTILS_DRAWINGS_DRAWPARAMS_H_ */
