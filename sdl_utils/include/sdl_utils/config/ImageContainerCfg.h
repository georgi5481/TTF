#ifndef SDL_UTILS_CONFIG_IMAGECONTAINERCFG_H_
#define SDL_UTILS_CONFIG_IMAGECONTAINERCFG_H_

//C system includes

//C++ system includes
#include<cstdint>
#include<unordered_map>
#include<string>
//3rd-party includes

//Own includes
#include"utils/drawings/Rectangle.h"

//Forward Declaration

struct ImageCfg {
	std::string location;
	int32_t width = 0;
	int32_t height = 0;
};

struct ImageContainerCfg{
	std::unordered_map<int32_t, ImageCfg> imageConfigs;
};



#endif /* SDL_UTILS_CONFIG_IMAGECONTAINERCFG_H_ */
