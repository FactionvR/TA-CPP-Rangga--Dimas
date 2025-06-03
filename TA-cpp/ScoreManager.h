#ifndef SCORE_MANAGER_H
#define SCORE_MANAGER_H

class ScoreManager {
private:
    int score;

public:
    ScoreManager();

    void AddScore(int amount);
    void Reset();
    int GetScore() const;
};

#endif
