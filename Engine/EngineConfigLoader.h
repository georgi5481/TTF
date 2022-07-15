#ifndef ENGINE_ENGINECONFIGLOADER_H_
#define ENGINE_ENGINECONFIGLOADER_H_

//C system includes

//C++ system includes
#include<cstdint>

//3rd-party includes

//Own includes
#include "Engine/config/EngineConfig.h"

//Forward Declaration


class EngineConfigLoader {
public:

	EngineConfigLoader() = delete;

	~EngineConfigLoader() = default;

	static EngineConfig loadConfig();
};

#endif /* ENGINE_ENGINECONFIGLOADER_H_ */
