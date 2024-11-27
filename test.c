#include <stdio.h>

void drawLine(int x1, int y1, int x2, int y2) {
    int dx = x2 - x1;
    int dy = y2 - y1;

    int x = x1;
    int y = y1;

    int p = 2 * dy - dx;
    int twoDy = 2 * dy;
    int twoDyDx = 2 * (dy - dx);

    printf("Plot: (%d, %d)\n", x, y);

    while (x < x2) {
        x++;
        if (p < 0) {
            p += twoDy;
        } else {
            y++;
            p += twoDyDx;
        }
        printf("Plot: (%d, %d)\n", x, y);
    }
}

int main() {
    int x1, y1, x2, y2;

    printf("Enter the starting point (x1, y1): ");
    scanf("%d %d", &x1, &y1);

    printf("Enter the ending point (x2, y2): ");
    scanf("%d %d", &x2, &y2);

    drawLine(x1, y1, x2, y2);

    return 0;
}