#ifndef ENGINE_CONFIG_ENGINECONFIG_H_
#define ENGINE_CONFIG_ENGINECONFIG_H_

//C system includes

//C++ system includes
#include<cstdint>

//3rd-party includes

//Own includes
#include "sdl_utils/config/MonitorWindowCfg.h"
#include "sdl_utils/config/ImageContainerCfg.h"
#include "Game/config/GameCfg.h"

//Forward Declaration


struct EngineConfig{
	MonitorWindowCfg windowCfg;
	//soon to populate other configs
	ImageContainerCfg imageContainerCfg;
;
};



#endif /* ENGINE_CONFIG_ENGINECONFIG_H_ */
