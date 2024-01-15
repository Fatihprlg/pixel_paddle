//
// Created by mfati on 12/20/2023.
//

#ifndef PIXELPADDLE_VECTOR2_H
#define PIXELPADDLE_VECTOR2_H


class Vector2 {
public:
    int x;
    int y;
    Vector2(int x, int y);
    Vector2();
    Vector2& operator=(const Vector2& other);
    Vector2& operator+(const Vector2& other);
    Vector2& operator+=(const Vector2& other);
    Vector2& operator-=(const Vector2& other);

};


#endif //PIXELPADDLE_VECTOR2_H
