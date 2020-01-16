/*
** EPITECH PROJECT, 2019
** test
** File description:
** test
*/

#include <string>
#include <iostream>
#include "CEventReceiver.hpp"

CEventReceiver::CEventReceiver(irr::scene::IAnimatedMeshSceneNode* nModel,
                               irr::scene::IAnimatedMeshSceneNode* nModel2,
                               irr::scene::IAnimatedMeshSceneNode* nModelE1,
                               irr::scene::IAnimatedMeshSceneNode* nModelE2,
                               std::vector<irr::scene::IMeshSceneNode *> nbombNode,
                               std::vector<irr::scene::IMeshSceneNode *> nCubeNodeTerrain) :
    _nModel(nModel), _nModel2(nModel2), _nModelE1(nModelE1), _nModelE2(nModelE2),
    _nbombNode(nbombNode), _nCubeNodeTerrain(nCubeNodeTerrain), _iBomb(0), _iParticule(0), _iTerrain(0), _state(indie_graph::GS::MENU)
{}

bool CEventReceiver::OnEvent(const irr::SEvent &event)
{
    if(_nModel != 0
    && event.EventType == irr::EET_KEY_INPUT_EVENT) {
        switch (event.KeyInput.Key) {
            case irr::KEY_KEY_Q:
                _isMoving[0] = event.KeyInput.PressedDown;
                _inputInfo[0] = LEFT;
                break;
            case irr::KEY_KEY_D:
                _isMoving[1] = event.KeyInput.PressedDown;
                _inputInfo[0] = RIGHT;
                break;
            case irr::KEY_KEY_Z:
                _isMoving[2] = event.KeyInput.PressedDown;
                _inputInfo[0] = UP;
                break;
            case irr::KEY_KEY_S:
                _isMoving[3] = event.KeyInput.PressedDown;
                _inputInfo[0] = DOWN;
                break;
            case irr::KEY_KEY_J:
                _isMoving[4] = event.KeyInput.PressedDown;
                _inputInfo[1] = LEFT;
                break;
            case irr::KEY_KEY_L:
                _isMoving[5] = event.KeyInput.PressedDown;
                _inputInfo[1] = RIGHT;
                break;
            case irr::KEY_KEY_I:
                _isMoving[6] = event.KeyInput.PressedDown;
                _inputInfo[1] = UP;
                break;
            case irr::KEY_KEY_K:
                _isMoving[7] = event.KeyInput.PressedDown;
                _inputInfo[1] = DOWN;
                break;
            case irr::KEY_KEY_C:
                _isBomb[0] = event.KeyInput.PressedDown;
                _inputInfo[0] = PUTBOMB;
                break;
            case irr::KEY_KEY_N:
                _isBomb[1] = event.KeyInput.PressedDown;
                _inputInfo[1] = PUTBOMB;
                break;
            case irr::KEY_ESCAPE:

                setState(indie_graph::GS::MENU);
                break;
            case irr::KEY_RETURN:
                setState(indie_graph::GS::GAME);
                break;
            default:
                return false;
        }
        return true;
    } else if (event.EventType == irr::EET_GUI_EVENT) {
        irr::s32 id = event.GUIEvent.Caller->getID();

        if (event.GUIEvent.EventType == irr::gui::EGET_BUTTON_CLICKED) {
            switch(id) {
                case BUTTONS::GUI_ID_QUIT:
                    exit(0);
                    break;
                case BUTTONS::GUI_ID_PLAY:
                    setState(indie_graph::GS::GAME);
                    break;
                case BUTTONS::GUI_ID_RELOAD:
                    setState(indie_graph::GS::MENU);
                    break;
                default:
                    return false;
            }
            return true;
        }
    }
    return false;
}

void CEventReceiver::setInputsP1(const irr::f32 frameDeltaTime,
    indie_game::boomberCase boomCase, irr::video::IVideoDriver *driver,
    irr::scene::ISceneManager *sceneManager, int x, int y)
{
    // irr::core::vector3df v = _nModel->getPosition();
    // irr::core::vector3df r = _nModel->getRotation();
    irr::core::vector3df currentPos = _nModel->getPosition();
    irr::core::vector3df r = _nModel->getRotation();
    irr::core::vector3df newPos(x * 10, y * 10, 0);
    irr::scene::ISceneNodeAnimator *anim;

    if(_nModel != 0 && _isBomb[0]
    && boomCase == indie_game::BOMB) {
    _nbombNode.push_back(sceneManager
    ->addMeshSceneNode(sceneManager->getMesh("./source/media/bomb/bomb.b3d")));
    _nbombNode[_iBomb]->setMaterialTexture(0, driver
    ->getTexture("./source/media/bomb/Albedo.png"));
    _nbombNode[_iBomb]->setPosition(irr::core::vector3df(x * 10, y * 10, 0));
    _nbombNode[_iBomb]->setScale(irr::core::vector3df(10, 10, 10));
    _iBomb++;
    } else if(_nModel != 0 && _isMoving[0] &&
    boomCase == indie_game::P1)
    {
        anim = sceneManager->createFlyStraightAnimator(currentPos, newPos, 1000, false, false);
        _nModel->addAnimator(anim);
        anim->drop();
        _nModel->setRotation(irr::core::vector3df(80.0f, 20.0f, 620.0f));
    }
    else if (_nModel != 0
    && _isMoving[1] &&
    boomCase == indie_game::P1) {
        anim = sceneManager->createFlyStraightAnimator(currentPos, newPos, 1000, false, false);
        _nModel->addAnimator(anim);
        anim->drop();
        _nModel->setRotation(irr::core::vector3df(80.0f, 20.0f, 100.0f));
    //v.X -= x * frameDeltaTime;
    // r.Y = 90.0f;
    }
    else if(_nModel != 0 && _isMoving[2]
    && boomCase == indie_game::P1) {
        anim = sceneManager->createFlyStraightAnimator(currentPos, newPos, 1000, false, false);
        _nModel->addAnimator(anim);
        anim->drop();
        _nModel->setRotation(irr::core::vector3df(80.0f, 20.0f, 0.0f));
    //v.Y += y * frameDeltaTime;
    //r.Y = 10.0f;
    }
    else if (_nModel != 0 && _isMoving[3]
    && boomCase == indie_game::P1) {
        anim = sceneManager->createFlyStraightAnimator(currentPos, newPos, 1000, false, false);
        _nModel->addAnimator(anim);
        anim->drop();
        _nModel->setRotation(irr::core::vector3df(-40.0f, -180.0f, -10.0f));
        //v.Y -= y * frameDeltaTime;
        //r.Y = 190.0f;
    }
}

void CEventReceiver::setInputsP2(const irr::f32 frameDeltaTime,
     indie_game::boomberCase boomCase, irr::video::IVideoDriver *driver,
     irr::scene::ISceneManager *sceneManager, int x, int y)
{
    irr::core::vector3df currentPos = _nModel2->getPosition();
    irr::core::vector3df r = _nModel2->getRotation();
    irr::core::vector3df newPos(x * 10, y * 10, 0);
    irr::scene::ISceneNodeAnimator *anim;

    //std::cout << (int) _inputInfo[0] << std::endl;
    if (_nModel2 != 0 && _isBomb[1]
    && boomCase == indie_game::BOMB) {
    _nbombNode.push_back(sceneManager
    ->addMeshSceneNode(sceneManager->getMesh("./source/media/bomb/bomb.b3d")));
    _nbombNode[_iBomb]->setMaterialTexture(0, driver
    ->getTexture("./source/media/bomb/Albedo.png"));
    _nbombNode[_iBomb]->setPosition(newPos);
    _nbombNode[_iBomb]->setScale(irr::core::vector3df(10, 10, 10));
    _iBomb++;
    }
    else if(_nModel2 != 0 && _isMoving[4] &&
    boomCase == indie_game::P2)
    {
        anim = sceneManager->createFlyStraightAnimator(currentPos, newPos, 1000, false, false);
        _nModel2->addAnimator(anim);
        anim->drop();
        _nModel2->setRotation(irr::core::vector3df(80.0f, 20.0f, 620.0f));
    }
    else if (_nModel2 != 0
    && _isMoving[5] &&
    boomCase == indie_game::P2) {
        anim = sceneManager->createFlyStraightAnimator(currentPos, newPos, 1000, false, false);
        _nModel2->addAnimator(anim);
        anim->drop();
        _nModel2->setRotation(irr::core::vector3df(80.0f, 20.0f, 100.0f));
    //v.X -= x * frameDeltaTime;
    // r.Y = 90.0f;
    }
    else if(_nModel2 != 0 && _isMoving[6]
    && boomCase == indie_game::P2) {
        anim = sceneManager->createFlyStraightAnimator(currentPos, newPos, 1000, false, false);
        _nModel2->addAnimator(anim);
        anim->drop();
        _nModel2->setRotation(irr::core::vector3df(80.0f, 20.0f, 0.0f));
    //v.Y += y * frameDeltaTime;
    //r.Y = 10.0f;
    }
    else if (_nModel2 != 0 && _isMoving[7]
    && boomCase == indie_game::P2) {
        anim = sceneManager->createFlyStraightAnimator(currentPos, newPos, 1000, false, false);
        _nModel2->addAnimator(anim);
        anim->drop();
        _nModel2->setRotation(irr::core::vector3df(-40.0f, -180.0f, -10.0f));
        //v.Y -= y * frameDeltaTime;
        //r.Y = 190.0f;
    }
}

void CEventReceiver::triggerAnimPlayer1(indie_game::boomberCase boomCase)
{
    if (_isWalking[0] == false && boomCase == indie_game::P1
    &&
    (_isMoving[0] || _isMoving[1] || _isMoving[2] || _isMoving[3])) {
        _isStanding[0] = false;
        _isWalking[0] = true;
        _nModel->setFrameLoop(0, 50);
        _nModel->setAnimationSpeed(190);
    }
    else {
        if (!_isMoving[0] && !_isMoving[1] && !_isMoving[2] && !_isMoving[3]) {
            _inputInfo[0] = NOP;
            _isWalking[0] = false;
            if (_isStanding[0] == false) {
                _isStanding[0] = true;
                _nModel->setFrameLoop(0, 0);
                _nModel->setAnimationSpeed(0);
            }
        }
    }
}


void CEventReceiver::triggerAnimPlayer2(indie_game::boomberCase boomCase)
{
    if (_isWalking[1] == false && boomCase == indie_game::P2 &&
    (_isMoving[4] || _isMoving[5] || _isMoving[6] || _isMoving[7])) {
        _isStanding[1] = false;
        _isWalking[1] = true;
        _nModel2->setFrameLoop(0, 50);
        _nModel2->setAnimationSpeed(190);
    }
    else {
        if (!_isMoving[4] && !_isMoving[5] && !_isMoving[6] && !_isMoving[7]) {
            _inputInfo[1] = NOP;
            _isWalking[1] = false;
            if (_isStanding[1] == false) {
                _isStanding[1] = true;
                _nModel2->setFrameLoop(0, 0);
                _nModel2->setAnimationSpeed(0);
            }
        }
    }
}

void CEventReceiver::setInputs(const irr::f32 frameDeltaTime,
    indie_game::boomberCase boomCase, irr::video::IVideoDriver *driver,
    irr::scene::ISceneManager *sceneManager, int x, int y)
{
    irr::core::vector3df newPos(x * 10, y * 10, 0);
    irr::core::vector3df currentPos;
    irr::scene::ISceneNodeAnimator *anim;

    if (_nModelE1 != 0 && boomCase == indie_game::E1) {
        currentPos = _nModelE1->getPosition();
        anim = sceneManager->createFlyStraightAnimator(currentPos, newPos, 1000, false, false);
        _nModelE1->addAnimator(anim);
        anim->drop();
    }
    if (_nModelE2 != 0 && boomCase == indie_game::E2) {
        currentPos = _nModelE2->getPosition();
        anim = sceneManager->createFlyStraightAnimator(currentPos, newPos, 1000, false, false);
        _nModelE2->addAnimator(anim);
        anim->drop();
    }
    if (boomCase == indie_game::BLAST) {
        _particleSystem.push_back(sceneManager->addParticleSystemSceneNode(false));
        _particleSystem[_iParticule]->setPosition(newPos);
        _animations.setUpAnimations(_particleSystem[_iParticule], driver);
    }
    if (boomCase == indie_game::EMPTY) {
        _nCubeNodeTerrain.push_back(sceneManager->addCubeSceneNode(10));
        _nCubeNodeTerrain[_iTerrain]->setMaterialTexture(0, driver
        ->getTexture("./source/media/terrain/terrain.jpg"));
        _nCubeNodeTerrain[_iTerrain]->setPosition(irr::core::vector3df(newPos.X, newPos.Y, 0));
        _iTerrain++;
    }
    if (boomCase == indie_game::BONUS_BOMB) {
        _nCubeNodeTerrain.push_back(sceneManager->addCubeSceneNode(10));
        _nCubeNodeTerrain[_iTerrain]->setMaterialTexture(0, driver
        ->getTexture("./source/media/terrain/terrain.jpg"));
        _nCubeNodeTerrain[_iTerrain]->setPosition(irr::core::vector3df(newPos.X, newPos.Y, 0));
        _iTerrain++;
        _nCubeNodeTerrain.push_back(sceneManager->addCubeSceneNode(10));
        _nCubeNodeTerrain[_iTerrain]->setMaterialTexture(0, driver
        ->getTexture("./source/media/terrain/bonus_bomb.png"));
        _nCubeNodeTerrain[_iTerrain]->setPosition(irr::core::vector3df(newPos.X, newPos.Y, 0));
        _iTerrain++;
    }
    if (boomCase == indie_game::BONUS_FIREUP) {
        _nCubeNodeTerrain.push_back(sceneManager->addCubeSceneNode(10));
        _nCubeNodeTerrain[_iTerrain]->setMaterialTexture(0, driver
        ->getTexture("./source/media/terrain/terrain.jpg"));
        _nCubeNodeTerrain[_iTerrain]->setPosition(irr::core::vector3df(newPos.X, newPos.Y, 0));
        _iTerrain++;
        _nCubeNodeTerrain.push_back(sceneManager->addCubeSceneNode(10));
        _nCubeNodeTerrain[_iTerrain]->setMaterialTexture(0, driver
        ->getTexture("./source/media/terrain/fireup.png"));
        _nCubeNodeTerrain[_iTerrain]->setPosition(irr::core::vector3df(newPos.X, newPos.Y, 0));
        _iTerrain++;
    }
    if (boomCase == indie_game::BONUS_SPEED) {
        _nCubeNodeTerrain.push_back(sceneManager->addCubeSceneNode(10));
        _nCubeNodeTerrain[_iTerrain]->setMaterialTexture(0, driver
        ->getTexture("./source/media/terrain/terrain.jpg"));
        _nCubeNodeTerrain[_iTerrain]->setPosition(irr::core::vector3df(newPos.X, newPos.Y, 0));
        _iTerrain++;
        _nCubeNodeTerrain.push_back(sceneManager->addCubeSceneNode(10));
        _nCubeNodeTerrain[_iTerrain]->setMaterialTexture(0, driver
        ->getTexture("./source/media/terrain/speedup.png"));
        _nCubeNodeTerrain[_iTerrain]->setPosition(irr::core::vector3df(newPos.X, newPos.Y, 0));
        _iTerrain++;
    }
    if (boomCase == indie_game::BONUS_WALL_PASS) {
        _nCubeNodeTerrain.push_back(sceneManager->addCubeSceneNode(10));
        _nCubeNodeTerrain[_iTerrain]->setMaterialTexture(0, driver
        ->getTexture("./source/media/terrain/terrain.jpg"));
        _nCubeNodeTerrain[_iTerrain]->setPosition(irr::core::vector3df(newPos.X, newPos.Y, 0));
        _iTerrain++;
        _nCubeNodeTerrain.push_back(sceneManager->addCubeSceneNode(10));
        _nCubeNodeTerrain[_iTerrain]->setMaterialTexture(0, driver
        ->getTexture("./source/media/terrain/wallpass.png"));
        _nCubeNodeTerrain[_iTerrain]->setPosition(irr::core::vector3df(newPos.X, newPos.Y, 0));
        _iTerrain++;
    }
    if(boomCase == indie_game::LOSE)
        setState(indie_graph::GS::GO);
    this->setInputsP1(frameDeltaTime, boomCase, driver, sceneManager, x, y);
    this->setInputsP2(frameDeltaTime, boomCase, driver, sceneManager, x, y);
    this->triggerAnimPlayer1(boomCase);
    this->triggerAnimPlayer2(boomCase);
}
