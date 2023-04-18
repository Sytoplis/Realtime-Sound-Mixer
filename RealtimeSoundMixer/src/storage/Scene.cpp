#include "Scene.h"

Scene::Scene() : assets(std::vector<AudioAsset*>()) {}
Scene::~Scene() {
	for (size_t i = 0; i < assets.size(); i++)
		delete assets[i];//delete all assets before freeing the vector
}
GET_ID_METHOD(Scene)

void Scene::Save(std::ofstream& file) const {
	size_t assetSize = assets.size();
	WRITE(assetSize, file);

	for (size_t i = 0; i < assetSize; i++) {
		WriteSaveable(*assets[i], file);
	}
}

void Scene::Load(std::ifstream& file) {
	Clear();

	size_t assetSize = 0;
	READ(assetSize, file);
	assets.resize(assetSize);

	for (size_t i = 0; i < assetSize; i++) {
		assets[i] = static_cast<AudioAsset*>(ReadSaveable(file));
	}
}


void Scene::Clear() {
	for (size_t i = 0; i < assets.size(); i++)
		delete assets[i];//delete all assets
	assets.clear();
}