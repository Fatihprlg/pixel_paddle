//
// Created by mfati on 12/20/2023.
//

#include "../../include/engine/Vector2.h"

Vector2::Vector2(int x, int y): x(x), y(y){}

Vector2 &Vector2::operator=(const Vector2 &other) {
    x = other.x;
    y = other.y;
    return *this;
}

Vector2 &Vector2::operator+(const Vector2 &other) {
    x += other.x;
    y += other.y;
    return *this;
}

Vector2 &Vector2::operator+=(const Vector2 &other) {
    x += other.x;
    y += other.y;
    return *this;
}

Vector2 &Vector2::operator-=(const Vector2 &other) {
    x -= other.x;
    y -= other.y;
    return *this;
}

Vector2::Vector2() = default;
