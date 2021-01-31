#include "pong_pch.h"
#include "Window.h"

int main(int argc, char** argv)
{
    glutInit(&argc, argv);

    std::unique_ptr<Pong::Window> window = std::make_unique<Pong::Window>();
    window->OnUpdate();

    return 0;
}
