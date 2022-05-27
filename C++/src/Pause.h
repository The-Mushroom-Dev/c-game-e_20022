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
    DrawText("Press SPACE to continue", x, y, 30, WHITE);
}