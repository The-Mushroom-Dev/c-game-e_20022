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
    while (!WindowShouldClose())
    {
        SetExitKey(0);

        BeginDrawing();
        ClearBackground(BLACK);

        switch (scene)
        {
        case Menu:
            menu();
            if (IsKeyPressed(KEY_SPACE))
                scene = Game;

            break;
        case Game:
            player(Rectangle{0, 600, 1000, 10});
            DrawRectangle(0, 600, 1000, 100, DARKBLUE);
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