#ifndef FIELD_H
#define FIELD_H

#include <cstdint>
#include <fstream>
#include <iostream>
#include <map>
#include <stack>
#include <queue>
#include <string>
#include <vector>
#include <windows.h>

#include <ConstData.h>
#include <Enemy.h>
#include <Role.h>
#include <Dice.h>

struct StatusCount {
	uint8_t poisoned;
	uint8_t bleed;
	uint8_t dizziness;
	uint8_t angry;
};

class Action {
private:
	Dice* dice;
	Entity* obj;
	StatusCount* count;
	uint32_t priority;
	uint8_t turn;
	uint8_t entityID;

public:
	Action(Entity* val, uint8_t mode, uint8_t ID);

	void SetObj(Entity* val) { obj = val; }
	void SetPriority(uint32_t val) { priority = val; }
	void SetTurn(uint8_t val) { turn = val; }
	void SetEntityID(uint8_t val) { entityID = val; }

	Dice* GetDice(void) { return dice; }
	Entity* GetObj(void) { return obj; }
	StatusCount* GetCount(void) { return count; }
	uint32_t GetPriority(void) { return priority; }
	uint8_t	GetTurn(void) { return turn; }
	uint8_t	GetEntityID(void) { return entityID; }
};

class Field {
private:
	Action* currEvent;                      // Current Event
	std::vector<Action*> eventQueue;        // Engage Entity

public:
	void MainPhase(Action*);
	void BattlePhase(Action*);
	void DamagePhase(Action*);
	void ExitPhase(void);

	void ChooseSkill(Role*);
	void ChooseTarget(Role*);
	void UsingFocus(Role*);
	// Detect Status and Compute
  
	Action* RefreshEvent(void);

public:
	// Set Combat Configuation; Put the players into first parameter and the enemies into second parameter.
	Field(std::vector<Entity*>, std::vector<Entity*>);
	~Field(void);

	// Start Combat
	void StartBattle(void);
};

#endif