#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>

#define WINW 1020/2
#define WINH 1261/2

bool isRunning=false;
SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;
SDL_Surface *surfaceScr = NULL;
SDL_Surface *surfaceImg = NULL;

bool initWindows();
void initVariables();
void processEvent();
void screenUpdate();
void screenDraw();
void destoryWindow();
void initImage();
void drawImage();

int main(){
    isRunning = initWindows();

    initVariables();
    initImage();

    while (isRunning){
        processEvent();
        screenUpdate();
        screenDraw();
    }

    destoryWindow();

    return 0;
}

bool initWindows(){
    if(SDL_Init(SDL_INIT_VIDEO) == false){
        SDL_Log("SDL init failure: %s\n", SDL_GetError());
        return false;
    }

    window = SDL_CreateWindow("nosebert", WINW, WINH, SDL_WINDOW_OPENGL);

    if(window == NULL){
        SDL_Log("SDL window creation failure: %s\n", SDL_GetError());
        return false;
    }

    renderer = SDL_CreateRenderer(window, NULL);

    if(renderer == NULL){
        SDL_Log("SDL renderer creation failure: %s\n", SDL_GetError());
        return false;
    }

    surfaceScr = SDL_GetWindowSurface(window);

    if(surfaceScr == NULL){
        SDL_Log("SDL Window Surface get failure: %s\n", SDL_GetError());
        return false;
    }

    return true;
}

void initVariables(){

}

void processEvent(){
    SDL_Event event;

    while(SDL_PollEvent(&event))
        switch(event.type) {
            case SDL_EVENT_QUIT:
                isRunning = false;
                break;
            case SDL_EVENT_KEY_DOWN:
                if(event.key.key == SDLK_ESCAPE){
                    isRunning = false;
                }
                break;
        
        }
}

void screenUpdate(){

}

void screenDraw(){

}

void initImage(){
    surfaceImg = IMG_Load("./nosebert.png");

    if(surfaceImg == NULL){
        SDL_Log("SDL Image Load failure: %s\n", SDL_GetError());
    }

    drawImage();
}

void drawImage(){
    SDL_Rect dstRect = {0, 0, WINW, WINH};
    SDL_BlitSurfaceScaled(surfaceImg, NULL, surfaceScr, &dstRect, SDL_SCALEMODE_LINEAR);
    SDL_UpdateWindowSurface(window);
}

void destoryWindow(){
    SDL_DestroySurface(surfaceImg);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

