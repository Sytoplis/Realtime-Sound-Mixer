#include "AudioPlayer.h"

AudioPlayer::AudioPlayer(FMOD::Sound* sound, const char* name) : sound(sound), group(nullptr), channel(nullptr) {
	PollingStation::Get().audioManager.createGroup(&group, name);
}

AudioPlayer::~AudioPlayer() {
	group->release();
	//NOTE: channels cant be released
}

void AudioPlayer::playSound() {
	PollingStation::Get().audioManager.playSound(sound, group, &channel);
}