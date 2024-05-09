#include <SDL2/SDL.h>
#include <stdlib.h>
#include <time.h>

// Window dimensions
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

// Ball dimensions
#define BALL_RADIUS 20

// Ball structure
typedef struct {
    int x, y;           // position
    int dx, dy;         // velocity
} Ball;

// Function to create a new ball
Ball createBall() {
    Ball ball;
    ball.x = rand() % (SCREEN_WIDTH - 2 * BALL_RADIUS) + BALL_RADIUS;
    ball.y = rand() % (SCREEN_HEIGHT - 2 * BALL_RADIUS) + BALL_RADIUS;
    ball.dx = (rand() % 5) - 2;   // Random velocity in x direction (-2 to 2)
    ball.dy = (rand() % 5) - 2;   // Random velocity in y direction (-2 to 2)
    return ball;
}

int main() {
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        printf("SDL initialization failed: %s\n", SDL_GetError());
        return 1;
    }

    // Create a window
    SDL_Window *window = SDL_CreateWindow("Bouncing Ball",
                                          SDL_WINDOWPOS_UNDEFINED,
                                          SDL_WINDOWPOS_UNDEFINED,
                                          SCREEN_WIDTH, SCREEN_HEIGHT,
                                          SDL_WINDOW_SHOWN);
    if (window == NULL) {
        printf("Window creation failed: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    // Create a renderer
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL) {
        printf("Renderer creation failed: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    // Initialize random seed
    srand(time(NULL));

    // Create ball
    Ball ball = createBall();

    // Main loop
    int running = 1;
    while (running) {
        // Event handling
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT)
                running = 0;
        }

        ball.x += ball.dx;
        ball.y += ball.dy;

        if (ball.x - BALL_RADIUS < 0 || ball.x + BALL_RADIUS > SCREEN_WIDTH)
            ball.dx = -ball.dx;
        if (ball.y - BALL_RADIUS < 0 || ball.y + BALL_RADIUS > SCREEN_HEIGHT)
            ball.dy = -ball.dy;

        // Clear screen
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);

        // Draw ball
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_Rect ballRect = {ball.x - BALL_RADIUS, ball.y - BALL_RADIUS, 2 * BALL_RADIUS, 2 * BALL_RADIUS};
        SDL_RenderFillRect(renderer, &ballRect);

        // Update screen
        SDL_RenderPresent(renderer);

        // Delay
        SDL_Delay(30);
    }

    // Clean up
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
