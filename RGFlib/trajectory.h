/**
 * @file trajectory.h
 * @author ninedayhx (1170535490@qq.com)
 * @brief
 * @version 0.1
 * @date 2024-08-11
 *
 * @copyright Copyright (c) 2024
 *
 */
#pragma once
#include <iostream>
#include <stdlib.h>

namespace RGF
{
    /**
     * @brief
     *
     */
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
        void print()
        {
            std::cout << "dpx: " << dpx
                      << " dpy: " << dpy
                      << " heading: " << heading
                      << " t: " << timestamp << std::endl;
        }
    };

    /**
     * @brief
     *
     */
    class trajectory
    {
    private:
        int curptr;
        int oldptr;
        int nums;
        int size;
        trajpoint_t *points;

    private:
        /**
         * @brief
         *
         */
        void updataTrajectory();

    public:
        trajectory(int n);
        ~trajectory();

        /**
         * @brief
         *
         * @param pt
         */
        void addPoint(trajpoint_t pt);
        /**
         * @brief
         *
         * @param time
         * @return trajpoint_t
         */
        trajpoint_t *findPoint(uint64_t time);
        /**
         * @brief
         *
         * @param idx
         * @return trajpoint_t*
         */
        trajpoint_t *findByindex(int idx);
        trajpoint_t interp(trajpoint_t p1, trajpoint_t p2, uint64_t x);
    };

} // namespace RGF
