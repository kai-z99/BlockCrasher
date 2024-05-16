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


void ObstacleBuilder::FlyingPentagon(float x, float y)
{
    std::vector<Vector2> v;

    v.push_back({ 700,700 });
    v.push_back({ 700,900 });
    v.push_back({ 900,1000 });
    v.push_back({ 1000,900 });
    v.push_back({ 900,700 });
    v.push_back({ 700,700 });

    DynamicShapeObstacle* d = new DynamicShapeObstacle(x, y, { 400, 700 }, v, 0.02f, 0.005f, { 1,-1 }, 0);
    this->storage.push_back(d);
}

void ObstacleBuilder::MasterSword(float x, float y)
{
    std::vector<Vector2> v;

    v.push_back({ 0,0 });
    v.push_back({ 100,0 });
    v.push_back({ 100,200 });
    v.push_back({ 200,200 });
    v.push_back({ 100,300 });
    v.push_back({ 100,700 });
    v.push_back({ 50,750 });
    v.push_back({ 0,700 });
    v.push_back({ 0,300 });
    v.push_back({ -100,200 });
    v.push_back({ 0,200 });
    v.push_back({ 0,0 });

    for (Vector2& vec : v)
    {
        vec.x += x;
        vec.y += y;
    }

    DynamicShapeObstacle* d = new DynamicShapeObstacle(x, y, { 50 + x, 100 + y }, v, 0.02f, 0.009f, { 0,0 }, 0);
    CircleObstacle* c = new CircleObstacle(50 + x, 100 + y, 10, { 0,0 });
    this->storage.push_back(d);
    this->storage.push_back(c);
}

void ObstacleBuilder::HollowBoxPiece(float x, float y, float rr, float ri, float vo, float scale) // good example. talke lots of params
{
    std::vector<Vector2> v;

    v.push_back({ 0,0 });
    v.push_back({ 0,300 });
    v.push_back({ 120,300 });
    v.push_back({ 120,240 });
    v.push_back({ 60,240 });
    v.push_back({ 60,60 });
    v.push_back({ 120,60 });
    v.push_back({ 120,0 });
    v.push_back({ 0,0 });


    for (Vector2& vec : v)
    {
        vec.x *= scale;
        vec.y *= scale;
    }
    
    for (Vector2& vec : v)
    {
        vec.x += x;
        vec.y += y;
    }

    DynamicShapeObstacle* d = new DynamicShapeObstacle( x, y, { 150*scale + x, 150*scale + y }, v, rr, vo, { 0,0 }, ri);
    this->storage.push_back(d);

}

void ObstacleBuilder::Wheel(float x, float y, float rr, float ri, float vo, float scale)
{
    std::vector<Vector2> v;

    v.push_back({ 10,10 });
    v.push_back({ 10,200 });
    v.push_back({ -10,200 });
    v.push_back({ -10,10 });
    v.push_back({ -200,10 });
    v.push_back({ -200,-10 });
    v.push_back({ -10,-10 });
    v.push_back({ -10,-200 });
    v.push_back({ 10,-200 });
    v.push_back({ 10,-10 });
    v.push_back({ 200,-10 });
    v.push_back({ 200, 10 });
    v.push_back({ 10, 10 });


    for (Vector2& vec : v)
    {
        vec.x *= scale;
        vec.y *= scale;
    }

    for (Vector2& vec : v)
    {
        vec.x += x;
        vec.y += y;
    }

    DynamicShapeObstacle* d = new DynamicShapeObstacle(x, y, { 0 * scale + x, 0 * scale + y }, v, rr, vo, { 0,0 }, ri);
    CircleObstacle* c = new CircleObstacle(x, y, 20, { 0,0 });
    this->storage.push_back(d);
    this->storage.push_back(c);

}

void ObstacleBuilder::NinjaStar(float x, float y, float rr, float ri, float vo, Vector2 vi, float scale)
{
    std::vector<Vector2> v;

    v.push_back({ 150,0 });
    v.push_back({ 50,50 });
    v.push_back({ 0,150 });
    v.push_back({ -50,50 });
    v.push_back({ -150,0 });
    v.push_back({ -50, 50 });
    v.push_back({ -150, 0 });
    v.push_back({ -50,-50 });
    v.push_back({ 0,-150 });
    v.push_back({ 50,-50 });
    v.push_back({ 150, 0 });


    for (Vector2& vec : v)
    {
        vec.x *= scale;
        vec.y *= scale;
    }

    for (Vector2& vec : v)
    {
        vec.x += x;
        vec.y += y;
    }

    DynamicShapeObstacle* d = new DynamicShapeObstacle(x, y, { 0 * scale + x, 0 * scale + y }, v, rr, vo, vi, ri);
    CircleObstacle* c = new CircleObstacle(x, y, 25 * scale, vi);
    this->storage.push_back(d);
    this->storage.push_back(c);

}

void ObstacleBuilder::RotatingBar(float x, float y, float rr, float ri, float vo, Vector2 vi, float scale)
{
    std::vector<Vector2> v;

    v.push_back({ -50, -5 });
    v.push_back({ 50, -5 });
    v.push_back({ 60, 0 });
    v.push_back({ 50, 5 });
    v.push_back({ -50, 5 });
    v.push_back({ -60, 0 });
    v.push_back({ -50, -5 });

    for (Vector2& vec : v)
    {
        vec.x *= scale;
        vec.y *= scale;
    }

    for (Vector2& vec : v)
    {
        vec.x += x;
        vec.y += y;
    }

    DynamicShapeObstacle* d = new DynamicShapeObstacle(x, y, { 0 * scale + x, 0 * scale + y }, v, rr, vo, vi, ri);
    CircleObstacle* c = new CircleObstacle(x, y, 3 * scale, vi);
    this->storage.push_back(d);
    this->storage.push_back(c);

}

void ObstacleBuilder::GridPiece(float x, float y, float rr, float ri, float vo, Vector2 vi, float scale, Vector2 center)
{
    std::vector<Vector2> v;

    v.push_back({ 0, 0 });
    v.push_back({ 100, 0 });
    v.push_back({ 100, 100 });
    v.push_back({ 0, 100 });
    v.push_back({ 0, 0 });

    for (Vector2& vec : v)
    {
        vec.x *= scale;
        vec.y *= scale;
    }

    for (Vector2& vec : v)
    {
        vec.x += x;
        vec.y += y;
    }

    DynamicShapeObstacle* d = new DynamicShapeObstacle(x, y, center, v, rr, vo, vi, ri);
    this->storage.push_back(d);

}

void ObstacleBuilder::Tree(float x, float y, float rr, float ri, float vo, Vector2 vi, float scale)
{
    std::vector<Vector2> v;

    v.push_back({ 50, 0 });
    v.push_back({ 50, 150 });
    v.push_back({ 200, 150 });
    v.push_back({ 100, 250 });
    v.push_back({ 150, 250 });
    v.push_back({ 50, 350 });
    v.push_back({ 100, 350 });
    v.push_back({ 0, 500 });
    v.push_back({ -100, 350 });
    v.push_back({ -50, 350 });
    v.push_back({ -150, 250 });
    v.push_back({ -100, 250 });
    v.push_back({ -200, 150 });
    v.push_back({ -50, 150 });
    v.push_back({ -50, 0 });
    v.push_back({ 50, 0 });

    for (Vector2& vec : v)
    {
        vec.x *= scale;
        vec.y *= scale;
    }

    for (Vector2& vec : v)
    {
        vec.x += x;
        vec.y += y;
    }

    DynamicShapeObstacle* d = new DynamicShapeObstacle(x, y, { 0 * scale + x, 50 * scale + y }, v, rr, vo, vi, ri);
    this->storage.push_back(d);

    std::vector<Vector2> v2; // right eye

    v2.push_back({ 50, 248 });
    v2.push_back({ 52, 250 });
    v2.push_back({ 50, 252 });
    v2.push_back({ 48, 250 });
    v2.push_back({ 50, 248 });

    for (Vector2& vec : v2)
    {
        vec.x *= scale;
        vec.y *= scale;
    }

    for (Vector2& vec : v2)
    {
        vec.x += x;
        vec.y += y;
    }


    DynamicShapeObstacle* d2 = new DynamicShapeObstacle(x, y, { 0 * scale + x, 50 * scale + y }, v2, rr, vo, vi, ri);
    this->storage.push_back(d2);


    //fix me find eas ywayto draw second eye

    std::vector<Vector2> v3; // left eye

    v3.push_back({ -50, 248 });
    v3.push_back({ -52, 250 });
    v3.push_back({ -50, 252 });
    v3.push_back({ -48, 250 });
    v3.push_back({ -50, 248 });

    for (Vector2& vec : v3)
    {
        vec.x *= scale;
        vec.y *= scale;
    }

    for (Vector2& vec : v3)
    {
        vec.x += x;
        vec.y += y;
    }

    DynamicShapeObstacle* d3 = new DynamicShapeObstacle(x - 100, y, { 0 * scale + x, 50 * scale + y }, v3, rr, vo, vi, ri);
    this->storage.push_back(d3);
     


    std::vector<Vector2> v4; // mouth

    v4.push_back({ -25, 200 });
    v4.push_back({ 25, 200 });
    v4.push_back({ -25, 201 });
    v4.push_back({ -25, 201 });
    v4.push_back({ -25, 200 });


    for (Vector2& vec : v4)
    {
        vec.x *= scale;
        vec.y *= scale;
    }

    for (Vector2& vec : v4)
    {
        vec.x += x;
        vec.y += y;
    }

    DynamicShapeObstacle* d4 = new DynamicShapeObstacle(x - 100, y, { 0 * scale + x, 50 * scale + y }, v4, rr, vo, vi, ri);
    this->storage.push_back(d4);

}


