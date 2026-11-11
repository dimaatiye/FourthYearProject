#include "Star.h"

void Star::DrawStar(Vector2 center, float outerRadius, float innerRadius, float rotationDeg, Color color)
{
    const int points = 5;

    for (int i = 0; i < points * 2; i++)
    {
        float angle1 = (rotationDeg - 90.0f + i * 180.0f / points) * DEG2RAD;
        float angle2 = (rotationDeg - 90.0f + (i + 1) * 180.0f / points) * DEG2RAD;

        float r1 = (i % 2 == 0) ? outerRadius : innerRadius;
        float r2 = (i % 2 == 0) ? innerRadius : outerRadius;

        Vector2 p1 = { center.x + cosf(angle1) * r1, center.y + sinf(angle1) * r1 };
        Vector2 p2 = { center.x + cosf(angle2) * r2, center.y + sinf(angle2) * r2 };

        DrawTriangle(center, p2, p1, color);   // p2 before p1 keeps the winding counter-clockwise
        // DrawLineV(p1, p2, color);           // use this instead for an outline-only star
    }
}
