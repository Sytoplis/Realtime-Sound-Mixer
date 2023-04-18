#include "SingleAudioAsset.h"

SingleAudioAsset::SingleAudioAsset() : soundId(-1) {}
SingleAudioAsset::~SingleAudioAsset() {}
GET_ID_METHOD(SingleAudioAsset)

FMOD::Sound* SingleAudioAsset::getSound() {
	return nullptr;//TODO: gets sound from sound library
}

void SingleAudioAsset::Save(std::ofstream& file) const {
	AudioAsset::Save(file);
	WRITE(soundId, file);
}

void SingleAudioAsset::Load(std::ifstream& file) {
	AudioAsset::Load(file);
	READ(soundId, file);
}