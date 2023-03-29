#pragma once
#include "audio/AudioManager.h"

class AudioAsset
{
public:
	const char* name;

	float volume;
	float frequency;

	long soundId;//use negative sign for no sound

public:
	AudioAsset();
	~AudioAsset();

	FMOD::Sound* getSound();
};