#include "ScoreManager.h"

ScoreManager::ScoreManager() : score(0) {}

void ScoreManager::AddScore(int amount) {
    score += amount;
}

void ScoreManager::Reset() {
    score = 0;
}

int ScoreManager::GetScore() const {
    return score;
}

