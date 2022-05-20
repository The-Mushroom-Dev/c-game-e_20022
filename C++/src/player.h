void player(Rectangle rec)
{
    static bool isGrounded;
    static float scale = 5.0;
    static Texture2D player = LoadTexture("data/1.png");
    static Texture2D player_left = LoadTexture("data/2.png");
    static Texture2D player_right = LoadTexture("data/1.png");
    static float x = 10;
    static float y = 10;

    // Movement
    if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT))
        x += 10;
    if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT))
        x -= 10;
    if (IsKeyPressed(KEY_W) || IsKeyPressed(KEY_UP) || IsKeyPressed(KEY_SPACE))
    {
        if (isGrounded)
        {
            y -= 200;
        }
    }

    // if (IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN))
    if (!isGrounded)
        y += 10;

    if (IsKeyPressed(KEY_D) || IsKeyPressed(KEY_RIGHT))
        player = player_right;
    if (IsKeyPressed(KEY_A) || IsKeyPressed(KEY_LEFT))
        player = player_left;
    if (CheckCollisionCircleRec(Vector2{x + 25, y + 25}, 20, rec))
    {
        isGrounded = true;
    }
    else
    {
        isGrounded = false;
    }
    
    DrawTextureEx(player, Vector2{x, y}, 0.0f, scale, WHITE);
}