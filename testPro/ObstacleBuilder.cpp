#include "ObstacleBuilder.h"
#include "CircleObstacle.h"
#include "DynamicShapeObstacle.h"
#include "RectangleObstacle.h"



void ObstacleBuilder::Insert(std::vector<Obstacle*>& activeObstacles)
{
    for (Obstacle* ob : this->storage)
    {
        activeObstacles.push_back(ob);
    }

    this->storage.clear();
}

void ObstacleBuilder::FlyingPentagon(float x, float y)
{
    std::vector<Vector2> v;

    v.push_back({ 700,700 });
    v.push_back({ 700,900 });
    v.push_back({ 900,1000 });
    v.push_back({ 1000,900 });
    v.push_back({ 900,700 });
    v.push_back({ 700,700 });

    DynamicShapeObstacle* d = new DynamicShapeObstacle(x, y, { 400, 700 }, v, 0.02f, 0.005f, { 1,-1 });
    this->storage.push_back(d);
}

void ObstacleBuilder::ClassicCircle(float x, float y, float r, Vector2 vi)
{
    CircleObstacle* c = new CircleObstacle(x, y, r, vi);
    this->storage.push_back(c);
}

void ObstacleBuilder::ClassicRectangle(float x, float y, float w, float h, Vector2 vi)
{
    RectangleObstacle* r = new RectangleObstacle(x, y, w, h, vi);
    this->storage.push_back(r);
}


