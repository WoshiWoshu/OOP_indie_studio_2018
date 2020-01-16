
// #include "Monitor.hpp"

// int moin()
// {
//     indie_game::Monitor mymonit;
//     std::shared_ptr<IndieStudioGraphicalEngine::GraphicalInput> test;
//     mymonit.create(test);
//     std::chrono::time_point<std::chrono::system_clock> _start;
//     std::chrono::time_point<std::chrono::system_clock> _end;
//     std::chrono::duration<double> _elapsedSeconds;
//     std::shared_ptr<IndieStudioGraphicalEngine::GraphicalInput> input = std::make_shared<IndieStudioGraphicalEngine::GraphicalInput>(IndieStudioGraphicalEngine::GraphicalInput());

//     input->setP1(IndieStudioGraphicalEngine::PUTBOMB);
//     //input.setP2(IndieStudioGraphicalEngine::RIGHT);
//     Graph gameState = mymonit.run(input);
//     //cr_assert(std::get<0>(gameState.front()) == indie_game::P1);

//     //input.setP1(IndieStudioGraphicalEngine::RIGHT);
//     //gameState = mymonit.run(input);
//     std::cout << std::get<0>(gameState.front()) << std::endl;
//     std::cout << "X : " << std::get<1>(gameState.front()).getX() << std::endl;
//     std::cout << "Y : " << std::get<1>(gameState.front()).getY() << std::endl;
    
//     input->setP1(IndieStudioGraphicalEngine::PUTBOMB);
//     gameState = mymonit.run(input);

//     _start = std::chrono::system_clock::now();
//     _end = std::chrono::system_clock::now();

//     while (_elapsedSeconds.count() < 3) {
//         _end = std::chrono::system_clock::now();
//         _elapsedSeconds = _end - _start;
//     }

//     //input.setP1(IndieStudioGraphicalEngine::RIGHT);
//     gameState = mymonit.run(input);

//     for (size_t i = 0; i < gameState.size(); ++i)
//         std::cout << std::get<0>(gameState[i]) << " X: "<< std::get<1>(gameState[i]).getX() << " Y: "<< std::get<1>(gameState[i]).getY() << std::endl;

//     /* input.setP1(IndieStudioGraphicalEngine::PUTBOMB);
//     gameState = mymonit.run(input);

//     for (size_t i = 0; i < gameState.size(); ++i)
//         std::cout << std::get<0>(gameState[i]) << std::endl;

//     input.setP1(IndieStudioGraphicalEngine::PUTBOMB);
//     gameState = mymonit.run(input);

//     for (size_t i = 0; i < gameState.size(); ++i)
//         std::cout << std::get<0>(gameState[i]) << std::endl; */
//     return 0;
// }
