#include "DynamicShapeObstacle.h"

static Vector2 Rotate(Vector2& v, Vector2 c, float angle) //helper
{
    float tc = cosf(angle);
    float ts = sinf(angle);
    float x_rotated = ((v.x - c.x) * tc) - ((c.y - v.y) * ts) + c.x;
    float y_rotated = -c.y + ((c.y - v.y) * tc) + ((v.x - c.x) * ts);

    return { x_rotated , -y_rotated };
}

DynamicShapeObstacle::DynamicShapeObstacle(float x, float y, Vector2 c, const std::vector<Vector2>& v, float rr, float vo, Vector2 ve, float ri)
{
	this->obstaclePosition = { x,y };
    this->center = c;
	this->rotationRate = rr;
	this->vertices = v;
    this->color = WHITE;
    this->type = DynamicShape;
    this->volatility = vo;
    this->velocity = ve;

    //set initial rotation
    for (Vector2& v : this->vertices)
    {
        v = Rotate(v, this->center, ri);
    }
}

void DynamicShapeObstacle::Draw()
{
	DrawLineStrip(&this->vertices[0], (int)vertices.size(), this->color);
}


void DynamicShapeObstacle::Update(unsigned int frame)
{
    //move (update pos)

    for (Vector2& v : this->vertices)
    {
        v.x += this->velocity.x;
        v.y += this->velocity.y;
    }

    this->obstaclePosition.x += this->velocity.x;
    this->obstaclePosition.y += this->velocity.y;

    this->center.x += this->velocity.x;
    this->center.y += this->velocity.y;

    //rotate

    float rotation = this->rotationRate * (cosf(frame * this->volatility));

    for (Vector2& v : this->vertices)
    {
        v = Rotate(v, this->center, rotation);
    }
}

void DynamicShapeObstacle::SetPosX(float x)
{
    float diff = x - this->obstaclePosition.x;


    for (Vector2& v : this->vertices) //for every vertices
    {
        v.x += diff;              // offset by diff.
    }

    this->obstaclePosition.x = x;
    this->center.x += diff;
}

void DynamicShapeObstacle::SetPosY(float y)
{
    float diff = y - this->obstaclePosition.y;


    for (Vector2& v : this->vertices)
    {
        v.y += diff;
    }

    this->obstaclePosition.y = y;
    this->center.y += diff;
}

std::vector<Vector2> DynamicShapeObstacle::GetVertices() const
{
    return this->vertices;
}

