#pragma once
#include "PollingStation.h"
#include "audio/AudioManager.h"

class AudioPlayer
{
public:
	FMOD::Sound* sound;
	FMOD::ChannelGroup* group;
	FMOD::Channel* channel;

public:
	AudioPlayer(FMOD::Sound* sound, const char* name);
	~AudioPlayer();

	void playSound();
};