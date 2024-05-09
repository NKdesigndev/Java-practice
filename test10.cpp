#include <iostream>
#include <cstdlib>
#include <ctime>
#include <thread> // for std::this_thread::sleep_for
#include <chrono> // for std::chrono::milliseconds

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

// Function to draw a circle at a given position
void drawCircle(int x, int y) {
    std::cout << "\033[" << y << ";" << x << "H"; // Move cursor to position
    std::cout << "*"; // Print circle character
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
        if (ball.x - BALL_RADIUS <= 0 || ball.x + BALL_RADIUS >= SCREEN_WIDTH)
            ball.dx = -ball.dx;
        if (ball.y - BALL_RADIUS <= 0 || ball.y + BALL_RADIUS >= SCREEN_HEIGHT)
            ball.dy = -ball.dy;

        // Clear screen
        clearScreen();

        // Draw ball
        drawCircle(ball.x, ball.y);

        // Sleep for a short time to control the animation speed
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }

    return 0;
}
