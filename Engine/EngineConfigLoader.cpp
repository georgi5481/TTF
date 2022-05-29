//Corresponding header
#include "EngineConfigLoader.h"
//C system includes

//C++ system includes
#include<cstdint>

//3rd-party includes


//Own includes
#include "common/commonDefines.h"

//constants
namespace{		//the anonymous namespace will work only on this .cpp file
constexpr auto WINDOW_WIDTH = 640;
constexpr auto WINDOW_HEIGHT = 480;
constexpr auto WINDOW_NAME = "Hardware_Redering";


constexpr auto RSRC_WIDTH = 640;
constexpr auto RSRC_HEIGHT = 480;

constexpr auto LAYER_2_IMG_WIDTH = 640;
constexpr auto LAER_2_IMG_HEIGHT = 480;

}

static void populateMonitorConfig(MonitorWindowCfg& cfg){
	cfg.windowName = WINDOW_NAME;
	cfg.windowWidth = WINDOW_WIDTH;
	cfg.windowHeight = WINDOW_HEIGHT;
	cfg.windowFlags = WINDOW_SHOWN;
}


/*
static void populateGameConfig(GameCfg& cfg){


}
*/

static void populateImageContainerConfig(ImageContainerCfg& cfg){

	ImageCfg imageCfg;
	imageCfg.location = "../resources/up.png";
	imageCfg.height = RSRC_HEIGHT;
	imageCfg.width = RSRC_WIDTH;

	cfg.imageConfigs.insert(std::make_pair(TextureId::UP,imageCfg));	//we have to pair them first with the ID

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
