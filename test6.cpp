#include <stdio.h>
#include <dos.h>
#include <conio.h>

#define VGA_WIDTH 320
#define VGA_HEIGHT 200
#define VGA_MODE 0x13

void setVideoMode(unsigned char mode);

void plotPixel(int x, int y, unsigned char color);

void drawCircle(int centerX, int centerY, int radius, unsigned char color);

int main() {
    setVideoMode(VGA_MODE);

    int centerX = VGA_WIDTH / 2;
    int centerY = VGA_HEIGHT / 2;
    int blobRadius = 10;
    int numCircles = 5;

    // Different colors for circles
    unsigned char colors[] = {4, 5, 6, 9, 12};

    for (int i = 0; i < numCircles; ++i) {
        drawCircle(centerX, centerY, blobRadius + i * 20, colors[i]);
    }

    getch();
    setVideoMode(0x03);
    return 0;
}

void setVideoMode(unsigned char mode) {
    union REGS regs;
    regs.h.ah = 0x00;
    regs.h.al = mode;
    int86(0x10, &regs, &regs);
}

void plotPixel(int x, int y, unsigned char color) {
    unsigned char far *ptr = (unsigned char far *)0xA0000000;
    ptr[y * VGA_WIDTH + x] = color;
}

void drawCircle(int centerX, int centerY, int radius, unsigned char color) {
    int x = radius, y = 0;
    int radiusError = 1 - x;

    while (x >= y) {
        plotPixel(centerX + x, centerY + y, color);
        plotPixel(centerX - x, centerY + y, color);
        plotPixel(centerX + x, centerY - y, color);
        plotPixel(centerX - x, centerY - y, color);
        plotPixel(centerX + y, centerY + x, color);
        plotPixel(centerX - y, centerY + x, color);
        plotPixel(centerX + y, centerY - x, color);
        plotPixel(centerX - y, centerY - x, color);

        y++;

        if (radiusError < 0) {
            radiusError += 2 * y + 1;
        } else {
            x--;
            radiusError += 2 * (y - x + 1);
        }
    }
}
