#include <iostream>
#include <cstdlib>
#include <ctime>
#include <graphics.h>

// Window dimensions
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

// Ball dimensions
#define BALL_RADIUS 30

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

int main() {
    // Seed random number generator
    srand(time(nullptr));

    // Initialize graphics
    initwindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Bouncing Ball");

    // Create ball
    Ball ball = createBall();

    // Main loop
    while (!kbhit()) {
        // Clear screen
        cleardevice();

        // Draw ball
        setcolor(WHITE);
        setfillstyle(SOLID_FILL, WHITE);
        circle(ball.x, ball.y, BALL_RADIUS);
        floodfill(ball.x, ball.y, WHITE);

        // Update ball position
        ball.x += ball.dx;
        ball.y += ball.dy;

        // Check for collisions with window boundaries
        if (ball.x - BALL_RADIUS <= 0 || ball.x + BALL_RADIUS >= SCREEN_WIDTH)
            ball.dx = -ball.dx;
        if (ball.y - BALL_RADIUS <= 0 || ball.y + BALL_RADIUS >= SCREEN_HEIGHT)
            ball.dy = -ball.dy;

        // Delay for a short time to control the animation speed
        delay(50);
    }

    // Close graphics
    closegraph();

    return 0;
}
