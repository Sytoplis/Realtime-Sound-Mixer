#include "PollingStation.h"

PollingStation::PollingStation() : audioManager(AudioManager()), window(Window(1280, 720, "THIS IS A TEST")) {}
PollingStation::~PollingStation() {}

PollingStation& PollingStation::Get() {
	static PollingStation instance;
	return instance;
}