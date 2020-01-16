/*
** EPITECH PROJECT, 2019
** indie studio
** File description:
** SceneNodes.cpp
*/

#include "SceneNodes.hpp"

SceneNodes::SceneNodes(irr::scene::ISceneManager *sceneManager)
    : _nBombermanP1(sceneManager->addAnimatedMeshSceneNode(sceneManager
      ->getMesh("./source/media/bomberman_model/bomberman.b3d"))),
      _nBombermanP2(sceneManager->addAnimatedMeshSceneNode(sceneManager
      ->getMesh("./source/media/bomberman_model/bomberman.b3d"))),
      _nBombermanE1(sceneManager->addAnimatedMeshSceneNode(sceneManager
      ->getMesh("./source/media/bomberman_model/bomberman.b3d"))),
      _nBombermanE2(sceneManager->addAnimatedMeshSceneNode(sceneManager
      ->getMesh("./source/media/bomberman_model/bomberman.b3d"))),
      _iBomb(0), _iTerrain(0), _iBblocks(0), _iWall(0)
{}

void SceneNodes::configureSceneNodes(irr::video::IVideoDriver *driver,
     irr::IrrlichtDevice *device, indie_game::Monitor &monitor, irr::scene::ISceneManager *sceneManager)
{
    irr::core::vector3df pos;
    DOUBLETILE map = monitor.create();
    int l = 11;
    int k = 10;

    _nBombermanP1->setMaterialTexture(0,
    driver->getTexture("./source/media/bomberman_model/bomberman1.png"));
    _nBombermanP2->setMaterialTexture(0,
    driver->getTexture("./source/media/bomberman_model/bomberman2.png"));
    _nBombermanE1->setMaterialTexture(0,
    driver->getTexture("./source/media/bomberman_model/enemy.png"));
    _nBombermanE2->setMaterialTexture(0,
    driver->getTexture("./source/media/bomberman_model/enemy.png"));
    _nBombermanP1->setScale(irr::core::vector3df(2.f, 2.f, 2.f));
    _nBombermanP2->setScale(irr::core::vector3df(2.f, 2.f, 2.f));
    _nBombermanE1->setScale(irr::core::vector3df(2.f, 2.f, 2.f));
    _nBombermanE2->setScale(irr::core::vector3df(2.f, 2.f, 2.f));
    _nBombermanP1->setRotation(irr::core::vector3df(80.0f, 20.0f, 0.0f));
    _nBombermanP2->setRotation(irr::core::vector3df(80.0f, 20.0f, 0.0f));
    _nBombermanE1->setRotation(irr::core::vector3df(80.0f, 20.0f, 0.0f));
    _nBombermanE2->setRotation(irr::core::vector3df(80.0f, 20.0f, 0.0f));
    for (size_t i = 0; i < monitor.getMap().getHeight() + 1; i++) {
        k = 10;
        l--;
        for (size_t j = 0; j < monitor.getMap().getWidth() + 1; j++) {
            pos = irr::core::vector3df(k * 10, l * 10, 0);
            if (map[i][j].getTile() == indie_game::P1) {
                _nBombermanP1->setPosition(pos);
                _cubeNodeTerrain.push_back(sceneManager->addCubeSceneNode(10));
                _cubeNodeTerrain[_iTerrain]->setMaterialTexture(0, driver
                ->getTexture("./source/media/terrain/terrain.jpg"));
                _cubeNodeTerrain[_iTerrain]->setPosition(irr::core::vector3df(pos.X, pos.Y, -11));
                _iTerrain++;
            }
            else if (map[i][j].getTile() == indie_game::P2) {
                _nBombermanP2->setPosition(pos);
                _cubeNodeTerrain.push_back(sceneManager->addCubeSceneNode(10));
                _cubeNodeTerrain[_iTerrain]->setMaterialTexture(0, driver
                ->getTexture("./source/media/terrain/terrain.jpg"));
                _cubeNodeTerrain[_iTerrain]->setPosition(irr::core::vector3df(pos.X, pos.Y, -11));
                _iTerrain++;
            }
            else if (map[i][j].getTile() == indie_game::E1) {
                _nBombermanE1->setPosition(pos);
                _cubeNodeTerrain.push_back(sceneManager->addCubeSceneNode(10));
                _cubeNodeTerrain[_iTerrain]->setMaterialTexture(0, driver
                ->getTexture("./source/media/terrain/terrain.jpg"));
                _cubeNodeTerrain[_iTerrain]->setPosition(irr::core::vector3df(pos.X, pos.Y, -11));
                _iTerrain++;
            }
            else if (map[i][j].getTile() == indie_game::E2) {
                _nBombermanE2->setPosition(pos);
                _cubeNodeTerrain.push_back(sceneManager->addCubeSceneNode(10));
                _cubeNodeTerrain[_iTerrain]->setMaterialTexture(0, driver
                ->getTexture("./source/media/terrain/terrain.jpg"));
                _cubeNodeTerrain[_iTerrain]->setPosition(irr::core::vector3df(pos.X, pos.Y, -11));
                _iTerrain++;
            }
            else if (map[i][j].getTile() == indie_game::BBLOCKS) {
                    _cubeNodeBBlocks.push_back(sceneManager->addCubeSceneNode(10));
                    _cubeNodeBBlocks[_iBblocks]->setMaterialTexture(0, driver
                    ->getTexture("./source/media/box/box.png"));
                    _cubeNodeBBlocks[_iBblocks]->setPosition(pos);
                    _iBblocks++;
                    _cubeNodeTerrain.push_back(sceneManager->addCubeSceneNode(10));
                    _cubeNodeTerrain[_iTerrain]->setMaterialTexture(0, driver
                    ->getTexture("./source/media/terrain/terrain.jpg"));
                    _cubeNodeTerrain[_iTerrain]->setPosition(irr::core::vector3df(pos.X, pos.Y, -11));
                    _iTerrain++;
            }
            else if (map[i][j].getTile() == indie_game::WALL) {
                    _cubeNodeWall.push_back(sceneManager->addCubeSceneNode(10));
                    _cubeNodeWall[_iWall]->setMaterialTexture(0, driver
                    ->getTexture("./source/media/wall/wall.jpg"));
                    _cubeNodeWall[_iWall]->setPosition(pos);
                    _iWall++;

                    _cubeNodeTerrain.push_back(sceneManager->addCubeSceneNode(10));
                    _cubeNodeTerrain[_iTerrain]->setMaterialTexture(0, driver
                    ->getTexture("./source/media/terrain/terrain.jpg"));
                    _cubeNodeTerrain[_iTerrain]->setPosition(irr::core::vector3df(pos.X, pos.Y, -11));
                    _iTerrain++;
            }
            else if (map[i][j].getTile() == indie_game::EMPTY) {
                    _cubeNodeTerrain.push_back(sceneManager->addCubeSceneNode(10));
                    _cubeNodeTerrain[_iTerrain]->setMaterialTexture(0, driver
                    ->getTexture("./source/media/terrain/terrain.jpg"));
                    _cubeNodeTerrain[_iTerrain]->setPosition(irr::core::vector3df(pos.X, pos.Y, -11));
                    _iTerrain++;
            }
            else if (map[i][j].getTile() == indie_game::BONUS_BOMB) {
                    std::cout<<"|F";
            }
            else if (map[i][j].getTile() == indie_game::BONUS_SPEED)
                    std::cout<<"|L";
            else if (map[i][j].getTile() == indie_game::BONUS_FIREUP)
                    std::cout<<"|I";
            else if (map[i][j].getTile() == indie_game::BONUS_WALL_PASS)
                    std::cout<<"|T";
            k--;
        }
    }
}
