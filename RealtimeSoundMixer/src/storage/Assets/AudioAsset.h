#pragma once
#include "audio/AudioManager.h"
#include "storage/Saveable.h"

class AudioAsset : public Saveable
{
public:
	std::string name;

	float volume;
	float frequency;

public:
	AudioAsset();
	~AudioAsset();

	virtual void Save(std::ofstream& file) const override;
	virtual void Load(std::ifstream& file) override;

	virtual size_t GetId() const override;
};

DEF_TYPE_ID(AudioAsset, 1)//the Id used for storage