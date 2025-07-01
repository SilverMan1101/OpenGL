#include "TestTexture2D.h"

#include "Renderer.h"
#include <imgui/imgui.h>

#include "Shader.h"

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

namespace test
{

	TestTexture2D::TestTexture2D()
	{
		      float position1[] = 
      {
          -0.5f, -0.5f, 0.0f, 0.0f, //0
	  	 0.5f, -0.5f, 1.0f, 0.0f, //1
	  	 0.5f,  0.5f, 1.0f, 1.0f, //2
	  	-0.5f,  0.5f, 0.0f, 1.0f, //3
	  };

      unsigned int indices1[] = 
      {
          0, 1, 2, // First triangle
          2, 3, 0  // Second triangle
	  };

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

		unsigned int vao;
		GLCall(glGenVertexArrays(1, &vao));
		GLCall(glBindVertexArray(vao));

		GLCall(glEnable(GL_BLEND));
		GLCall(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA)); // Enable blending for transparency

		VertexArray va;
        VertexBuffer vb(position1, 4 * 4 * sizeof(float)); // 10 vertices, 7 floats each (3 for position, 4 for color)
		VertexBufferLayout layout;
		layout.Push<float>(2); // Position (x, y, z)   
		layout.Push<float>(2); // Color (r, g, b, a)
		va.AddBuffer(vb, layout);
        IndexBuffer ib(indices1, 6); // 9 indices

		//GLCall(glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 7, (const void*)0));
		//GLCall(glEnableVertexAttribArray(0));
		//GLCall(glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(float) * 7, (const void*)(3 * sizeof(float))));
		//GLCall(glEnableVertexAttribArray(1));
		glm::mat4 projection = glm::ortho(-0.5f, 0.5f, -0.375f, 0.375f, -1.0f, 1.0f);

		Shader shader("res/shaders/Basic.shader");
		shader.Bind();
		std::cout << "Vertex Shader: " << std::endl << shader.source.VertexSource << std::endl;
		std::cout << "Fragment Shader: " << std::endl << shader.source.FragmentSource << std::endl;
		shader.SetUniformMat4f("u_MVP", projection); // Set the projection matrix uniform


		Texture texture("res/textures/wall.jpg");
		texture.Bind(0); // Bind the texture
		shader.SetUniform1i("u_Texture", 0); // Set the texture uniform to use texture unit 0


		va.Unbind(); // Unbind the VAO
        shader.Unbind(); // Unbind the shader program
		vb.Unbind(); // Unbind the VBO
		ib.Unbind(); // Unbind the IBO

	}

	TestTexture2D::~TestTexture2D()
	{
	}

	void TestTexture2D::OnUpdate(float deltaTime)
	{
		// Update logic if needed
	}

	void TestTexture2D::OnRender()
	{
		GLCall(glClearColor(0.0f, 0.0f, 0.0f, 1.0f));
		GLCall(glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT));
	}

	void TestTexture2D::OnImGuiRender()
	{
	}
}