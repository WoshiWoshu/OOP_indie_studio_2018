/*
** EPITECH PROJECT, 2019
** indie
** File description:
** Animations.cpp
*/

#include "Animations.hpp"

void Animations::configureParticles(irr::scene::IParticleSystemSceneNode
    *particleSystem, irr::video::IVideoDriver *driver)
{
    irr::scene::IParticleEmitter *emitter(particleSystem->createBoxEmitter(
    irr::core::aabbox3d<irr::f32>(-6,0,-6,6,1,6),
    irr::core::vector3df(0.0f,0.06f,0.0f),
    80,100, irr::video::SColor(0,255,255,255),
    irr::video::SColor(0,255,255,255),
    800, 1000, 0, irr::core::dimension2df(10.f,2.f),
    irr::core::dimension2df(3.0f,3.0f)));
    irr::scene::IParticleAffector *affector(
    particleSystem->createFadeOutParticleAffector(
    irr::video::SColor(0,0,0,0), 1200));

    particleSystem->setEmitter(emitter);
    emitter->drop();
    particleSystem->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    particleSystem->setMaterialFlag(irr::video::EMF_ZWRITE_ENABLE, false);
    particleSystem->setMaterialTexture(0,
    driver->getTexture("./source/media/bomb/15725.bmp"));
    particleSystem->setScale(irr::core::vector3df(0.f, 0.f, 0.f));
    particleSystem->addAffector(affector);
    affector->drop();
}

void Animations::setUpAnimations(irr::scene::IParticleSystemSceneNode                 
    *particleSystem, irr::video::IVideoDriver *driver)
{
    this->configureParticles(particleSystem, driver);
}
