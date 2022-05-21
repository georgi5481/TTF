#ifndef UTILS_DRAWINGS_DRAWPARAMS_H_
#define UTILS_DRAWINGS_DRAWPARAMS_H_

//C system includes

//C++ system includes
#include<cstdint>

//3rd-party includes

//Own includes
#include "utils/drawings/Point.h"

//Forward Declaration


struct DrawParams {
	// Top left position of texture
	Point pos = Point::UNDEFINED;

	//Draw dimensions of the texture
	int32_t width = 0;
	int32_t height = 0;

	//unique resourceId
	int32_t rsrcId = -1;
};



#endif /* UTILS_DRAWINGS_DRAWPARAMS_H_ */
