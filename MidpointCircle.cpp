#include <GL/glut.h>
#include <iostream>

// Function to draw circle using Mid-Point Circle Drawing Algorithm
void midPointCircleDraw(int x_centre, int y_centre, int r) {
    int x = r, y = 0;
    float P = 1 - r;

    // Begin drawing points
    glBegin(GL_POINTS);

    // Iterate until x is greater than y
    while (x >= y) {
        // Plot points in all octants
        glVertex2i(x + x_centre, y + y_centre);
        glVertex2i(-x + x_centre, y + y_centre);
        glVertex2i(x + x_centre, -y + y_centre);
        glVertex2i(-x + x_centre, -y + y_centre);
        glVertex2i(y + x_centre, x + y_centre);
        glVertex2i(-y + x_centre, x + y_centre);
        glVertex2i(y + x_centre, -x + y_centre);
        glVertex2i(-y + x_centre, -x + y_centre);

        // Update y if P is non-positive
        if (P <= 0)
            P += 2 * y++ + 1;
        else // Update both x and y if P is positive
            P += 2 * (y++ - x--) + 1;
    }

    // End drawing points
    glEnd();
}

// Function to initialize OpenGL
void init() {
    // Set clear color to black
    glClearColor(0.0, 0.0, 0.0, 1.0);

    // Set fill color to white
    glColor3f(1.0, 1.0, 1.0);

    // Set orthogonal 2D view
    gluOrtho2D(-320, 320, -240, 240);
}

// Function to display the circle
void display() {
    // Clear the color buffer
    glClear(GL_COLOR_BUFFER_BIT);

    // Ask user for radius input
    int radius;
    std::cout << "Enter the radius of the circle: ";
    std::cin >> radius;

    // Call the function to draw circle
    midPointCircleDraw(0, 0, radius);

    // Display result
    glFlush();
}

// Main function
int main(int argc, char** argv) {
    // Initialize GLUT
    glutInit(&argc, argv);

    // Set display mode
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    // Set window size and position
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(200, 200);

    // Create the window with title "Mid-Point Circle Drawing"
    glutCreateWindow("Mid-Point Circle Drawing");

    // Initialize drawing colors and background
    init();

    // Call the display function
    glutDisplayFunc(display);

    // Enter the GLUT event loop
    glutMainLoop();

    return 0;
}
