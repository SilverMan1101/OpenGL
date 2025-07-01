#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include<iostream>
#include <fstream>
#include <sstream>
#include <string>

#include"Renderer.h"
#include "VertexBuffer.h"
#include "VertexBufferLayout.h"
#include "IndexBuffer.h"
#include "VertexArray.h"
#include "Shader.h"
#include "texture.h"

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

#include "imgui/imgui.h"
#include "imgui/imgui_impl_glfw.h"
#include "imgui/imgui_impl_opengl3.h"

#include "tests/TestClearColor.h"


int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    //Initialize the variables 
    int width = 960, height = 720;
    //float timeInSeconds = (float)glfwGetTime();
    //double mouseX, mouseY;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(width, height, "Game", NULL, NULL);
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


    ImGui::CreateContext();
    ImGui::StyleColorsDark();
    //ImGuiIO& io = ImGui::GetIO();   
    //io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
    //io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 330 core");

    //bool show_demo_window = true;
    //bool show_another_window = false;
    //ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);


    // VERSION INFO
    //std::cout << "OpenGL Vendor: " << glGetString(GL_VENDOR) << std::endl;
    //std::cout << "OpenGL Renderer: " << glGetString(GL_RENDERER) << std::endl;
    //std::cout << "OpenGL Version: " << glGetString(GL_VERSION) << std::endl;
    //std::cout << "OpenGL Shading Language Version: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;
    {

        //      float position1[] = 
        //      {
        //          -0.5f, -0.5f, 0.0f, 0.0f, //0
              //	 0.5f, -0.5f, 1.0f, 0.0f, //1
              //	 0.5f,  0.5f, 1.0f, 1.0f, //2
              //	-0.5f,  0.5f, 0.0f, 1.0f, //3
              //};

        //      unsigned int indices1[] = 
        //      {
        //          0, 1, 2, // First triangle
        //          2, 3, 0  // Second triangle
              //};

        //      float position[]
        //      {
        //          //   x       y      z      r      g      b      w
        //              0.0f,   0.5f,  0.0f,  1.0f,  0.0f,  0.0f,  1.0f,  // Vertex 0 1  tr
        //              0.25f,  0.0f,  0.0f,  0.0f,  1.0f,  0.0f,  1.0f,  // Vertex 1 2  tl
        //              0.5f,  -0.5f,  0.0f,  0.0f,  1.0f,  0.0f,  1.0f,  // Vertex 2 3  bl
        //              0.0f,  -0.5f,  0.0f,  0.0f,  0.0f,  1.0f,  1.0f,  // Vertex 3 4  br
        //             -0.5f,  -0.5f,  0.0f,  0.0f,  0.0f,  1.0f,  1.0f,  // Vertex 4 5  tl
        //             -0.25f,  0.0f,  0.0f,  0.0f,  0.0f,  1.0f,  1.0f,  // Vertex 5 6  bl

        //              0.25f,  0.0f,  0.0f,  1.0f,  0.0f,  0.0f,  1.0f,  // Vertex 6 7(2)  tl
        //              0.0f,  -0.5f,  0.0f,  0.0f,  1.0f,  0.0f,  1.0f,  // Vertex 7 8(4)  br
        //              0.0f,  -0.5f,  0.0f,  0.0f,  1.0f,  0.0f,  1.0f,  // Vertex 8 9(4)  br
        //             -0.25f,  0.0f,  0.0f,  1.0f,  0.0f,  0.0f,  1.0f   // Vertex 9 10(6)  bl
        //      };

        //      unsigned int indices[]
        //      {
        //          0, 5, 1,
        //          6, 2, 3,
        //          7, 4, 9
        //      };

        //unsigned int vao;
        //GLCall(glGenVertexArrays(1, &vao));
        //GLCall(glBindVertexArray(vao));

        GLCall(glEnable(GL_BLEND));
        GLCall(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA)); // Enable blending for transparency

        //VertexArray va;
  //      VertexBuffer vb(position1, 4 * 4 * sizeof(float)); // 10 vertices, 7 floats each (3 for position, 4 for color)
        //VertexBufferLayout layout;
        //layout.Push<float>(2); // Position (x, y, z)   
        //layout.Push<float>(2); // Color (r, g, b, a)
        //va.AddBuffer(vb, layout);
  //      IndexBuffer ib(indices1, 6); // 9 indices

        //GLCall(glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 7, (const void*)0));
        //GLCall(glEnableVertexAttribArray(0));
        //GLCall(glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(float) * 7, (const void*)(3 * sizeof(float))));
        //GLCall(glEnableVertexAttribArray(1));
        //glm::mat4 proj = glm::perspective(glm::radians(45.0f), (float)width / (float)height, 0.1f, 100.0f);
        //glm::mat4 projection = glm::ortho(-0.5f, 0.5f, -0.375f, 0.375f, -1.0f, 1.0f);

        //Shader shader("res/shaders/Basic.shader");
        //shader.Bind();
        //std::cout << "Vertex Shader: " << std::endl << shader.source.VertexSource << std::endl;
        //std::cout << "Fragment Shader: " << std::endl << shader.source.FragmentSource << std::endl;
        //shader.SetUniformMat4f("u_MVPM", proj); // Set the projection matrix uniform
        //shader.SetUniformMat4f("u_MVP", projection); // Set the projection matrix uniform



        //Texture texture("res/textures/wall.jpg");
        //texture.Bind(0); // Bind the texture
        //shader.SetUniform1i("u_Texture", 0); // Set the texture uniform to use texture unit 0

        //ShaderProgramSource source = ParseShader("res/shaders/Basic.shader");
        //unsigned int shader = CreateShader(source.VertexSource, source.FragmentSource);
        //GLCall(glUseProgram(shader));

        //glUniform2f(glGetUniformLocation(shader, "u_resolution"), (float)width, (float)height);

        //va.Unbind(); // Unbind the VAO
        //shader.Unbind(); // Unbind the shader program
        //vb.Unbind(); // Unbind the VBO
        //ib.Unbind(); // Unbind the IBO


        Renderer renderer;

        test::Test* currentTest = nullptr;
        test::TestMenu* testMenu = new test::TestMenu(currentTest);
        currentTest = testMenu; // Set the current test to the test menu

        testMenu->RegisterTests<test::TestClearColor>("Clear Color Test");

        //test::TestClearColor test;


        /* Loop until the user closes the window */
        while (!glfwWindowShouldClose(window))
        {
            /* Render here */
            //GLCall(glClearColor(0.1f, 0.1f, 0.1f, 1.0f));
            //GLCall(glClear(GL_COLOR_BUFFER_BIT));
            renderer.Clear();
            //shader.Bind();
            //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

            //unsigned int locResolution = glGetUniformLocation(shader, "u_resolution");
            //glfwGetFramebufferSize(window, &width, &height);
            //glUniform2f(locResolution, (float)width, (float)height);
            //glUniform2f(glGetUniformLocation(shader, "u_resolution"), (float)width, (float)height);
            //unsigned int locTime = glGetUniformLocation(shader, "u_time");
            //float timeInSeconds = (float)glfwGetTime();
            //glUniform1f(locTime, timeInSeconds);

            //float timeInSeconds = (float)glfwGetTime();
            //shader.SetUniform1f("u_time", (float)glfwGetTime());


            //unsigned int locMouse = glGetUniformLocation(shader, "u_mouse");
            //double mouseX, mouseY;
            //glfwGetCursorPos(window, &mouseX, &mouseY);
            //mouseY = height - mouseY; // Flip Y axis
            //glUniform2f(locMouse, (float)mouseX, (float)mouseY);



            //test.OnUpdate(0.0f);
            //test.OnRender();

            // Start the ImGui frame
            ImGui_ImplOpenGL3_NewFrame();
            ImGui_ImplGlfw_NewFrame();
            ImGui::NewFrame();

            if (currentTest)
            {
                currentTest->OnUpdate(0.0f);
                currentTest->OnRender();
                ImGui::Begin("Test Menu");

                if (currentTest != testMenu && ImGui::Button("<-"))
                {
                    delete currentTest;
                    currentTest = testMenu;
                }
                currentTest->OnImGuiRender();
                ImGui::End();
            }

            //test.OnImGuiRender();

            //// Your ImGui code goes here
            //ImGui::Begin("Shader Controls");
            //// Example slider
            //static float R = 1.0f;
            //static float G = 1.0f;
            //static float B = 1.0f;
            //shader.SetUniform1f("u_r", R); // Example uniform for speed
            //shader.SetUniform1f("u_g", G); // Example uniform for speed
            //shader.SetUniform1f("u_b", B); // Example uniform for speed

            
            //ImGui::SliderFloat("G", &G, 0.0f, 1.0f);
            //ImGui::SliderFloat("B", &B, 0.0f, 1.0f);
            //ImGui::End();



            //glDrawArrays(GL_TRIANGLES, 0, 3);
            //glDrawArrays(GL_TRIANGLES, 3, 3);

            //GLCall(glBindVertexArray(vao)); // Bind the VAO before drawing
            //va.Bind(); // Bind the VAO
            //ib.Bind(); // Bind the IBO

            //glDrawElements(GL_TRIANGLES, 9, GL_UNSIGNED_INT, nullptr);
            //renderer.Draw(va, ib, shader);

            //if (show_demo_window)
            //    ImGui::ShowDemoWindow(&show_demo_window);

            //{
            //    static float f = 0.0f;
            //    static int counter = 0;

            //    ImGui::Begin("Hello, world!");                          // Create a window called "Hello, world!" and append into it.

            //    ImGui::Text("This is some useful text.");               // Display some text (you can use a format strings too)
            //    ImGui::Checkbox("Demo Window", &show_demo_window);      // Edit bools storing our window open/close state
            //    ImGui::Checkbox("Another Window", &show_another_window);

            //    ImGui::SliderFloat("float", &f, 0.0f, 1.0f);            // Edit 1 float using a slider from 0.0f to 1.0f
            //    ImGui::ColorEdit3("clear color", (float*)&clear_color); // Edit 3 floats representing a color

            //    if (ImGui::Button("Button"))                            // Buttons return true when clicked (most widgets return true when edited/activated)
            //        counter++;
            //    ImGui::SameLine();
            //    ImGui::Text("counter = %d", counter);

            //    ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / io.Framerate, io.Framerate);
            //    ImGui::End();
            //}

            //if (show_another_window)
            //{
            //    ImGui::Begin("Another Window", &show_another_window);   // Pass a pointer to our bool variable (the window will have a closing button that will clear the bool when clicked)
            //    ImGui::Text("Hello from another window!");
            //    if (ImGui::Button("Close Me"))
            //        show_another_window = false;
            //    ImGui::End();
            //}


            // Rendering
            ImGui::Render();
            //int display_w, display_h;
            //glfwGetFramebufferSize(window, &display_w, &display_h);
            //glViewport(0, 0, display_w, display_h);
            //glClearColor(clear_color.x * clear_color.w, clear_color.y * clear_color.w, clear_color.z * clear_color.w, clear_color.w);
            //glClear(GL_COLOR_BUFFER_BIT);
            ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());


            /* Swap front and back buffers */
            glfwSwapBuffers(window);

            /* Poll for and process events */
            glfwPollEvents();
        }
        delete currentTest; // Clean up the current test
        if (currentTest != testMenu) // If the current test is not the test menu, delete it
        {
            delete testMenu;
        }
    }

    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();



    glfwTerminate();
    return 0;
}