#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unistd.h> // for usleep

// Window dimensions
#define SCREEN_WIDTH 80
#define SCREEN_HEIGHT 24

// Ball dimensions
#define BALL_RADIUS 3

// Ball structure
struct Ball {
    int x, y;           // position
    int dx, dy;         // velocity
};

// Function to create a new ball
Ball createBall() {
    Ball ball;
    ball.x = rand() % (SCREEN_WIDTH - 2 * BALL_RADIUS) + BALL_RADIUS;
    ball.y = rand() % (SCREEN_HEIGHT - 2 * BALL_RADIUS) + BALL_RADIUS;
    ball.dx = (rand() % 5) - 2;   // Random velocity in x direction (-2 to 2)
    ball.dy = (rand() % 5) - 2;   // Random velocity in y direction (-2 to 2)
    return ball;
}

// Function to clear screen
void clearScreen() {
    std::cout << "\033[2J\033[1;1H";
}

int main() {
    // Seed random number generator
    srand(time(nullptr));

    // Create ball
    Ball ball = createBall();

    // Main loop
    while (true) {
        // Update ball position
        ball.x += ball.dx;
        ball.y += ball.dy;

        // Check for collisions with window boundaries
        if (ball.x - BALL_RADIUS < 0 || ball.x + BALL_RADIUS >= SCREEN_WIDTH)
            ball.dx = -ball.dx;
        if (ball.y - BALL_RADIUS < 0 || ball.y + BALL_RADIUS >= SCREEN_HEIGHT)
            ball.dy = -ball.dy;

        // Clear screen
        clearScreen();

        // Draw ball
        for (int y = 0; y < SCREEN_HEIGHT; ++y) {
            for (int x = 0; x < SCREEN_WIDTH; ++x) {
                if ((x - ball.x) * (x - ball.x) + (y - ball.y) * (y - ball.y) <= BALL_RADIUS * BALL_RADIUS)
                    std::cout << "*";
                else
                    std::cout << " ";
            }
            std::cout << std::endl;
        }

        // Sleep for a short time to control the animation speed
        usleep(50000);
    }

    return 0;
}
