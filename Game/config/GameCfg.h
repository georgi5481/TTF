#ifndef GAME_CONFIG_GAMECFG_H_
#define GAME_CONFIG_GAMECFG_H_

//C system includes

//C++ system includes
#include<cstdint>
#include<unordered_map>
//3rd-party includes

//Own includes

//Forward Declaration

enum Images{
	UP, DOWN, LEFT, RIGHT, PRESS_KEYS, LAYER_2, COUNT
};

struct GameCfg {
std::unordered_map<Images, std::string> imgPaths;	//will give us the path of the wanted image
};

#endif /* GAME_CONFIG_GAMECFG_H_ */
