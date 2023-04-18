#pragma once
#include <vector>

#include "storage/TypeIdSystem.h"
#include "storage/Assets/AudioAsset.h"

class Scene : public Saveable
{
public:
	std::vector<AudioAsset*> assets;
public:
	Scene();
	~Scene();
	
	void Save(std::ofstream& file) const override;
	void Load(std::ifstream& file) override;

	size_t GetId() const override;

	void Clear();
};

DEF_TYPE_ID(Scene, 0)//the Id used for storage