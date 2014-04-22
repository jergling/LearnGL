#include <GL/glfw3.h>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <OBJHandler.h>

GLuint loadIt;

static void error_callback(int error, const char* description)
{
    fputs(description, stderr);
}
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
}

static void loadModel(std::string filename){
    Mesh *cubey = OBJHandler::importObj(filename);

    for(int i = 0; i < cubey->faces.size(); i++){
            //glVertex3f(cubey->verts.at(i).at(0), cubey->verts.at(i).at(1), cubey->verts.at(i).at(3));
            //int i = 0;
            glBegin(GL_TRIANGLES);

            glColor3f(1.0f,0.0f,0.0f);
            glVertex3f(cubey->verts.at(cubey->faces[i][0]).at(0), cubey->verts.at(cubey->faces[i][0]).at(1), cubey->verts.at(cubey->faces[i][0]).at(2));
            //printf("%i, %i, %i", cubey->faces[i][0], cubey->faces[i][1], cubey->faces[i][2]);

            glColor3f(0.0f,1.0f,0.0f);glFrustum (-1.0, 1.0, -1.0, 1.0, 1.5, 20.0);
            glVertex3f(cubey->verts.at(cubey->faces[i][1]).at(0), cubey->verts.at(cubey->faces[i][1]).at(1), cubey->verts.at(cubey->faces[i][1]).at(2));

            glColor3f(0.0f,0.0f,1.0f);
            glVertex3f(cubey->verts.at(cubey->faces[i][2]).at(0), cubey->verts.at(cubey->faces[i][2]).at(1), cubey->verts.at(cubey->faces[i][2]).at(2));

            glEnd();
        }
}
int main(void)
{
    GLFWwindow* window;
    glfwSetErrorCallback(error_callback);
    srand(time(NULL));
    if (!glfwInit())
        exit(EXIT_FAILURE);
    window = glfwCreateWindow(640, 480, "GORPHICS!", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    glfwMakeContextCurrent(window);
    glfwSetKeyCallback(window, key_callback);

    Mesh *cubey = OBJHandler::importObj("c:\\Users\\the_e_000\\Documents\\Github\\LearnGL\\LearnGL\\bin\\Debug\\hipolymonkey.obj");
    //Mesh *cubey = OBJHandler::importObj("c:\\Users\\the_e_000\\Documents\\Github\\LearnGL\\LearnGL\\bin\\Debug\\shortparse.txt");

    loadIt = glGenLists (1);
    glNewList(loadIt, GL_COMPILE);
    loadModel("c:\\Users\\the_e_000\\Documents\\Github\\LearnGL\\LearnGL\\bin\\Debug\\hipolymonkey.obj");
    glEndList();

    glFrontFace(GL_CCW);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    glEnable(GL_DEPTH_TEST);
    glDepthMask(GL_TRUE);
    glDepthFunc(GL_LEQUAL);
    glDepthRange(0.0f, 1.0f);

    while (!glfwWindowShouldClose(window))
    {
        float ratio;
        int width, height;
        glfwGetFramebufferSize(window, &width, &height);
        ratio = width / (float) height;
        glViewport(0, 0, width, height);
        glClearDepth(1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glMatrixMode(GL_PROJECTION);

        glLoadIdentity();
        glOrtho(-ratio, ratio, -1.f, 1.f, 1.f, -1.f);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glFrustum (-1.0, 1.0, -1.0, 1.0, 1, 20.0);
        glTranslatef(0.0f, 0.0f, -2.5f);
        glRotatef((float) glfwGetTime() * 10.f, 0.f, 10.f, 1.f);

        glCallList(loadIt);
        glFlush();

/*
            for(int i = 0; i < cubey->faces.size(); i++){
                //glVertex3f(cubey->verts.at(i).at(0), cubey->verts.at(i).at(1), cubey->verts.at(i).at(3));
                //int i = 0;
                glBegin(GL_TRIANGLES);

                glColor3f(1.0f,0.0f,0.0f);
                glVertex3f(cubey->verts.at(cubey->faces[i][0]).at(0), cubey->verts.at(cubey->faces[i][0]).at(1), cubey->verts.at(cubey->faces[i][0]).at(2));
                //printf("%i, %i, %i", cubey->faces[i][0], cubey->faces[i][1], cubey->faces[i][2]);

                glColor3f(0.0f,1.0f,0.0f);glFrustum (-1.0, 1.0, -1.0, 1.0, 1.5, 20.0);
                glVertex3f(cubey->verts.at(cubey->faces[i][1]).at(0), cubey->verts.at(cubey->faces[i][1]).at(1), cubey->verts.at(cubey->faces[i][1]).at(2));

                glColor3f(0.0f,0.0f,1.0f);
                glVertex3f(cubey->verts.at(cubey->faces[i][2]).at(0), cubey->verts.at(cubey->faces[i][2]).at(1), cubey->verts.at(cubey->faces[i][2]).at(2));

                glEnd();
            }
*/


        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
}
