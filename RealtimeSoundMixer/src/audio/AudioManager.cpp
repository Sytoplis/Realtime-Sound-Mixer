#include "AudioManager.h"

const int MAX_CHANNELS = 64;

static inline bool ErrorCheck(FMOD_RESULT result) {
	if (result != FMOD_OK) {
		printf("FMOD error! (%d) %s\n", result, FMOD_ErrorString(result));
		return true;
	}
	return false;
}

AudioManager::AudioManager() : sys(nullptr) {
	FMOD_RESULT result = FMOD::System_Create(&sys);// Create the main system object.
	if(ErrorCheck(result)) exit(-1);

	result = sys->init(MAX_CHANNELS, FMOD_INIT_MIX_FROM_UPDATE, 0);    // Initialize FMOD.
	if (ErrorCheck(result)) exit(-1);

	printf("FMOD initialized!\n");
}

AudioManager::~AudioManager() {
	ErrorCheck(sys->release());
}


void AudioManager::update() {
	ErrorCheck(sys->update());
}


void AudioManager::loadSound(const char* name_or_data, FMOD::Sound** sound) {
	ErrorCheck(sys->createSound(name_or_data, FMOD_DEFAULT, NULL, sound));
}

void AudioManager::playSound(FMOD::Sound* sound, FMOD::ChannelGroup* channelGroup, FMOD::Channel** channel) {
	ErrorCheck(sys->playSound(sound, channelGroup, false, channel));
}

void AudioManager::createGroup(FMOD::ChannelGroup** group, const char* name) {
	ErrorCheck(sys->createChannelGroup(name, group));
}