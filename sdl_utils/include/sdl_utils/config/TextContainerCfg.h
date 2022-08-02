#ifndef SDL_UTILS_CONFIG_TEXTCONTAINERCFG_H_
#define SDL_UTILS_CONFIG_TEXTCONTAINERCFG_H_

//C system includes

//C++ system includes
#include<cstdint>
#include<unordered_map>
#include<string>
//3rd-party includes

//Own includes

//Forward Declaration

struct FontCfg {
	std::string location;
	int32_t fontSize;
};

struct TextContainerCfg{
	std::unordered_map<int32_t, FontCfg> fontConfigs;
};



#endif /* SDL_UTILS_CONFIG_TEXTCONTAINERCFG_H_ */
