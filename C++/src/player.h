float x = 10;
float y = 10;
void player(Rectangle rec, Texture playerRun, float framewidht)
{
    static bool isGrounded;
    static float left = -framewidht;
    static float right = framewidht;
    static float directions = framewidht;
    static float timer = .0f;
    static int frame = 0;
    static int maxFrames = (int)(playerRun.width / (int)framewidht);
    timer += GetFrameTime();
    frame = frame % maxFrames;

    // Movement
    if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT))
    {
        x += 10;
        if (timer >= .1)
        {
            timer = 0;
            frame++;
        }
    }
    else if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT))
    {
        x -= 10;
        if (timer >= .1)
        {
            timer = 0;
            frame++;
        }
    }
    else
        frame = 0;

    if (IsKeyPressed(KEY_SPACE) && isGrounded)
    {
        y -= 20;
    }

    // if (IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN))
    if (!isGrounded)
    {
        y += 10;
        frame = 0;
    }

    if (IsKeyPressed(KEY_D) || IsKeyPressed(KEY_RIGHT))
        directions = right;
    else if (IsKeyPressed(KEY_A) || IsKeyPressed(KEY_LEFT))
        directions = left;

    if (CheckCollisionCircleRec(Vector2{x + 20, y + 25}, 20, rec))
        isGrounded = true;
    else
        isGrounded = false;
    // DrawCircle(x+20,y+25,20,RED);
    // DrawTextureEx(player, Vector2{x, y}, 0.0f, scale, WHITE);
    DrawTextureRec(playerRun, Rectangle{framewidht * frame, 0, directions, (float)playerRun.height}, Vector2{x, y}, WHITE);
}