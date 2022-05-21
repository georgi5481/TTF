#ifndef SDL_UTILS_CONTAINERS_IMAGECONTAINER_H_
#define SDL_UTILS_CONTAINERS_IMAGECONTAINER_H_

//C system includes

//C++ system includes
#include<cstdint>
#include<unordered_map>
//3rd-party includes

//Own includes
#include "utils/drawings/Rectangle.h"
//Forward Declaration

struct SDL_Texture;

class ImageContainer {
private:
	std::unordered_map<int32_t, SDL_Texture*> _textures;

	std::unordered_map<int32_t, Rectangle*> _textureFrames;


};

#endif /* SDL_UTILS_CONTAINERS_IMAGECONTAINER_H_ */
