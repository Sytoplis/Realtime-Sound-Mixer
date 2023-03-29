#include <iostream>
#include "PollingStation.h"
#include "audio/AudioPlayer.h"

void onUpdate() {
	PollingStation::Get().audioManager.update();
}

int main() {
	std::cout << "Hello World" << std::endl;

	FMOD::Sound* sound;
	PollingStation::Get().audioManager.loadSound("res/sneeze.mp3", &sound);

	AudioPlayer player = AudioPlayer(sound, "test");
	player.playSound();

	PollingStation::Get().window.mainLoop(onUpdate);
}
