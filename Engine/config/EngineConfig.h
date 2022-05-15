#ifndef ENGINE_CONFIG_ENGINECONFIG_H_
#define ENGINE_CONFIG_ENGINECONFIG_H_

//C system includes

//C++ system includes
#include<cstdint>

//3rd-party includes

//Own includes
#include "sdl_utils/MonitorWindow.h"
#include "Game/config/GameCfg.h"

//Forward Declaration


struct EngineConfig{
	MonitorWindowCfg windowCfg;
	//soon to populate other configs
	GameCfg gameCfg;
};



#endif /* ENGINE_CONFIG_ENGINECONFIG_H_ */
