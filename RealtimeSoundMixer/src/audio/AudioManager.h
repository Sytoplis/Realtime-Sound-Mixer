#pragma once

#include <iostream>

#include "fmod.hpp"
#include "fmod_errors.h"

class AudioManager
{
public:
	AudioManager();
	~AudioManager();

	void update();

	void loadSound(const char* name_or_data, FMOD::Sound** sound);
	void playSound(FMOD::Sound* sound, FMOD::ChannelGroup* channelGroup, FMOD::Channel** channel);
	void createGroup(FMOD::ChannelGroup** group, const char* name);

private:
	FMOD::System* sys;
};

