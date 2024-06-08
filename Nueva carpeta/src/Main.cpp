#define SDL_MAIN_HANDLED "SDL_MAIN"

#include<cstdlib>
#include<E:\Proyects\OOP Proyects\Proyecto Ajedrez Cuantico\include\SDL.h>
#include<E:\Proyects\OOP Proyects\Proyecto Ajedrez Cuantico\include\SDL_events.h>
#include<E:\Proyects\OOP Proyects\Proyecto Ajedrez Cuantico\include\SDL_main.h>
#include<stdexcept>


using namespace std;

void handle_events(SDL_Event *event, bool &is_active){
    while(SDL_PollEvent(event)){
        if(event -> type == SDL_QUIT) is_active = false;
    }
}

void loop(){
    bool is_active{true};
    SDL_Event event{};

    while(is_active) handle_events(&event, is_active);
}

void clear(SDL_Window *window, SDL_Renderer *renderer){
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}

int main(){
    //Si falla SLD_init() avisar
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0) throw runtime_error{"ERROR => SDL_init()"};
    
    SDL_Window *window{SDL_CreateWindow("Test SDL2", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 720, 480, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL)};
    //Si falla SLD_CreateWindow avisar
    if(not window) throw runtime_error("ERROR => SDL_CreateWindow()");
    
    //Renderizamos
    SDL_Renderer *renderer{SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC)};
    
    //si falla el renderer avisar
    if(not renderer) throw runtime_error("ERROR => SDL_Renderer()");

    loop();
    clear(window, renderer);
}

    clear(window, renderer);
}
