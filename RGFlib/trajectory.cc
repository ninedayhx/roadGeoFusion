#include "trajectory.h"

namespace RGF
{
    trajectory::trajectory(int n)
    {
        curptr = 0;
        oldptr = 0;
        nums = n;
        size = 0;
        points = new trajpoint_t[nums + 1];
        for (int i = 0; i < nums + 1; i++)
            points[i] = trajpoint_t();
    }

    trajectory::~trajectory()
    {
        delete[] points;
    }

    void trajectory::addPoint(trajpoint_t pt)
    {
        ++curptr;
        if (curptr > nums)
        {
            curptr = 1;
            if (oldptr == 0)
            {
                ++oldptr;
            }
        }
        if (oldptr > nums)
        {
            oldptr = 1;
        }
        if (oldptr == curptr)
        {
            ++oldptr;
        }
        points[curptr] = pt;
        int tmp = curptr - oldptr;
        if (tmp < 0)
            size = nums;
        else
            size = tmp;
    }
    trajpoint_t trajectory::findPoint(uint64_t time)
    {
        return
    }

    void trajectory::updataTrajectory()
    {
    }

} // namespace RGF
