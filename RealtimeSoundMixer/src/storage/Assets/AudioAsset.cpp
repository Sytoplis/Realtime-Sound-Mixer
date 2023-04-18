#include "AudioAsset.h"

AudioAsset::AudioAsset() : name(), volume(0.5f), frequency(0.0f) {}
AudioAsset::~AudioAsset() {}

GET_ID_METHOD(AudioAsset)

void AudioAsset::Save(std::ofstream& file) const {
	WriteString(this->name, file);
	WRITE(this->volume, file);
	WRITE(this->frequency, file);
}

void AudioAsset::Load(std::ifstream& file) {
	ReadString(this->name, file);
	READ(this->volume, file);
	READ(this->frequency, file);
}