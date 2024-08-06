#pragma once
#include <iostream>
#include <stdlib.h>

struct trajpoint_t
{
    float dpx;
    float dpy;
    float heading;
    uint64_t timestamp;
    trajpoint_t()
    {
        dpx = 0.0f;
        dpy = 0.0f;
        heading = 0.0f;
        timestamp = 0;
    }
    trajpoint_t(float x1, float x2, float x3, uint64_t x4)
        : dpx(x1), dpy(x2), heading(x3), timestamp(x4) {}
};

namespace RGF
{
    class trajectory
    {
    private:
        int curptr;
        int oldptr;
        int nums;
        int size;
        trajpoint_t *points;

    public:
        trajectory(int n);
        ~trajectory();

        void addPoint(trajpoint_t pt);
        trajpoint_t findPoint(uint64_t time);
        void updataTrajectory();
    };

} // namespace RGF
