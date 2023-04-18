#pragma once
#include "AudioAsset.h"

class SingleAudioAsset : public AudioAsset
{
public:
	long soundId;//use negative sign for no sound

public:
	SingleAudioAsset();
	~SingleAudioAsset();

	FMOD::Sound* getSound();

	virtual void Save(std::ofstream& file) const override;
	virtual void Load(std::ifstream& file) override;

	virtual size_t GetId() const override;
};

DEF_TYPE_ID(SingleAudioAsset, 2)//the Id used for storage