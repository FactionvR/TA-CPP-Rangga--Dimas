#include "raylib.h"
#include "ScoreManager.h"
#include "Player.h"
#include "Command.h"
#include "InputHandler.h"
#include "ItemFactory.h"
#include "Item.h"
#include "Assets.h"
#include <vector>


int main() {
    InitWindow(1080, 1080, "Catch the Falling Apples");
    SetTargetFPS(60);
    
    Assets::Load();

    int lives = 3;
    bool isGameOver = false;
    int nextlivesScore = 200; 

    vector<unique_ptr<Item>> items;
    int spawnTimer = 0;

    ScoreManager score;
    Player player(400, 900, 200, 200, 10.0f, &Assets::basketTex);
    InputHandler input;
    player.SetSpeed(15.0f); // player jadi sangat cepat


    while (!WindowShouldClose()) {
    if (!isGameOver) {
        // Input
        Command* command = input.HandleInput();
        if (command) command->Execute(player);

        // Spawn items
        spawnTimer++;
        if (spawnTimer >= 60) {
            items.push_back(ItemFactory::CreateRandomItem());
            spawnTimer = 0;
        }

        // Update & collision
        for (int i = items.size() - 1; i >= 0; i--) {
            items[i]->Update();

            if (items[i]->CheckCollision(player.GetRect())) {
                int value = items[i]->GetScoreValue();
                score.AddScore(value);

                if (value < 0) 
                {   
                    lives--;
                    if (lives <= 0) {
                        isGameOver = true;
                    }
                } 

                items.erase(items.begin() + i);

                if (score.GetScore() >= nextlivesScore) 
                {
                    lives++;
                    nextlivesScore += 200;
                }

            } 
            else if (items[i]->IsOffScreen()) 
            {
                items.erase(items.begin() + i);
            }
        }

    } else {
        // Game Over & restart
        if (IsKeyPressed(KEY_R)) {
            items.clear();
            score.Reset();
            lives = 3;
            isGameOver = false;
        }
    }

    // ==========================================
    // 🎨 GAMBAR (Draw)
    // ==========================================
    BeginDrawing();

    DrawTexture(Assets::backgroundTex, 0, 0, WHITE);
    
    player.Draw();

    for (auto& item : items) {
        item->Draw();
    }

    DrawText(TextFormat("Lives: %d", lives), 10, 10, 20, BLACK);
    DrawText(TextFormat("Score: %d", score.GetScore()), 10, 40, 30, BLACK);
    DrawText(TextFormat("Items count: %d", items.size()), 10, 70, 20, DARKGRAY);

    if (isGameOver) {
        DrawText("GAME OVER", 440, 440, 40, RED);
        DrawText("Press [R] to Restart", 455, 490, 20, DARKGRAY);
    }

    EndDrawing();
}

    Assets::Unload();
    CloseWindow();
    return 0;
}
