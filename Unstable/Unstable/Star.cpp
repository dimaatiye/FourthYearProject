#include "Star.h"

void Star::DrawStar(Vector2 center, float outerRadius, float innerRadius, Color color)
{
    const int points = 5;

    for (int i = 0; i < points * 2; i++)
    {
        float angle1 = ( i * 180.0f / points) * DEG2RAD;
        float angle2 = ((i + 1) * 180.0f / points) * DEG2RAD;

        float radius1 = (i % 2 == 0) ? outerRadius : innerRadius;
        float radius2 = (i % 2 == 0) ? innerRadius : outerRadius;

        Vector2 point1 = { center.x + cosf(angle1) * radius1, center.y + sinf(angle1) * radius1 };//cos left right . sin up down
        Vector2 point2 = { center.x + cosf(angle2) * radius2, center.y + sinf(angle2) * radius2 };

        DrawTriangle(center, point2, point1, color);   // p2 before p1 keeps the winding counter-clockwise
    }
}
// refrence : https://raw.org/math/geometry/drawing-an-upright-star-polygon/