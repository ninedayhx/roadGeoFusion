/**
 * @file trajectory.cc
 * @author ninedayhx (1170535490@qq.com)
 * @brief
 * @version 0.1
 * @date 2024-08-11
 *
 * @copyright Copyright (c) 2024
 *
 */
#include "trajectory.h"

namespace RGF
{
    trajectory::trajectory(int n)
    {
        curptr = 0;
        oldptr = 0;
        nums = n;
        size = 0;
        points = new trajpoint_t[nums];
    }

    trajectory::~trajectory()
    {
        delete[] points;
    }

    void trajectory::addPoint(trajpoint_t pt)
    {
        static int flag = 0;
        points[curptr] = pt;
        if (++curptr > nums)
        {
            curptr = 0;
            if (!flag)
            {
                oldptr = 0;
                flag = 1;
            }
        }
        if (flag)
        {
            oldptr = (curptr + 1) > nums ? 0 : curptr + 1;
            size = nums;
        }
        else
        {
            size = curptr;
        }
    }

    trajpoint_t *trajectory::findPoint(uint64_t time)
    {
        int i = 0;
        if (time >= points[curptr].timestamp || time <= points[oldptr].timestamp)
        {
            return nullptr;
        }
        while (findByindex(++i)->timestamp < time)
        {
            if (i >= nums)
                break;
        }
        int left = i, right = i + 1;

        return;
    }

    /**
     * @brief
     *
     * @param idx
     * @return trajpoint_t*
     */
    trajpoint_t *trajectory::findByindex(int idx)
    {
        if (idx >= nums)
            return nullptr;
        int ptr = curptr - idx;
        ptr = (ptr >= 0) ? ptr : ptr + nums;
        return &points[ptr];
    }

    void trajectory::updataTrajectory()
    {
    }

    trajpoint_t trajectory::interp(trajpoint_t p1, trajpoint_t p2, uint64_t x)
    {
    }

} // namespace RGF
