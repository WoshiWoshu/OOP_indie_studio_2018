
#include "Monitor.hpp"

indie_game::Monitor::Monitor()
{
    ProceduralGeneration procedure(10, 10);
    procedure.generateMap();
    _mapProcedure = procedure.getMap();
    _map = procedure.getMap().getField();
    setPlayer();
    procedure.printMap();
    _over = false;
    _gameOv = NOP;
}

indie_game::Monitor::~Monitor() {}

DOUBLETILE indie_game::Monitor::create() {
    return _map;
}

void indie_game::Monitor::printMap(){
    for (size_t i = 0; i < _mapProcedure.getHeight()+1; i++) {
        for (size_t j = 0; j < _mapProcedure.getWidth()+1; j++) {
            if (_map[i][j].getTile() == BOMB)
                std::cout<<"|B";
            else if (_map[i][j].getTile() == P1)
                std::cout<<"|P";
            else if (_map[i][j].getTile() == P2)
                std::cout<<"|2";
            else if (_map[i][j].getTile() == E1)
                std::cout<<"|E";
            else if (_map[i][j].getTile() == E2)
                std::cout<<"|3";
            else if (_map[i][j].getTile() == BBLOCKS)
                    std::cout<<"|D";
            else if (_map[i][j].getTile() == WALL)
                    std::cout<<"|W";
            else if (_map[i][j].getTile() == EMPTY)
                    std::cout<<"| ";
            else if (_map[i][j].getTile() == BONUS_BOMB)
                    std::cout<<"|F";
            else if (_map[i][j].getTile() == BONUS_SPEED)
                    std::cout<<"|L";
            else if (_map[i][j].getTile() == BONUS_FIREUP)
                    std::cout<<"|I";
            else if (_map[i][j].getTile() == BONUS_WALL_PASS)
                    std::cout<<"|T";
            else
                std::cout<<"|S";
        }
        std::cout<<"|"<<std::endl;
    }
}

Graph indie_game::Monitor::controlBlast(Graph blast)
{
    Graph newBlast;
    Point irTest;
    std::tuple<indie_game::boomberCase, Point, Point> newTuple;
    bool wall1 = true;
    bool wall2 = true;
    bool wall3 = true;
    bool wall4 = true;

    irTest.setXY(10 - std::get<1>(blast[0]).getY(), 10 - std::get<1>(blast[0]).getX());
    newTuple = std::make_tuple(BLAST, irTest, irTest);
    newBlast.push_back(newTuple);
    newTuple = std::make_tuple(BLAST, std::get<1>(blast[0]), std::get<1>(blast[0]));
    _blastSave.push_back(newTuple);

    for (size_t i = 1; i < blast.size(); i+=4) {
        if (std::get<1>(blast[i]).getY() >= 0) {
            if (_map[std::get<1>(blast[i]).getX()][std::get<1>(blast[i]).getY()].getTile() != WALL && wall1) {
                irTest.setXY(10 - std::get<1>(blast[i]).getY(), 10 - std::get<1>(blast[i]).getX());
                newTuple = std::make_tuple(BLAST, irTest, irTest);
                newBlast.push_back(newTuple);
                newTuple = std::make_tuple(BLAST, std::get<1>(blast[i]), std::get<1>(blast[i]));
                _blastSave.push_back(newTuple);
            }
            else wall1 = false;
        } if (std::get<1>(blast[i+1]).getX() >= 0) {
            if (_map[std::get<1>(blast[i+1]).getX()][std::get<1>(blast[i+1]).getY()].getTile() != WALL && wall2) {
                irTest.setXY(10 - std::get<1>(blast[i+1]).getY(), 10 - std::get<1>(blast[i+1]).getX());
                newTuple = std::make_tuple(BLAST, irTest, irTest);
                newBlast.push_back(newTuple);
                newTuple = std::make_tuple(BLAST, std::get<1>(blast[i+1]), std::get<1>(blast[i+1]));
                _blastSave.push_back(newTuple);
            }
            else wall2 = false;
        } if (std::get<1>(blast[i+2]).getX() < _mapProcedure.getHeight()+1) {
            if (_map[std::get<1>(blast[i+2]).getX()][std::get<1>(blast[i+2]).getY()].getTile() != WALL && wall3) {
                irTest.setXY(10 - std::get<1>(blast[i+2]).getY(), 10 - std::get<1>(blast[i+2]).getX());
                newTuple = std::make_tuple(BLAST, irTest, irTest);
                newBlast.push_back(newTuple);
                newTuple = std::make_tuple(BLAST, std::get<1>(blast[i+2]), std::get<1>(blast[i+2]));
                _blastSave.push_back(newTuple);
            }
            else wall3 = false;
        } if (std::get<1>(blast[i+3]).getY() < _mapProcedure.getWidth()+1) {
            if (_map[std::get<1>(blast[i+3]).getX()][std::get<1>(blast[i+3]).getY()].getTile() != WALL && wall4) {
                irTest.setXY(10 - std::get<1>(blast[i+3]).getY(), 10 - std::get<1>(blast[i+3]).getX());
                newTuple = std::make_tuple(BLAST, irTest, irTest);
                newBlast.push_back(newTuple);
                newTuple = std::make_tuple(BLAST, std::get<1>(blast[i+3]), std::get<1>(blast[i+3]));
                _blastSave.push_back(newTuple);
            }
            else wall4 = false;
        }
    }

    return newBlast;
}

Graph indie_game::Monitor::manageEnemy(Graph moveEnemy)
{
    Graph moveE;
    Point lastPos;
    Point irTest;
    std::tuple<indie_game::boomberCase, Point, Point> newTuple;

    for (size_t i = 0; i < moveEnemy.size(); ++i) {
        if (((std::get<2>(moveEnemy[i]).getY() >= 0) &&
                (std::get<2>(moveEnemy[i]).getY() < _mapProcedure.getWidth()+1)) &&
                ((std::get<2>(moveEnemy[i]).getX() >= 0) &&
                (std::get<2>(moveEnemy[i]).getX() < _mapProcedure.getHeight()+1))) {
            if (_map[std::get<2>(moveEnemy[i]).getX()][std::get<2>(moveEnemy[i]).getY()].getTile() == P1) {
                _p1.setLife();
                irTest.setXY(10 - _p1.getPosition().getY(), 10 - _p1.getPosition().getX());
                newTuple = std::make_tuple(P_DEAD, irTest, irTest);
                moveE.push_back(newTuple);
                _map[std::get<2>(moveEnemy[i]).getX()][std::get<2>(moveEnemy[i]).getY()].setTile(EMPTY);
            }
            if (_map[std::get<2>(moveEnemy[i]).getX()][std::get<2>(moveEnemy[i]).getY()].getTile() == P2) {
                _p2.setLife();
                irTest.setXY(10 - _p2.getPosition().getY(), 10 - _p2.getPosition().getX());
                newTuple = std::make_tuple(P_DEAD, irTest, irTest);
                moveE.push_back(newTuple);
                _map[std::get<2>(moveEnemy[i]).getX()][std::get<2>(moveEnemy[i]).getY()].setTile(EMPTY);
            }
            if (checkMoveEnemy(_map[std::get<2>(moveEnemy[i]).getX()][std::get<2>(moveEnemy[i]).getY()].getTile())) {
                _map[std::get<1>(moveEnemy[i]).getX()][std::get<1>(moveEnemy[i]).getY()].setTile(EMPTY);
                _map[std::get<2>(moveEnemy[i]).getX()][std::get<2>(moveEnemy[i]).getY()].setTile(std::get<0>(moveEnemy[i]));
                irTest.setXY(10 - std::get<2>(moveEnemy[i]).getY(), 10 - std::get<2>(moveEnemy[i]).getX());
                lastPos.setXY(10 - std::get<1>(moveEnemy[i]).getY(), 10 - std::get<1>(moveEnemy[i]).getX());
                newTuple = std::make_tuple(std::get<0>(moveEnemy[i]), lastPos, irTest);
                moveE.push_back(newTuple);
            }
            else {
                if (std::get<0>(moveEnemy[i]) == E1)
                    _enemy.movBot1(std::get<1>(moveEnemy[i]));
                else _enemy.movBot2(std::get<1>(moveEnemy[i]));
            }
        } else {
            if (std::get<0>(moveEnemy[i]) == E1)
                _enemy.movBot1(std::get<1>(moveEnemy[i]));
            else _enemy.movBot2(std::get<1>(moveEnemy[i]));
        }
    }

    return moveE;
}

bool indie_game::Monitor::checkMoveEnemy(boomberCase cas)
{
    switch (cas) {
        case E1:
            return false;
            break;
        case E2:
            return false;
            break;
        case WALL:
            return false;
            break;
        case BOMB:
            return false;
            break;
        case BBLOCKS:
            return false;
            break;
        default:
            return true;
            break;
    }
}

Graph indie_game::Monitor::run(IndieStudioGraphicalEngine::GraphicalInput input)
{
    if (!_over) {
        Graph gameState = checkBomb();
        Graph changeState = makeChangeState(_p1, _p2, input);
        const Graph moveE = _enemy.run();
        Graph stateEnemy = manageEnemy(moveE);
        Graph gameOv = manageGover(moveE);

        if (gameState.empty())
            gameState.insert(gameState.begin(), changeState.begin(), changeState.end());
        else
            gameState.insert(gameState.end(), changeState.begin(), changeState.end());
        if (!stateEnemy.empty())
            gameState.insert(gameState.end(), stateEnemy.begin(), stateEnemy.end());
        if (!gameOv.empty()) {
            gameState.insert(gameState.end(), gameOv.begin(), gameOv.end());
            _over = true;
        }
        //printMap();
        return gameState;
    } else return (gameOver());
}

Graph indie_game::Monitor::gameOver()
{
    std::tuple<indie_game::boomberCase, Point, Point> newTuple;
    Graph gameOv;
    newTuple = std::make_tuple(_gameOv, _p1.getPosition(), _p1.getPosition());
    gameOv.push_back(newTuple);
    return gameOv;
}

Graph indie_game::Monitor::manageGover(Graph moveE)
{
    std::tuple<indie_game::boomberCase, Point, Point> newTuple;
    Graph gameOv;

    if (moveE.empty() && _p1.getLife() && !_p2.getLife()) {
        newTuple = std::make_tuple(P1_WIN, _p1.getPosition(), _p1.getPosition());
        gameOv.push_back(newTuple);
        _gameOv = P1_WIN;
        std::cout << "P1 WIN" << std::endl;
    }
    if (moveE.empty() && !_p1.getLife() && _p2.getLife()) {
        newTuple = std::make_tuple(P2_WIN, _p1.getPosition(), _p1.getPosition());
        gameOv.push_back(newTuple);
        _gameOv = P2_WIN;
        std::cout << "P2 WIN" << std::endl;
    }
    if (!moveE.empty() && !_p1.getLife() && !_p2.getLife()) {
        newTuple = std::make_tuple(LOSE, _p1.getPosition(), _p1.getPosition());
        gameOv.push_back(newTuple);
        _gameOv = LOSE;
        std::cout << "LOSE" << std::endl;
    }

    return gameOv;
}

void indie_game::Monitor::setPlayer()
{
    _p1.setID(PLAYER1);
    _p2.setID(PLAYER2);

    if (_map[0][0].getTile() == P1) {
        _p1.setPosition(0, 0);
        _p2.setPosition(_mapProcedure.getHeight(), _mapProcedure.getWidth());
        Point e1(_mapProcedure.getHeight(), 0);
        Point e2(0, _mapProcedure.getWidth());
        _enemy.setEnemy(e1, e2);
    } else if (_map[0][_mapProcedure.getWidth()].getTile() == P1) {
        _p1.setPosition(0, _mapProcedure.getWidth());
        _p2.setPosition(_mapProcedure.getHeight(), 0);
        Point e1(_mapProcedure.getHeight(), _mapProcedure.getWidth());
        Point e2(0, 0);
        _enemy.setEnemy(e1, e2);
    } else if (_map[_mapProcedure.getHeight()][_mapProcedure.getWidth()].getTile() == P1) {
        _p1.setPosition(_mapProcedure.getHeight(), _mapProcedure.getWidth());
        _p2.setPosition(0, 0);
        Point e1(0, _mapProcedure.getWidth());
        Point e2(_mapProcedure.getHeight(), 0);
        _enemy.setEnemy(e1, e2);
    } else {
        _p1.setPosition(_mapProcedure.getHeight(), 0);
        _p2.setPosition(0, _mapProcedure.getWidth());
        Point e1(_mapProcedure.getHeight(), _mapProcedure.getWidth());
        Point e2(0, 0);
        _enemy.setEnemy(e1, e2);
    }
}

Graph indie_game::Monitor::checkBomb()
{
    Graph blast;
    Graph tmp;
    bool first = true;
    auto it = _bombAct.begin();

    for (size_t i = 0; i < _bombAct.size(); ++i) {
        if (_bombAct[i].getChrono()) {
            if (first) {
                tmp = controlBlast(_bombAct[i].blastField());
                blast.insert(blast.begin(), tmp.begin(), tmp.end());
                first = false;
            } else {
                tmp = controlBlast(_bombAct[i].blastField());
                blast.insert(blast.end(), tmp.begin(), tmp.end());
            }
            if (_bombAct[i].getPersoId() == PLAYER1)
                _p1.decActBombs();
            else
                _p2.decActBombs();
            _bombAct[i].setBlast();

            tmp = destroyBlock(_blastSave);
            blast.insert(blast.end(), tmp.begin(), tmp.end());
        }
    }

    for (size_t i = 0; i < _bombAct.size(); ++i, ++it)
        if (_bombAct[i].getBlast())
            _bombAct.erase(it);

    return blast;
}

Graph indie_game::Monitor::destroyBlock(Graph blast)
{
    Graph bonus;
    Point irTest;
    std::tuple<indie_game::boomberCase, Point, Point> newTuple;
    boomberCase tmp;
    _map[std::get<1>(blast[0]).getX()][std::get<1>(blast[0]).getY()].setTile(EMPTY);
    irTest.setXY(10 - std::get<1>(blast[0]).getY(), 10 - std::get<1>(blast[0]).getX());
    newTuple = std::make_tuple(EMPTY, irTest, irTest);
    bonus.push_back(newTuple);

    for (size_t i = 0; i < blast.size(); ++i) {
        if (_map[std::get<1>(blast[i]).getX()][std::get<1>(blast[i]).getY()].getTile() == BBLOCKS) {
            tmp = genBonus();
            _map[std::get<1>(blast[i]).getX()][std::get<1>(blast[i]).getY()].setTile(tmp);
            irTest.setXY(10 - std::get<1>(blast[i]).getY(), 10 - std::get<1>(blast[i]).getX());
            newTuple = std::make_tuple(tmp, irTest, irTest);
            bonus.push_back(newTuple);
        } if ((std::get<1>(blast[i]).getX() == _p1.getPosition().getX()) &&
                (std::get<1>(blast[i]).getY() == _p1.getPosition().getY())) {
            irTest.setXY(10 - _p1.getPosition().getY(), 10 - _p1.getPosition().getX());
            newTuple = std::make_tuple(P_DEAD, irTest, irTest);
            bonus.push_back(newTuple);
            _p1.setLife();
            _map[_p1.getPosition().getX()][_p1.getPosition().getY()].setTile(EMPTY);
        } if ((std::get<1>(blast[i]).getX() == _p2.getPosition().getX()) &&
                (std::get<1>(blast[i]).getY() == _p2.getPosition().getY())) {
            irTest.setXY(10 - _p2.getPosition().getY(), 10 - _p2.getPosition().getX());
            newTuple = std::make_tuple(P_DEAD, irTest, irTest);
            bonus.push_back(newTuple);
            _p2.setLife();
            _map[_p2.getPosition().getX()][_p2.getPosition().getY()].setTile(EMPTY);
        } if ((std::get<1>(blast[i]).getX() == _enemy.getPBot1().getX()) &&
                (std::get<1>(blast[i]).getY() == _enemy.getPBot1().getY())) {
            irTest.setXY(10 - _enemy.getPBot1().getY(), 10 - _enemy.getPBot1().getX());
            newTuple = std::make_tuple(P_DEAD, irTest, irTest);
            bonus.push_back(newTuple);
            _enemy.setL1(false);
            _map[_enemy.getPBot1().getX()][_enemy.getPBot1().getY()].setTile(EMPTY);
        } if ((std::get<1>(blast[i]).getX() == _enemy.getPBot2().getX()) &&
                (std::get<1>(blast[i]).getY() == _enemy.getPBot2().getY())) {
            irTest.setXY(10 - _enemy.getPBot2().getY(), 10 - _enemy.getPBot2().getX());
            newTuple = std::make_tuple(P_DEAD, irTest, irTest);
            bonus.push_back(newTuple);
            _enemy.setL2(false);
            _map[_enemy.getPBot2().getX()][_enemy.getPBot2().getY()].setTile(EMPTY);
        }
    }
    _blastSave.clear();
    
    return bonus;
}

indie_game::boomberCase indie_game::Monitor::genBonus()
{
    int myMove;
    srand (time(NULL));
    myMove = (rand() % (15 - 12 + 1)) + 12;
    
    switch (myMove) {
        case 12:
            return BONUS_BOMB;
            break;
        case 13:
            return BONUS_FIREUP;
            break;
        case 14:
            return BONUS_WALL_PASS;
            break;
        case 15:
            return BONUS_SPEED;
            break;
        default:
            return EMPTY;
            break;
    }
}

Graph indie_game::Monitor::moveP(Player &p, IndieStudioGraphicalEngine::input in)
{
    std::tuple<indie_game::boomberCase, Point, Point> tmp;
    Graph state;
    int i = p.getBonusSpeed();

    while (i > 0) {
        tmp = movePlayer(p, in);
        if (std::get<0>(tmp) != NOP)
            state.push_back(tmp);
        else
            break;
        --i;
    }

    return state;
}

Graph indie_game::Monitor::moveP1andP2(Player &p1, Player &p2, IndieStudioGraphicalEngine::GraphicalInput input)
{
    std::tuple<indie_game::boomberCase, Point, Point> tmp;
    Graph state;
    int i = p1.getBonusSpeed();
    int j = p2.getBonusSpeed();
    bool blockus1 = true;
    bool blockus2 = true;

    while ((i > 0 || j > 0) && (blockus1 || blockus2)) {
        if (blockus1 && i > 0) {
            tmp = movePlayer(p1, input.getP1());
            if (std::get<0>(tmp) != NOP)
                state.push_back(tmp);
            else
                blockus1 = false;
            --i;
        }

        if (blockus2 && j > 0) {
            tmp = movePlayer(p2, input.getP2());
            if (std::get<0>(tmp) != NOP)
                state.push_back(tmp);
            else
                blockus2 = false;
            --j;
        }
    }

    return state;
}

std::tuple<indie_game::boomberCase, Point, Point> indie_game::Monitor::setBomb(Player &p)
{
    Point irTest;
    Bomb newBomb(p.getPosition().getX(), p.getPosition().getY(), p.getID(), p.getBonusFireUp());
    _bombAct.push_back(newBomb);

    std::tuple<indie_game::boomberCase, Point, Point> newTuple;

    irTest.setXY(10 - p.getPosition().getY(), 10 - p.getPosition().getX());
    newTuple = std::make_tuple(BOMB, irTest, irTest);
    _map[p.getPosition().getX()][p.getPosition().getY()].setTile(BOMB);

    return newTuple;
}

bool indie_game::Monitor::checkMove(Player &p, IndieStudioGraphicalEngine::input in)
{
    if (p.getLife())
        switch (in) {
            case IndieStudioGraphicalEngine::UP:
                if ((p.getPosition().getX() - 1) >= 0)
                    return true;
                break;
            case IndieStudioGraphicalEngine::DOWN:
                if ((p.getPosition().getX() + 1) < _mapProcedure.getHeight()+1)
                    return true;
                break;
            case IndieStudioGraphicalEngine::RIGHT:
                if ((p.getPosition().getY() + 1) < _mapProcedure.getWidth()+1)
                    return true;
                break;
            case IndieStudioGraphicalEngine::LEFT:
                if ((p.getPosition().getY() - 1) >= 0)
                    return true;
                break;
            default:
                return false;
                break;
        }
    return false;
}

Graph indie_game::Monitor::makeChangeState(Player &p1, Player &p2, IndieStudioGraphicalEngine::GraphicalInput input)
{
    Graph state1;
    
    if (checkMove(p1, input.getP1()) && checkMove(p2, input.getP2()))
        state1 = moveP1andP2(p1, p2, input);
    else if (checkMove(p1, input.getP1()))
        state1 = moveP(p1, input.getP1());
    else if (checkMove(p2, input.getP2()))
        state1 = moveP(p2, input.getP2());
    if (input.getP1() == IndieStudioGraphicalEngine::PUTBOMB && p1.setBomb())
        state1.push_back(setBomb(p1));
    if (input.getP2() == IndieStudioGraphicalEngine::PUTBOMB && p2.setBomb())
        state1.push_back(setBomb(p2));

    return state1;
}

indie_game::boomberCase indie_game::Monitor::checkTile(Player &p, IndieStudioGraphicalEngine::input in)
{
    switch (in) {
        case IndieStudioGraphicalEngine::UP:
            return (_map[p.getPosition().getX() - 1][p.getPosition().getY()].getTile());
            break;
        case IndieStudioGraphicalEngine::DOWN:
            return (_map[p.getPosition().getX() + 1][p.getPosition().getY()].getTile());
            break;
        case IndieStudioGraphicalEngine::RIGHT:
            return (_map[p.getPosition().getX()][p.getPosition().getY() + 1].getTile());
            break;
        case IndieStudioGraphicalEngine::LEFT:
            return (_map[p.getPosition().getX()][p.getPosition().getY() - 1].getTile());
            break;
        default:
            return NOP;
            break;
    }
}

std::tuple<indie_game::boomberCase, Point, Point> indie_game::Monitor::movePlayer(Player &p, IndieStudioGraphicalEngine::input in)
{
    std::tuple<indie_game::boomberCase, Point, Point> empty;
    empty = std::make_tuple(NOP, Point(), Point());

    switch (checkTile(p, in)) {
        case E1:
            return enemyCas(p);
            break;
        case E2:
            return enemyCas(p);
            break;
        case WALL:
            return empty;
            break;
        case BONUS_BOMB:
            p.setBonusBomb();
            return moveCas(p, in, BONUS_BOMB);
            break;
        case BONUS_FIREUP:
            p.setBonusFireUp();
            return moveCas(p, in, BONUS_FIREUP);
            break;
        case BONUS_WALL_PASS:
            p.setBonusWallPass();
            return moveCas(p, in, BONUS_WALL_PASS);
            break;
        case BONUS_SPEED:
            p.setBonusSpeed();
            return moveCas(p, in, BONUS_SPEED);
            break;
        case BBLOCKS:
            if (p.getBonusWallPass())
                return moveCas(p, in, BBLOCKS);
            return empty;
            break;
        case EMPTY:
            return moveCas(p, in, EMPTY);
            break;
        default:
            return empty;
            break;
    }
}

indie_game::boomberCase indie_game::Monitor::imgToDisplay(boomberCase cas, Player &p)
{
    switch (cas) {
        case BONUS_BOMB:
            if (p.getID() == PLAYER1)
                return P1;
            return P2;
            //return P_GETBONUS_BOMB;
            break;
        case BONUS_FIREUP:
            if (p.getID() == PLAYER1)
                return P1;
            return P2;
            //return P_GETBONUS_FIREUP;
            break;
        case BONUS_WALL_PASS:
            if (p.getID() == PLAYER1)
                return P1;
            return P2;
            //return P_GETBONUS_WALL_PASS;
            break;
        case BONUS_SPEED:
            if (p.getID() == PLAYER1)
                return P1;
            return P2;
            //return P_GETBONUS_SPPED;
            break;
        case BBLOCKS:
            return P_MWP;
            break;
        case EMPTY:
            if (p.getBonusWallPass())
                return P_MWP;
            if (p.getID() == PLAYER1)
                return P1;
            return P2;
            break;
        default:
            return NOP;
            break;
    }
}

std::tuple<indie_game::boomberCase, Point, Point> indie_game::Monitor::moveCas(Player &p, IndieStudioGraphicalEngine::input &in,
boomberCase cas)
{
    Point lastPos;
    Point irTest;
    std::tuple<indie_game::boomberCase, Point, Point> newTuple;

    lastPos.setXY(10 - p.getPosition().getX(), 10 - p.getPosition().getY());

    if (_map[p.getPosition().getX()][p.getPosition().getY()].getTile() != BOMB &&
            _map[p.getPosition().getX()][p.getPosition().getY()].getTile() != BBLOCKS)
        _map[p.getPosition().getX()][p.getPosition().getY()].setTile(EMPTY);

    p.move(in);
    irTest.setXY(10 - p.getPosition().getY(), 10 - p.getPosition().getX());
    if (p.getID() == PLAYER1) {
        newTuple = std::make_tuple(imgToDisplay(cas, p), lastPos, irTest);
        if (_map[p.getPosition().getX()][p.getPosition().getY()].getTile() != BBLOCKS)
            _map[p.getPosition().getX()][p.getPosition().getY()].setTile(P1);
    }
    else {
        newTuple = std::make_tuple(imgToDisplay(cas, p), lastPos, irTest);
        if (_map[p.getPosition().getX()][p.getPosition().getY()].getTile() != BBLOCKS)
            _map[p.getPosition().getX()][p.getPosition().getY()].setTile(P2);
    }

    return newTuple;
}

std::tuple<indie_game::boomberCase, Point, Point> indie_game::Monitor::enemyCas(Player &p)
{
    std::tuple<indie_game::boomberCase, Point, Point> newTuple;
    Point irTest;

    irTest.setXY(10 - p.getPosition().getY(), 10 - p.getPosition().getX());
    newTuple = std::make_tuple(P_DEAD, irTest, irTest);
    _map[p.getPosition().getX()][p.getPosition().getY()].setTile(EMPTY);

    p.setLife();
    return newTuple;
}
