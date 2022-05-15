//Corresponding header
#include "EngineConfigLoader.h"
//C system includes

//C++ system includes
#include<cstdint>

//3rd-party includes
#include "sdl_utils/config/MonitorWindowCfg.h"

//Own includes

namespace{
constexpr auto WINDOW_WIDTH = 640;
constexpr auto WINDOW_HEIGHT = 480;
constexpr auto WINDOW_NAME = "Hardware_Redering";
}

static void populateMonitorConfig(MonitorWindowCfg& cfg){
	cfg.windowName = WINDOW_NAME;
	cfg.windowWidth = WINDOW_WIDTH;
	cfg.windowHeight = WINDOW_HEIGHT;
	cfg.windowFlags = WINDOW_SHOWN;
}


static void populateGameConfig(GameCfg& cfg){

	cfg.imgPaths[UP] = "../resources/up.png";
	cfg.imgPaths[DOWN] = "../resources/down.png";
	cfg.imgPaths[RIGHT] = "../resources/right.png";
	cfg.imgPaths[LEFT] = "../resources/left.png";
	cfg.imgPaths[PRESS_KEYS] = "../resources/press_keys.png";
	cfg.imgPaths[LAYER_2] = "../resources/layer_2.png";
}


EngineConfig EngineConfigLoader::loadConfig(){
	EngineConfig cfg;

	populateMonitorConfig(cfg.windowCfg);
	populateGameConfig(cfg.gameCfg);

	return cfg;
}
