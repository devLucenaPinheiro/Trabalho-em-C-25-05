#include <GL/glut.h>

GLfloat angle = 0.0f;

// função de renderização
void renderScene() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(0.0f, 0.0f, 5.0f,  // posição da câmera
              0.0f, 0.0f, 0.0f,  // perspectiva
              0.0f, 1.0f, 0.0f); // posição "cabeça" da câmera

    glRotatef(angle, 0.0f, 1.0f, 0.0f); // rotação do cubo

    // desenhando o cubo
    glBegin(GL_QUADS);
    // face frontal
    glColor3f(1.0f, 0.0f, 0.0f); // vermelho
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);
    glVertex3f(1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, 1.0f);
    // face traseira
    glColor3f(0.0f, 1.0f, 0.0f); // verde
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);
    glVertex3f(1.0f, 1.0f, -1.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);
    // face superior
    glColor3f(0.0f, 0.0f, 1.0f); // azul
    glVertex3f(-1.0f, 1.0f, -1.0f);
    glVertex3f(-1.0f, 1.0f, 1.0f);
    glVertex3f(1.0f, 1.0f, 1.0f);
    glVertex3f(1.0f, 1.0f, -1.0f);
    // face inferior
    glColor3f(1.0f, 1.0f, 0.0f); // amarelo
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);
    // face direita
    glColor3f(1.0f, 0.0f, 1.0f); // magenta
    glVertex3f(1.0f, -1.0f, -1.0f);
    glVertex3f(1.0f, 1.0f, -1.0f);
    glVertex3f(1.0f, 1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);
    // face esquerda
    glColor3f(0.0f, 1.0f, 1.0f); // ciano
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);
    glEnd();

    angle += 0.5f; // incrementando o ângulo de rotação

    glutSwapBuffers();
}

// redimensionamento da janela
void reshapeWindow(int width, int height) {
    if (height == 0)
        height = 1;
    float aspectRatio = (float)width / height;

    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, aspectRatio, 0.1f, 100.0f);
    glMatrixMode(GL_MODELVIEW);
}

// função principal
int main(int argc, char** argv) {
    // inicialização do GLUT e criação da janela
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Janela cubo 3D RGB com OpenGL");

    // funções de callback
    glutDisplayFunc(renderScene);
    glutReshapeFunc(reshapeWindow);
    glutIdleFunc(renderScene);

    // habilitando o Z-buffer
    glEnable(GL_DEPTH_TEST);

    // loop principal do GLUT
    glutMainLoop();

    return 0;
}
