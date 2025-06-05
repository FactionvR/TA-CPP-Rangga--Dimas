class ScoreManager {
private:
    int score;
    ScoreManager(); // deklarasi

public:
    static ScoreManager& GetInstance();

    void AddScore(int value);
    void Reset();
    int GetScore() const;
};
