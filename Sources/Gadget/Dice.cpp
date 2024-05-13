#include "../../Includes/Gadget/Dice.h"

// Public

Dice::Dice(uint8_t amount, uint8_t successRate) {
	this->focusCount = 0;
	this->movementPoint = 0;
	this->amount = amount;
	this->result.resize(this->amount, false);
	this->successRate.resize(this->amount, successRate);
	this->rateAddition.resize(this->amount, 0);
}

Dice::Dice(uint8_t speed) {
	this->focusCount = 0;
	this->movementPoint = 0;
	this->amount = static_cast<uint8_t>(speed / 10); // MaxMovementPoint := Stat::Speed / 10
	this->result.resize(this->amount, false);
	this->rateAddition.resize(this->amount, 0);
	this->successRate.resize(this->amount, std::min<uint8_t>(90, speed)); // successRate := Stat::Speed / 100, but not exceed 90.
}

void Dice::RollDice(void) {
	// Random Engine
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(0, 99);
	this->movementPoint = 0;

	// Roll Dice
	for (int i = 0; i < this->amount; i++) {
		this->result[i] = (dis(gen) < this->successRate[i] + this->rateAddition[i]) || (i < focusCount);
		if (this->result[i]) {
			this->movementPoint++;
		}
	}

	// Reset FocusCount and RateAddition
	this->focusCount = 0;
	this->rateAddition.clear();
	this->rateAddition.resize(this->amount, 0);
}

void Dice::setMovementPoint(const uint8_t movementPoint) {
	this->movementPoint = movementPoint;
}

void Dice::SetAmount(const uint8_t amount) {
	this->amount = amount;
}

void Dice::SetFocusCount(const uint8_t focusCount) {
	this->focusCount = focusCount;
}

void Dice::SetSuccessRate(const std::vector<uint8_t>& successRate) {
	this->successRate = successRate;
}

void Dice::SetRateAddition(const std::vector<double>& rateAddition) {
	this->rateAddition = rateAddition;
}

void Dice::SetResult(const std::vector<bool>& result) {
	this->result = result;
}

uint8_t Dice::GetMovementPoint(void) {
	return this->movementPoint;
}

uint8_t Dice::GetAmount(void) {
	return this->amount;
}

uint8_t Dice::GetFocusCount(void) {
	return this->focusCount;
}

std::vector<uint8_t> Dice::GetSuccessRate(void) {
	return this->successRate;
}

std::vector<double> Dice::GetRateAddition(void) {
	return this->rateAddition;
}

std::vector<bool> Dice::GetResult(void) {
	return this->result;
}