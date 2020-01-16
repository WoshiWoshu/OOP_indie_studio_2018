/*
** EPITECH PROJECT, 2019
** IndieStudio
** File description:
** Graphics.hpp
*/

#ifndef OOP_INDIE_STUDIO_2018_GRAPHICS_H
#define OOP_INDIE_STUDIO_2018_GRAPHICS_H

#include <irrlicht/irrlicht.h>
#include <memory>
#include <string>
#include "Map.hpp"
#include "GraphicalInput.hpp"

namespace IndieStudioGraphicalEngine {
enum {
  GUI_ID_MENU_NEW_GAME_BUTTON = 101,
  GUI_ID_MENU_QUIT_BUTTON = 102
};
enum GraphicStateEnum {
  MENU,
  GAME,
  PAUSE,
  GAME_OVER
};
class GraphicState {
public:
  GraphicStateEnum state = GAME;
  GraphicState() {};
};
struct GameMenuContext {
  irr::IrrlichtDevice *device;
};

class GraphicEventReceiver : public irr::IEventReceiver {
public:
  GraphicEventReceiver(std::shared_ptr<GameMenuContext> context, std::shared_ptr<GraphicState> graphicState)
      : Context(*context.get()), graphicState(graphicState) {
    for (irr::u32 i = 0; i < irr::KEY_KEY_CODES_COUNT; i++) {
      KeyIsDown[i] = false;
    }
  }
  virtual bool OnEvent(const irr::SEvent &event) {
    if (event.EventType == irr::EET_KEY_INPUT_EVENT)
      KeyIsDown[event.KeyInput.Key] = event.KeyInput.PressedDown;
    else if (event.EventType == irr::EET_GUI_EVENT) {
      irr::s32 id = event.GUIEvent.Caller->getID();
      irr::gui::IGUIEnvironment *guienv = Context.device->getGUIEnvironment();

      if (event.GUIEvent.EventType == irr::gui::EGET_BUTTON_CLICKED) {
        if (id == GUI_ID_MENU_NEW_GAME_BUTTON) {
          graphicState.get()->state = GAME;
          Context.device->getLogger()->log(L"Game start button pressed");
        }
        if (id == GUI_ID_MENU_QUIT_BUTTON) {
          Context.device->getLogger()->log(L"Quit button pressed");
          Context.device->closeDevice();
          return true;
        }
      }
    }
    return false;
  }
  virtual bool IsKeyDown(irr::EKEY_CODE keyCode) const {
    return KeyIsDown[keyCode];
  }
private:
  bool KeyIsDown[irr::KEY_KEY_CODES_COUNT];
  std::shared_ptr<GraphicState> graphicState;
  GameMenuContext &Context;
};
enum KeyboardType { AZERTY, QWERTY };
class Graphic {
public:
  Graphic(const std::shared_ptr<GraphicState> graphicState, const std::shared_ptr<indie_game::Map> myGameMap)
      : graphicState(graphicState), gameMap(myGameMap) {

    int field_rows_count;
    int field_columns_count;
    int S;
    int halfS;
    int cubeSize = 10;
    indie_game::boomberCase tileType;
    this->device = irr::createDevice(irr::video::EDT_OPENGL,
                                     irr::core::dimension2d<irr::u32>(1080, 720),
                                     32, false, false, false, nullptr);
    if (!this->device)
      return;
    this->device->getLogger()->setLogLevel(irr::ELL_INFORMATION);
    this->videoDriver = this->device->getVideoDriver();
    this->context = std::make_shared<GameMenuContext>(GameMenuContext());
    this->context->device = this->device;
    this->guienv = device->getGUIEnvironment();
    this->smgr = device->getSceneManager();

    field_rows_count = this->gameMap->getHeight();
    field_columns_count = this->gameMap->getWidth();
    S = field_rows_count * field_columns_count;
    halfS = S * 0.5;

    this->gameMap->getField();
    std::vector<std::vector<irr::scene::ISceneNode *>> field_rows(field_rows_count);
    for (int j = 0; j < field_rows_count + 1; j++) {
      for (int k = 0; k < field_columns_count + 1; k++) {
        tileType = this->gameMap->getField()[j][k].getTile();
        irr::core::vector3df pos = irr::core::vector3df(k * 10, j * 10, 0);
        switch (tileType) {
        case indie_game::BOMB: {
          placeBomb(pos);
          break;
        }
        case indie_game::P1: {
          placeBomberman(pos, tileType);
          irr::core::vector3df newPos = irr::core::vector3df(pos.X, pos.Y, -cubeSize);
          placeCube("./source/media/terrain/terrain.jpg", newPos);
          break;
        }
        case indie_game::P2: {
          placeBomberman(pos, tileType);
          irr::core::vector3df newPos = irr::core::vector3df(pos.X, pos.Y, -cubeSize);
          placeCube("./source/media/terrain/terrain.jpg", newPos);
          break;
        }
        case indie_game::E1: {
          placeBomberman(pos, tileType);
          irr::core::vector3df newPos = irr::core::vector3df(pos.X, pos.Y, -cubeSize);
          placeCube("./source/media/terrain/terrain.jpg", newPos);
          break;
        }
        case indie_game::E2: {
          placeBomberman(pos, tileType);
          irr::core::vector3df newPos = irr::core::vector3df(pos.X, pos.Y, -cubeSize);
          placeCube("./source/media/terrain/terrain.jpg", newPos);
          break;
        }
        case indie_game::WALL: {
          placeCube("./source/media/wall/wall.jpg", pos);
          break;
        }
        case indie_game::BONUS_BOMB: break;
        case indie_game::BONUS_SPEED: break;
        case indie_game::BBLOCKS: {
          placeCube("./source/media/box/box.png", pos);
          irr::core::vector3df newPos = irr::core::vector3df(pos.X, pos.Y, -cubeSize);
          placeCube("./source/media/terrain/terrain.jpg", newPos);
          break;
        }
        case indie_game::EMPTY: {
          irr::core::vector3df newPos = irr::core::vector3df(pos.X, pos.Y, -cubeSize);
          placeCube("./source/media/terrain/terrain.jpg", newPos);
          break;
        }
        default: break;
        }
      }
    }
    smgr->addCameraSceneNode(nullptr, irr::core::vector3df(halfS, halfS, S), irr::core::vector3df(halfS, halfS, 10));
//    smgr->addCameraSceneNodeFPS();
  };
  void setupDrawing() {
    switch (this->graphicState.get()->state) {
    case MENU:drawMenuScene(this->device, this->videoDriver);
      break;
    case GAME:drawGameScene(this->device, this->videoDriver);
      break;
    default:return;
    }
  }
  void refresh() {};
  void placeCube(const irr::io::path &filename, irr::core::vector3df pos) {
    irr::scene::ISceneNode *cubeTerrain = smgr->addCubeSceneNode(10, nullptr, -1, pos);

    cubeTerrain->setMaterialTexture(0, videoDriver->getTexture(filename));
    cubeTerrain->setMaterialFlag(irr::video::EMF_LIGHTING, false);
  }
  void placeBomb(irr::core::vector3df pos) {
    irr::scene::IMesh *mesh;
    irr::scene::IMeshSceneNode *node;
    //mesh = smgr->getMesh("../source/media/bomb/bomb.b3d");
    node = smgr->addMeshSceneNode(mesh);
    node->setMaterialTexture(0, videoDriver->getTexture("./source/media/bomb/Albedo.png"));
    node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    node->setRotation(irr::core::vector3df(80.0f, 20.0f, 0.0f));
    node->setPosition(pos);
    node->setScale(irr::core::vector3df(10, 10, 10));
  }
  void placeBomberman(irr::core::vector3df pos, indie_game::boomberCase characterType) {
    irr::scene::IAnimatedMesh *mesh;
    irr::scene::IAnimatedMeshSceneNode *node;

    mesh = smgr->getMesh("./source/media/bomberman_model/bomberman_model.b3d");
    node = smgr->addAnimatedMeshSceneNode(mesh);
    node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    node->setRotation(irr::core::vector3df(80.0f, 20.0f, 0.0f));
    node->setPosition(pos);
    node->setScale(irr::core::vector3df(2, 2, 2));
    if (characterType == indie_game::P1) {
      node->setMaterialTexture(0, videoDriver->getTexture("./source/media/bomberman_model/bomberman1.png"));
      this->playerOneNode = node;
    } else if (characterType == indie_game::P2) {
      node->setMaterialTexture(0, videoDriver->getTexture("./source/media/bomberman_model/bomberman2.png"));
      this->playerTwoNode = node;
    } else if (characterType == indie_game::E1) {
      node->setMaterialTexture(0, videoDriver->getTexture("./source/media/bomberman_model/enemy.png"));
      this->enemyOneNode = node;
    } else {
      node->setMaterialTexture(0, videoDriver->getTexture("./source/media/bomberman_model/enemy.png"));
      this->enemyTwoNode = node;
    }
  }
  void drawMenuScene(irr::IrrlichtDevice *device, irr::video::IVideoDriver *videoDriver) {
    const irr::core::dimension2d<irr::u32> &screenSize = videoDriver->getScreenSize();
    std::string str =
        "Frame Size " + std::to_string(screenSize.Width) + "x" + std::to_string(screenSize.Height);
    std::wstring widestr = std::wstring(str.begin(), str.end());
    //device->getLogger()->log(widestr.c_str());
    irr::video::ITexture *image = videoDriver->getTexture("./source/media/eagletoons-inc-bomberman-transparent.jpg");
    videoDriver->draw2DImage(image, irr::core::position2d<irr::s32>(0, 0),
                             irr::core::rect<irr::s32>(0, 0, 1556, 1100), nullptr,
                             irr::video::SColor(255, 255, 255, 255), true);
    irr::core::rect<irr::s32> startButtonRect = irr::core::rect<irr::s32>(250, 20, 250 + 120, 50);
    irr::core::rect<irr::s32> quitButtonRect = irr::core::rect<irr::s32>(250, 20 + 20 + 10, 250 + 120, 50 + 50);

    irr::gui::IGUIButton *startGameBtn = this->guienv->addButton(startButtonRect, nullptr,
                                                                 GUI_ID_MENU_NEW_GAME_BUTTON, L"Start game",
                                                                 L"Press to start the game");
    irr::gui::IGUIButton *quitGameBtn = this->guienv->addButton(quitButtonRect, nullptr,
                                                                GUI_ID_MENU_QUIT_BUTTON, L"Quit",
                                                                L"Press to quit the game");
  }
  void drawGameScene(irr::IrrlichtDevice *device, irr::video::IVideoDriver *videoDriver) {
  }
  void myLog(irr::IrrlichtDevice *d, std::string msg, std::string label, std::string prefix, std::string postfix) {
    std::string str = label + " " + prefix + " " + msg + " " + postfix;
    std::wstring widestr = std::wstring(str.begin(), str.end());
    d->getLogger()->log(widestr.c_str(), irr::ELL_INFORMATION);
  }
  std::shared_ptr<GraphicalInput> handleKeyPress(GraphicEventReceiver *r, irr::IrrlichtDevice *d, KeyboardType kt) {
    std::shared_ptr<GraphicalInput> graphicalInput = std::make_shared<GraphicalInput>(GraphicalInput());
    switch (kt) {
    case AZERTY:
      if (r->IsKeyDown(irr::KEY_KEY_Z)) {
        myLog(d, "Z", "[CORE]", "Pressed", "key");
        graphicalInput->setP1(IndieStudioGraphicalEngine::input::UP);
      }
      if (r->IsKeyDown(irr::KEY_KEY_Q)) {
        myLog(d, "Q", "[CORE]", "Pressed", "key");
        graphicalInput->setP1(IndieStudioGraphicalEngine::input::LEFT);
      }
      if (r->IsKeyDown(irr::KEY_KEY_S)) {
        myLog(d, "S", "[CORE]", "Pressed", "key");
        graphicalInput->setP1(IndieStudioGraphicalEngine::input::DOWN);
      }
      if (r->IsKeyDown(irr::KEY_KEY_D)) {
        myLog(d, "D", "[CORE]", "Pressed", "key");
        graphicalInput->setP1(IndieStudioGraphicalEngine::input::LEFT);
      }
      if (r->IsKeyDown(irr::KEY_KEY_A)) {
        myLog(d, "A", "[CORE]", "Pressed", "key");
        graphicalInput->setP1(IndieStudioGraphicalEngine::input::PUTBOMB);
      }
      if (r->IsKeyDown(irr::KEY_KEY_O)) {
        myLog(d, "O", "[CORE]", "Pressed", "key");
        graphicalInput->setP2(IndieStudioGraphicalEngine::input::UP);
      }
      if (r->IsKeyDown(irr::KEY_KEY_K)) {
        myLog(d, "K", "[CORE]", "Pressed", "key");
        graphicalInput->setP2(IndieStudioGraphicalEngine::input::LEFT);
      }
      if (r->IsKeyDown(irr::KEY_KEY_L)) {
        myLog(d, "L", "[CORE]", "Pressed", "key");
        graphicalInput->setP2(IndieStudioGraphicalEngine::input::DOWN);
      }
      if (r->IsKeyDown(irr::KEY_KEY_M)) {
        myLog(d, "M", "[CORE]", "Pressed", "key");
        graphicalInput->setP2(IndieStudioGraphicalEngine::input::RIGHT);
      }
      if (r->IsKeyDown(irr::KEY_KEY_P)) {
        myLog(d, "P", "[CORE]", "Pressed", "key");
        graphicalInput->setP2(IndieStudioGraphicalEngine::input::PUTBOMB);
      }
    case QWERTY:
      if (r->IsKeyDown(irr::KEY_KEY_W)) {
        myLog(d, "W", "[CORE]", "Pressed", "key");
        graphicalInput->setP1(IndieStudioGraphicalEngine::input::UP);
      }
      if (r->IsKeyDown(irr::KEY_KEY_A)) {
        myLog(d, "A", "[CORE]", "Pressed", "key");
        graphicalInput->setP1(IndieStudioGraphicalEngine::input::LEFT);
      }
      if (r->IsKeyDown(irr::KEY_KEY_S)) {
        myLog(d, "S", "[CORE]", "Pressed", "key");
        graphicalInput->setP1(IndieStudioGraphicalEngine::input::DOWN);
      }
      if (r->IsKeyDown(irr::KEY_KEY_D)) {
        myLog(d, "D", "[CORE]", "Pressed", "key");
        graphicalInput->setP1(IndieStudioGraphicalEngine::input::RIGHT);
      }
      if (r->IsKeyDown(irr::KEY_KEY_Q)) {
        myLog(d, "Q", "[CORE]", "Pressed", "key");
        graphicalInput->setP1(IndieStudioGraphicalEngine::input::PUTBOMB);
      }
      if (r->IsKeyDown(irr::KEY_KEY_O)) {
        myLog(d, "O", "[CORE]", "Pressed", "key");
        graphicalInput->setP2(IndieStudioGraphicalEngine::input::UP);
      }
      if (r->IsKeyDown(irr::KEY_KEY_K)) {
        myLog(d, "K", "[CORE]", "Pressed", "key");
        graphicalInput->setP2(IndieStudioGraphicalEngine::input::LEFT);
      }
      if (r->IsKeyDown(irr::KEY_KEY_L)) {
        myLog(d, "L", "[CORE]", "Pressed", "key");
        graphicalInput->setP2(IndieStudioGraphicalEngine::input::DOWN);
      }
      if (r->IsKeyDown(irr::KEY_OEM_1)) {
        myLog(d, ":;", "[CORE]", "Pressed", "key");
        graphicalInput->setP2(IndieStudioGraphicalEngine::input::RIGHT);
      }
      if (r->IsKeyDown(irr::KEY_KEY_P)) {
        myLog(d, "P", "[CORE]", "Pressed", "key");
        graphicalInput->setP2(IndieStudioGraphicalEngine::input::PUTBOMB);
      }
    }
    if (r->IsKeyDown(irr::KEY_ESCAPE)) {
      myLog(d, "Escape", "[CORE]", "Pressed", "key");
    }
    if (r->IsKeyDown(irr::KEY_UP)) {
      myLog(d, "Up", "[CORE]", "Pressed", "key");
    }
    if (r->IsKeyDown(irr::KEY_LEFT)) {
      myLog(d, "Left", "[CORE]", "Pressed", "key");
    }
    if (r->IsKeyDown(irr::KEY_DOWN)) {
      myLog(d, "Down", "[CORE]", "Pressed", "key");
    }
    if (r->IsKeyDown(irr::KEY_RIGHT)) {
      myLog(d, "Right", "[CORE]", "Pressed", "key");
    }
    if (r->IsKeyDown(irr::KEY_RETURN)) {
      myLog(d, "Return", "[CORE]", "Pressed", "key");
    }
    return graphicalInput;
  }

  irr::gui::IGUIEnvironment *guienv;
  irr::scene::ISceneManager *smgr;
  std::shared_ptr<GraphicState> graphicState;
  std::shared_ptr<GameMenuContext> context;
  irr::IrrlichtDevice *device;
  irr::video::IVideoDriver *videoDriver;
  std::shared_ptr<indie_game::Map> gameMap;
  irr::scene::IAnimatedMeshSceneNode *playerOneNode;
  irr::scene::IAnimatedMeshSceneNode *playerTwoNode;
  irr::scene::IAnimatedMeshSceneNode *enemyOneNode;
  irr::scene::IAnimatedMeshSceneNode *enemyTwoNode;
};
}

#endif //OOP_INDIE_STUDIO_2018_GRAPHICS_H
