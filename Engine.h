#pragma once
#include "World.h"
#include <string>

using namespace std;

class Engine
{
public:
	Engine();
	virtual ~Engine();

	bool bRunning;

	void Initialize();
	void Load(string MapFilename);
	void Run();
	void Terminate();
	void Input();

	inline static int GetKeyCode() { return Engine::KeyCode; }

	inline static Engine* GetEngine() { return Instance; }
	
	World* GetWorld() const { return MyWorld; }

	inline void QuitGame() { bRunning = false; }

protected:
	static int KeyCode;
	
	World* MyWorld;

	static Engine* Instance;
};

#define GEngine Engine::GetEngine()