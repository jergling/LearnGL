#include <GL/glew.h>
#include <GL/glfw3.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <OBJHandler.h>
#include <VectorMath.h>
#include <Ribbon.h>
#include <RibbonParticle.h>
#include <cmath>
#include <MeshGL.h>
#include <ShaderHandler.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform.hpp>


static void error_callback(int error, const char* description)
{
    fputs(description, stderr);
}
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
}

int main(void)
{
    GLFWwindow* window;
    glfwSetErrorCallback(error_callback);
    srand(time(NULL));

    //RibbonParticle ribby(0.0f, 0.0f, 0.0f, 128);
    //ribby.move(0.0f,-1.0f,0.0f,true);

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

    glewExperimental = GL_TRUE;
    glewInit();

    Mesh *cubey = OBJHandler::importObj("..\\..\\media\\models\\hipolymonkey.obj");

    //Load Vertex Array Object
    MeshGL cubeyGL(cubey);
    printf("\nMESHGL LOADED\n");
    printf("Facearray from main's view: %x\n", cubeyGL.faceArray);
    printf("VertArray length: %i\n", cubeyGL.vertLength);
    printf("FaceArray length: %i\n", cubeyGL.faceLength);

    cubeyGL.genColorArray();
    //printf("Random Color array generated\n");

    //Weird code that needs to happen at setup. Not sure why.
/* Don't need to make Vertex Array to use VBOs... not sure what idiot told me to do this.
    printf("Making ID uint\n");
    GLuint VertexArrayID;
    printf("Generating Vertex Array\n");
    glGenVertexArrays(1, &VertexArrayID);
    printf("Binding Vertex Array\n");
    glBindVertexArray(VertexArrayID);
*/
/*
    glEnableClientState(GL_VERTEX_ARRAY);
    printf("glEnableClientState Successful\n");
    glVertexPointer(3, GL_FLOAT, 0, cubeyGL.vertArray);
    printf("glVertexPointer Setup complete\n");
    printf("faceArray pointer: %x\n", cubeyGL.faceArray);
*/

    //Load Shaders
    ShaderHandler shandler;
    //printf("Loading shaders...\n");
    GLuint shaderProgramID = shandler.loadShaders("..\\..\\media\\shaders\\VertexShader.vs", "..\\..\\media\\shaders\\FragmentShader.fs");

    //printf("Making vertex buffer...\n");
    GLuint modelVertBuffer;
    glGenBuffersARB(1, &modelVertBuffer);
    glBindBufferARB(GL_ARRAY_BUFFER_ARB, modelVertBuffer);
    glBufferDataARB(GL_ARRAY_BUFFER_ARB, cubeyGL.vertLength * sizeof(GLfloat), cubeyGL.vertArray, GL_STATIC_DRAW_ARB);
    //printf("    Done\n");

    //printf("Making index buffer...\n");
    GLuint modelIndexBuffer;
    glGenBuffersARB(1, &modelIndexBuffer);
    glBindBufferARB(GL_ELEMENT_ARRAY_BUFFER_ARB, modelIndexBuffer);
    glBufferDataARB(GL_ELEMENT_ARRAY_BUFFER_ARB, cubeyGL.faceLength * sizeof(GLuint), cubeyGL.faceArray, GL_STATIC_DRAW_ARB);
    //printf("    Done\n");

//DISABLE WHEN USING WIREFRAME
    glFrontFace(GL_CCW);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    glEnable(GL_DEPTH_TEST);
    glDepthMask(GL_TRUE);
    glDepthFunc(GL_LEQUAL);
    glDepthRange(0.0f, 1.0f);

    glPolygonMode(GL_FRONT, GL_POLYGON);

    while (!glfwWindowShouldClose(window))
    {
        float ratio;
        int width, height;
        glfwGetFramebufferSize(window, &width, &height);
        ratio = width / (float) height;
        glViewport(0, 0, width, height);
        glClearDepth(1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

//  Replaced by glm+shader
/*
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(-ratio, ratio, -1.f, 1.f, 1.f, -1.f);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glFrustum (-1.0, 1.0, -1.0, 1.0, 1, 20.0);
        glTranslatef(0.0f, 0.0f, -3.5f);
        glRotatef((float) glfwGetTime() * 10.f, 0.f, 10.f, 0.f);
*/

        //GLM matrix/shader stuff
        glm::mat4 Projection = glm::perspective(60.0f, 640.f/480.f, 0.1f, 100.0f);
        glm::mat4 View = glm::lookAt(glm::vec3(4,3,3), glm::vec3(0,0,0), glm::vec3(0,1,0));
        glm::mat4 Model = glm::mat4(1.0f);
        glm::mat4 MVP = Projection*View*Model;

        GLuint MatrixID = glGetUniformLocation(shaderProgramID, "MVP");
        glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);


        //printf("Setting shader program\n");
        glUseProgram(shaderProgramID);

        //printf("Binding Buffers\n");
        glBindBufferARB(GL_ARRAY_BUFFER_ARB, modelVertBuffer);
        glBindBufferARB(GL_ELEMENT_ARRAY_BUFFER_ARB, modelIndexBuffer);

        //printf("Enabling GL_VERTEX_ARRAY\n");
        glEnableClientState(GL_VERTEX_ARRAY);
        glVertexPointer(3, GL_FLOAT, 0, 0);

        //printf("Drawing\n");
        glDrawElements(GL_TRIANGLES, cubeyGL.faceLength, GL_UNSIGNED_INT, 0);

        //printf("Disabling GL_VERTEX_ARRAY\n");
        glDisableClientState(GL_VERTEX_ARRAY);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    //May put glDisableClientState info here, not sure//
    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
}
