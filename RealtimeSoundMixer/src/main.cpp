#include <iostream>
#include "PollingStation.h"
#include "audio/AudioPlayer.h"

//TESTING
#include "storage/Scene.h"
#include "storage/Assets/SingleAudioAsset.h"


void onUpdate() {
	PollingStation::Get().audioManager.update();
}

int main() {
	std::cout << "Hello World" << std::endl;

#if 1//TEST SAVING
	Scene scene = Scene();
	scene.assets.push_back(new SingleAudioAsset());
	scene.assets[0]->volume = 0.3f;

	//SAVE
	std::ofstream fout = std::ofstream("data.bin", std::ofstream::binary);
	scene.Save(fout);
	fout.close();

	//LOAD
	std::ifstream fin = std::ifstream("data.bin", std::ofstream::binary);
	scene.Load(fin);
	fin.close();

	if (scene.assets[0] != nullptr)
		std::cout << "LOADED volume: " << scene.assets[0]->volume << std::endl;
	else
		std::cout << "nullptr loaded" << std::endl;
#endif


	FMOD::Sound* sound;
	PollingStation::Get().audioManager.loadSound("res/sneeze.mp3", &sound);

	AudioPlayer player = AudioPlayer(sound, "test");
	player.playSound();

	PollingStation::Get().window.mainLoop(onUpdate);
}
