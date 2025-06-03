#include "Assets.h"

Texture2D Assets::appleTex;
Texture2D Assets::bombTex;
Texture2D Assets::goldTex;
Texture2D Assets::basketTex;
Texture2D Assets::backgroundTex;

void Assets::Load() {
    appleTex = LoadTexture("assets/red_apple.png");
    bombTex = LoadTexture("assets/bomb.png");
    goldTex = LoadTexture("assets/golden_apple.png");
    basketTex = LoadTexture("assets/capybara.png");
    backgroundTex = LoadTexture("assets/background.jpg");
}

void Assets::Unload() {
    UnloadTexture(appleTex);
    UnloadTexture(bombTex);
    UnloadTexture(goldTex);
    UnloadTexture(basketTex);
    UnloadTexture(backgroundTex);
}
