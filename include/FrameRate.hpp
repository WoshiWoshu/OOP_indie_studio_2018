/*
** EPITECH PROJECT, 2019
** indie studio
** File description:
** FrameRate.hpp
*/

#pragma once

#include <irrlicht/irrlicht.h>

class FrameRate {
public:
    explicit inline FrameRate(irr::IrrlichtDevice *device)
    : _then(device->getTimer()->getTime()), _now(0), _frameDeltaTime(0) {}
    ~FrameRate() = default;
    inline void setNow(irr::IrrlichtDevice *device)
    { _now = device->getTimer()->getTime(); }
    inline void setThen(void) { _then = _now; }
    inline void setFrameDeltaTime(void) { _frameDeltaTime =
    (irr::f32)(_now - _then) / 120.f; }
    inline irr::f32 getFrameDeltaTime(void) { return _frameDeltaTime; }
private:
    irr::u32 _then;
    irr::u32 _now;
    irr::f32 _frameDeltaTime;
};
