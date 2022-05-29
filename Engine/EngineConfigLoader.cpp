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


constexpr auto PRESS_KEYS_WIDTH = 640;
constexpr auto PRESS_KEYS_HEIGHT = 480;

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
	imageCfg.location = "../resources/press_keys.png";
	imageCfg.height = PRESS_KEYS_WIDTH;
	imageCfg.width = PRESS_KEYS_HEIGHT;

	cfg.imageConfigs.insert(std::make_pair(TextureId::PRESS_KEYS,imageCfg));	//we have to pair them first with the ID


	ImageCfg imageCfg;
	imageCfg.location = "../resources/layer_2.png";
	imageCfg.height = LAYER_2_IMG_WIDTH;
	imageCfg.width = LAER_2_IMG_HEIGHT;

	cfg.imageConfigs.insert(std::make_pair(TextureId::LAYER_2,imageCfg));	//we have to pair them first with the ID
}


EngineConfig EngineConfigLoader::loadConfig(){
	EngineConfig cfg;

	populateMonitorConfig(cfg.windowCfg);
	populateGameConfig(cfg.imageContainerCfg);

	return cfg;
}
