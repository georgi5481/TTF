#ifndef SDL_UTILS_CONTAINERS_IMAGECONTAINER_H_
#define SDL_UTILS_CONTAINERS_IMAGECONTAINER_H_

//C system includes

//C++ system includes
#include<cstdint>
#include<unordered_map>
//3rd-party includes

//Own includes
#include "utils/drawings/Rectangle.h"
#include "utils/config/ImageContainerCfg.h"

//Forward Declaration

struct SDL_Texture;

class ImageContainer {
public:

	int32_t init(const ImageContainerCfg& cfg);
	int32_t deinit();


	SDL_Texture* getImageTexture(int32_t rsrcId) const;	//will basically search in the map below ( _textures )

	Rectangle getImageFrame(int32_t rsrcId) const;		//this one will search in the other map below ( _textureFrames )
private:
	std::unordered_map<int32_t, SDL_Texture*> _textures;

	std::unordered_map<int32_t, Rectangle> _textureFrames;


};

#endif /* SDL_UTILS_CONTAINERS_IMAGECONTAINER_H_ */
