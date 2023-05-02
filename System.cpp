#include "System.h"


System::System() 
{}

System::~System() 
{
    delete gameState;
    gameState = NULL;

    delete startMenu;
    startMenu = NULL;

    if (renderer != NULL) 
    {
        SDL_DestroyRenderer(renderer);
        renderer = NULL;
    }

    if (window != NULL) 
    {
        SDL_DestroyWindow(window);
        window = NULL;
    }
}

void System::initSDL() 
{
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) 
    {
        std::cout << "System : "  << SDL_GetError() << std::endl;
    }
    else 
    {
        // Tao window
        // Window cua ta se co the phong to va thu nho
        window = SDL_CreateWindow(WINDOW_TITTLE.c_str(), 
                                    SDL_WINDOWPOS_CENTERED, 
                                    SDL_WINDOWPOS_CENTERED, 
                                    SCREEN_WIDTH, 
                                    SCREEN_HEIGHT, 
                                    SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
        std::cout << "System : Window opened successfully!" << std::endl;
        Running = true;

        if (window == nullptr) 
        {
            std::cout << "System : " <<  SDL_GetError() << std::endl;
        }
        else 
        {
            // Tao render
            renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
            std::cout << "System : Renderer created successfully!" << std::endl;

            SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
            SDL_RenderSetLogicalSize(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);

            if (TTF_Init() < 0) std::cout << "System : " << TTF_GetError() << std::endl;
            else std::cout << "System : TTF Ready!" << std::endl;

            if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 8, 2048) < 0) std::cout << "System : " << Mix_GetError() << std::endl;
            else std::cout << "System : Audio Ready!" << std::endl;
            Mix_Volume(-1, MIX_MAX_VOLUME);

            // Mo file de doc du lieu
            std::ifstream input ("score.txt");
            std::string t;
            for (int i = 0; i < 10; i++)
            {
                std::getline(input,t);
                highScore.push_back(t);
            }
            input.close();
        }
    }
}

void System::quitSDL() 
{
    // Xoa thong so window
    SDL_DestroyRenderer(renderer);
    renderer = NULL;
    
    SDL_DestroyWindow(window);
    window = NULL;
    
    // Quit SDL
    Mix_Quit();
    TTF_Quit();
    atexit(SDL_Quit);
    
    std::cout << "System : Successfully exited!" << std::endl;
    // Viet vao file
    std::ofstream output ("score.txt");
    for (int i = 0; i < 10; i++) output << highScore[i] << std::endl;
    output.close();
    return;
}

void System::runGame() 
{
    // Tao Menu
    startMenu = new Menu(442, 200, startMenuButtonText.size(), 320, 30);
    startMenu->init(renderer, "Assets/Pacman Menu.png", startMenuButtonText);
    startMenu->changeRunStatus();

    // Tao Game Event
    SDL_Event e;
    runningMenu = true;
    bool startGame = false;
    gameState = new GameStateManager();

    while (Running) {

        while (SDL_PollEvent(&e) != 0) 
        {
            if (e.type == SDL_QUIT) Running = false;
            else 
            {
                if (runningMenu) 
                {
                    startMenu->handleEvent(e, renderer);
                    switch (startMenu->getStatus()) 
                    {
                        case Menu::PLAY_BUTTON_PRESSED:
                            runningMenu = false; 
                            break;
                        case Menu::EXIT_BUTTON_PRESSED:
                            Running = false; 
                            break;
                    }
                }
                else 
                {
                    gameState->handleEvent(e, renderer, runningMenu, highScore);
                    if (runningMenu) startMenu->reOpen();
                }
            }
        }
        if (!runningMenu) 
        {
            if (!startGame) 
            {
                gameState->newGame(renderer);
                startGame = true;
            }
            gameState->runGame(runningMenu);
            if (runningMenu) startMenu->reOpen(), startGame = false;
        }
        
        // Ve man hinh mau den
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        // Trong khi game chay ta se render update game lien tuc
        if (runningMenu) startMenu->render(renderer, highScore);
        else gameState->render(renderer, highScore);
        // Cap nhat cac render update len man hinh 
        SDL_RenderPresent(renderer);
    }
}
