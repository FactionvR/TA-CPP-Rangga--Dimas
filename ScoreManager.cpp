#include "ScoreManager.h"

ScoreManager::ScoreManager() : score(0) {}

ScoreManager& ScoreManager::GetInstance() {
    static ScoreManager instance;
    return instance;
}

void ScoreManager::AddScore(int value) {
    score += value;
}

void ScoreManager::Reset() {
    score = 0;
}

int ScoreManager::GetScore() const {
    return score;
}
