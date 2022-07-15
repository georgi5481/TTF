#ifndef ENGINE_CONFIG_ENGINECONFIG_H_populateTextContainerConfig
#define ENGINE_CONFIG_ENGINECONFIG_H_

//C system includes

//C++ system includes
#include<cstdint>

//3rd-party includes

//Own includes
#include "sdl_utils/config/MonitorWindowCfg.h"
#include "sdl_utils/config/ImageContainerCfg.h"
#include "sdl_utils/config/TextContainerCfg.h"
#include "Game/config/GameCfg.h"

//Forward Declaration


struct EngineConfig{
	MonitorWindowCfg windowCfg;
	ImageContainerCfg imageContainerCfg;
	TextContainerCfg textContainerCfg;
	GameCfg gameCfg;
};



#endif /* ENGINE_CONFIG_ENGINECONFIG_H_ */
