#pragma once
#include "raylib.h"

struct Assets {
    static Texture2D appleTex;
    static Texture2D bombTex;
    static Texture2D goldTex;
    static Texture2D basketTex;
    static Texture2D backgroundTex;

    static void Load();
    static void Unload();
};
