#include "DebugLevel.h"

DebugLevel::DebugLevel(StateManager& sm)
    : stateManager(sm)
{
    filledSquares = 0;
}

void DebugLevel::InitButtons(Renderer& renderRef)
{
    testButton01Color = BLUE;
    // Setup any UI buttons here if needed
}

void DebugLevel::Run(Renderer& renderRef)
{
    Renderer& render = renderRef;

    // --- Input handling ---
    if (IsKeyPressed(KEY_UP)) filledSquares++;
    if (IsKeyPressed(KEY_DOWN)) filledSquares--;

    if (filledSquares > MAX_FILLED) filledSquares = MAX_FILLED;
    if (filledSquares < MIN_FILLED) filledSquares = MIN_FILLED;

    // --- Drawing ---
    BeginDrawing();
    ClearBackground(RAYWHITE);

    render.DrawTextBlock(
        "Debug Level",
        render.TextScreenCenterX(300),
        render.GridY(1),
        300,
        TextAlign::Center,
        TextSize::Dialogue
    );

    // Draw the 8 circular pips grid (fits in a 100x80 area)
    DrawGrid(filledSquares, 100, 120);

    EndDrawing();
}

void DebugLevel::DrawGrid(int filledCount, int startX, int startY)
{
    const int totalWidth = 100;
    const int totalHeight = 80;
    const int spacing = 4; // slightly larger spacing for circles

    // Calculate circle center spacing
    float cellWidth = (float)(totalWidth - (GRID_COLS - 1) * spacing) / GRID_COLS;
    float cellHeight = (float)(totalHeight - (GRID_ROWS - 1) * spacing) / GRID_ROWS;

    // Use radius slightly smaller than half the smallest cell dimension
    float radius = fminf(cellWidth, cellHeight) * 0.4f;

    for (int row = 0; row < GRID_ROWS; row++)
    {
        for (int col = 0; col < GRID_COLS; col++)
        {
            int index = row * GRID_COLS + col;

            float centerX = startX + col * (cellWidth + spacing) + cellWidth / 2.0f;
            float centerY = startY + row * (cellHeight + spacing) + cellHeight / 2.0f;

            if (index < filledCount)
                DrawCircle((int)centerX, (int)centerY, radius, DARKBLUE);
            else
                DrawCircleLines((int)centerX, (int)centerY, radius, GRAY);
        }
    }
}
