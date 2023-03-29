#pragma once
#include "audio/AudioManager.h"
#include "render/Window.h"

class PollingStation
{
public:
	AudioManager audioManager;
	Window window;

private:
	PollingStation();
	~PollingStation();

public:
	static PollingStation& Get();
};

