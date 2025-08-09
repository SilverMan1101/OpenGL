#include "Header.h"


float v[] = {
    // positions in x y z
     0.5f,  0.5f,  0.5f,       1.0f,  0.0f, 0.0f, 1.0f,  // 0
     0.5f,  0.5f, -0.5f,       0.0f,  1.0f, 0.0f, 1.0f,  // 1
    -0.5f,  0.5f, -0.5f,       0.0f,  0.0f, 1.0f, 1.0f,  // 2
    -0.5f,  0.5f,  0.5f,       1.0f,  1.0f, 0.0f, 1.0f,  // 3
     0.5f, -0.5f,  0.5f,       0.0f,  1.0f, 1.0f, 1.0f,  // 4
     0.5f, -0.5f, -0.5f,       1.0f,  0.0f, 1.0f, 1.0f,  // 5
    -0.5f, -0.5f, -0.5f,       1.0f,  1.0f, 1.0f, 1.0f,  // 6
    -0.5f, -0.5f,  0.5f,       0.0f,  0.0f, 0.0f, 1.0f   // 7
};

unsigned int e[] = {
    0,1,2,
    2,3,0,

    0,4,3,
    3,7,4,

    0,1,4,
    1,4,5,

    4,5,6,
    4,7,6,

    1,5,2,
    5,2,6,

    3,2,6,
    3,6,7

};




float position[]
{
    -0.5f, -0.5f, 0.0f, 0.0f, //0
     0.5f, -0.5f, 1.0f, 0.0f, //1
     0.5f,  0.5f, 1.0f, 1.0f, //2
    -0.5f,  0.5f, 0.0f, 1.0f  //3
};
float positionOfSquare[]
{
    -1.0f, -1.0f, //0
     1.0f, -1.0f, //1
     1.0f,  1.0f, //2
    -1.0f,  1.0f //3
};

unsigned int indices[]
{
    0, 1, 2, // First triangle
    2, 3, 0  // Second triangle
};

glm::mat4 rotationMatrix = glm::mat4(1.0f);

void framebufferSizeChanged(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height); // Set the viewport to the new window size
    //render(window); 
}

void render(GLFWwindow* window)
{
    // Clear the screen
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);

    // Swap buffers to display the rendered content
    glfwSwapBuffers(window);
}


void testInputFunction(GLFWwindow* window, int key, int scancode, int action, int mods)
{

    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE); // Corrected to use GLFW's API
}

void processInput(GLFWwindow* window, float deltaTime)
{
    const float rotationSpeedDegreesPerSceond = 120.0f; // degrees per second
    const float rotationAnglePerFrame = rotationSpeedDegreesPerSceond * deltaTime;
    if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS) {
        rotationMatrix = glm::rotate(rotationMatrix, glm::radians(rotationAnglePerFrame), glm::vec3(1.0f, 0.0f, 0.0f));
    }
    if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS) {
        rotationMatrix = glm::rotate(rotationMatrix, glm::radians(-rotationAnglePerFrame), glm::vec3(0.0f, 1.0f, 0.0f));
    }
    if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS) {
        rotationMatrix = glm::rotate(rotationMatrix, glm::radians(-rotationAnglePerFrame), glm::vec3(0.0f, 0.0f, 1.0f));
    }
}

int main(void)
{
    /* Initialize the library */
    if (!glfwInit())
        return -1;

    const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
    const auto width = mode->width;
    const auto height = mode->height;

    // Initialize the variables
    //int width = 960, height = 720;

    /* Create a windowed mode window and its OpenGL context */
    GLFWwindow* window = glfwCreateWindow(960, 960, "Game", NULL(), NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    if (glewInit() != GLEW_OK)
        std::cout << "error" << std::endl;
    glfwWindowHint(GLFW_DEPTH_BITS, 24); // Request a 24-bit depth buffer


    // OpenGL configuration
    VertexArray vao;
    VertexBuffer vbo(v, 8 * 7 * sizeof(float)); // 10 vertices, 7 floats each (3 for position, 4 for color)
    VertexBufferLayout layout;
    layout.Push<float>(3); // Position (x, y, z)   
    layout.Push<float>(4); // Position (x, y, z)   
    vao.AddBuffer(vbo, layout);
    IndexBuffer ibo(e, 36); // 9 indices
    //glm::mat4 projection = glm::ortho(-2.37f, 2.37f, -1.0f, 1.0f, -1.0f, 1.0f);
    Shader shader("res/shaders/Basic.shader");
    shader.Bind();
    //shader.SetUniformMat4f("u_MVP", projection); // Set the projection matrix uniform
    //Texture texture("res/textures/wall.jpg");
    //texture.Bind(); // Bind the texture
    //shader.SetUniform1i("u_Texture", 0);
    vao.Unbind(); // Unbind the VAO
    shader.Unbind(); // Unbind the shader program
    vbo.Unbind(); // Unbind the VBO
    ibo.Unbind(); // Unbind the IBO
    Renderer renderer;


    glfwSetFramebufferSizeCallback(window, framebufferSizeChanged);

    glfwSetKeyCallback(window, testInputFunction);

    float lastFrameStartTime = 0.0f; // Variable to store the last frame time
    int i = 0;
    /* Loop until the user closes the window */
    glEnable(GL_DEPTH_TEST); // Enable depth testing for 3D rendering
    while (!glfwWindowShouldClose(window))
    {
        //Uniform update
        //float timeInSeconds = (float)glfwGetTime();
        //shader.SetUniform1f("u_time", (float)glfwGetTime());
        unsigned int locTime = glGetUniformLocation(shader.m_RendererID, "u_time");
        float timeInSeconds = (float)glfwGetTime();
        glUniform1f(locTime, timeInSeconds);
        glUniform2f(glGetUniformLocation(shader.m_RendererID, "u_resolution"), (float)width, (float)height);

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        float currentFrameStartTime = static_cast<float>(glfwGetTime()); // Get the current time in seconds
        float deltaTime;
        for (int i = 0; i < 1; i++) {
            if (i == 0)
                deltaTime = currentFrameStartTime - (currentFrameStartTime - 0.01f); // Calculate the time since the last frame
            if (i == 1)
                deltaTime = currentFrameStartTime - lastFrameStartTime; // Calculate the time since the last frame
        }
        lastFrameStartTime = currentFrameStartTime; // Update the last frame time


        processInput(window, deltaTime);

        /* Render here */
        //glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
        //glClear(GL_COLOR_BUFFER_BIT);
        renderer.Clear();
        shader.Bind();
        //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);  
        //shader.SetUniform1f("u_time", (float)glfwGetTime());
        auto location = glGetUniformLocation(shader.m_RendererID, "u_RM");
        glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(rotationMatrix));

        //Renderer Code
        renderer.Draw(vao, ibo, shader);



        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }
    glfwTerminate();
    return 0;
}