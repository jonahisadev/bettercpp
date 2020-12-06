#include <iostream>

#define BETTER_CPP_IMPL
#include "lib/pointer.h"

struct Point
{
    int x;
    int y;
};

int main()
{
    Point p = {10, 20};
    RefPtr<Point> ptr = make_ref<Point>(p);

    std::cout << ptr->x << ", " << ptr->y << std::endl;

    {
        auto copy = ptr;
        copy->x += 5;
    }

    std::cout << ptr->x << ", " << ptr->y << std::endl;

    return 0;
}