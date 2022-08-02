#ifndef SDL_UTILS_CONTAINERS_IMAGECONTAINER_H_
#define SDL_UTILS_CONTAINERS_IMAGECONTAINER_H_

//C system includes

//C++ system includes
#include<cstdint>
#include<unordered_map>
//3rd-party includes

//Own includes
#include "utils/drawings/Rectangle.h"
#include "sdl_utils/config/ImageContainerCfg.h"

//Forward Declaration

struct SDL_Texture;

class ImageContainer {
public:

	int32_t init(const ImageContainerCfg& cfg);
	int32_t deinit();


	SDL_Texture* getImageTexture(int32_t rsrcId) const;	//will basically search in the map below ( _textures )

	Rectangle getImageFrame(int32_t rsrcId) const;		//this one will search in the other map below for the pixel frame ( _textureFrames )
private:

	int32_t loadSingleResource(const ImageCfg& resCfg, int32_t rsrcId);

	std::unordered_map<int32_t, SDL_Texture*> _textures;	//in the first we are saving the ID and the texture

	std::unordered_map<int32_t, Rectangle> _textureFrames;	//in the second we are saving the ID and the rectangle dimensions


};

#endif /* SDL_UTILS_CONTAINERS_IMAGECONTAINER_H_ */
