/*
** EPITECH PROJECT, 2019
** IndieStudio
** File description:
** Core.hpp
*/
#include "Monitor.hpp"
#include "Graphics.hpp"
#include "Output.hpp"
#include "ProceduralGeneration.hpp"

namespace IndieStudioCore {
    class Core {
    public:
        Core();
        ~Core();

        void runMainLoop();
    };
}