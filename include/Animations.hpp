/*
** EPITECH PROJECT, 2019
** Indie Studio
** File description:
** Animations.hpp
*/

#pragma once

#include <irrlicht/irrlicht.h>

class Animations {
public:
    Animations() = default;
    ~Animations() = default;
    void setUpAnimations(irr::scene::IParticleSystemSceneNode
    *particleSystem, irr::video::IVideoDriver *driver);
private:
    void configureParticles(irr::scene::IParticleSystemSceneNode
    *particleSystem, irr::video::IVideoDriver *driver);
};
