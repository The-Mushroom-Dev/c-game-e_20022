#include "raylib.h"
#include "player.h"
#include "menu.h"
#include "pause.h"


enum Scene
{
    Menu,
    Game,
    Pause
};
Scene scene = Menu;
int main()
{
    InitWindow(1280, 720, "game_project");
    SetTargetFPS(60);
#include "texures.h"

    while (!WindowShouldClose())
    {
        SetExitKey(0);

        BeginDrawing();
        ClearBackground(BLACK);
        DrawFPS(10, 10);
        switch (scene)
        {
        case Menu:
            menu();
            if (IsKeyPressed(KEY_SPACE))
                scene = Game;

            break;
        case Game:
            player(Rectangle{0, 650, 1500, 10}, Player_Run, framewidht);
            DrawRectangle(0, 650, 1500, 100, PINK);
            if (IsKeyPressed(KEY_ESCAPE))
                scene = Pause;
            break;
        case Pause:
            pause_menu();
            if (IsKeyPressed(KEY_ESCAPE) || IsKeyPressed(KEY_SPACE))
                scene = Game;
            break;
        }

        EndDrawing();
    }
    CloseWindow();
    return 0;
}