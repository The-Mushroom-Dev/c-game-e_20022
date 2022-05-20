void pause_menu()
{
    static float x = 410;
    static float y = 600;
    static bool upwards;
    if (upwards)
        y -= .5f;
    if (!upwards)
        y += .5f;
    if (y == 570)
        upwards = false;
    if (y == 610)
        upwards = true;
    Vector2 position = Vector2{500, 240};
    static Texture2D logo = LoadTexture("data/1.png");
    DrawRectangle(0, 0, 1280, 720, BLUE);
    DrawText("Press SPACE to continue", x, y, 30, WHITE);
    DrawTextureEx(logo, position, 0.0f, 20.0f, WHITE);
    DrawText("Paused", 500, 100, 50, WHITE);
}