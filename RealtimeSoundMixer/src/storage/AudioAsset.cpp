#include "AudioAsset.h"

AudioAsset::AudioAsset() : name(), volume(0.5f), frequency(0.0f), soundId(-1) {}
AudioAsset::~AudioAsset() {}


FMOD::Sound* getSound() {
	return nullptr;//TODO: gets sound from sound library
}