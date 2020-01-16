/*
** EPITECH PROJECT, 2019
** indie studio
** File description:
** SceneNodes.hpp
*/

#pragma once

#include <irrlicht/irrlicht.h>
#include <vector>
#include "Monitor.hpp"

class SceneNodes {
public:
    explicit SceneNodes(irr::scene::ISceneManager *sceneManager);
    ~SceneNodes() = default;
    void configureSceneNodes(irr::video::IVideoDriver *driver,
    irr::IrrlichtDevice *device, indie_game::Monitor &monitor,
    irr::scene::ISceneManager *sceneManager);
    inline irr::scene::IAnimatedMeshSceneNode
    *getBombermanP1(void) { return _nBombermanP1; }
    inline irr::scene::IAnimatedMeshSceneNode
    *getBombermanP2(void) { return _nBombermanP2; }
    inline irr::scene::IAnimatedMeshSceneNode
    *getBombermanE1(void) { return _nBombermanE1; }
    inline irr::scene::IAnimatedMeshSceneNode
    *getBombermanE2(void) { return _nBombermanE2; }
    inline std::vector<irr::scene::IMeshSceneNode *>
    getBomb(void) { return _bombNode; }
    inline std::vector<irr::scene::IMeshSceneNode *>
    getTerrain(void) { return _cubeNodeTerrain; }
private:
    irr::scene::IAnimatedMeshSceneNode *_nBombermanP1;
    irr::scene::IAnimatedMeshSceneNode *_nBombermanP2;
    irr::scene::IAnimatedMeshSceneNode *_nBombermanE1;
    irr::scene::IAnimatedMeshSceneNode *_nBombermanE2;
    std::vector<irr::scene::IMeshSceneNode *> _cubeNodeTerrain;
    std::vector<irr::scene::IMeshSceneNode *> _cubeNodeWall;
    std::vector<irr::scene::IMeshSceneNode *> _cubeNodeBBlocks;
    std::vector<irr::scene::IMeshSceneNode *> _bombNode;
    int _iBomb;
    int _iTerrain;
    int _iBblocks;
    int _iWall;
};
