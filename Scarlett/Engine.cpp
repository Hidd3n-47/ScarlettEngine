#include "Engine.h"

#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "VertexArray.h"
#include "VertexBufferLayout.h"
#include "Shader.h"
#include "Texture.h"

NamespaceScarlettBegin

void Engine::StartEngine()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		std::cout << "Failed to init SDL." << std::endl;
		m_state = EngineState::Failed;
		return;
	}

	m_window = SDL_CreateWindow("Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, m_width, m_height, SDL_WINDOW_OPENGL);
	if (!m_window)
	{
		m_state = EngineState::Failed;
	}

	SDL_GLContext glContext = SDL_GL_CreateContext(m_window);
	if (!glContext)
	{
		m_state = EngineState::Failed;
	}

	GLenum err = glewInit();
	if (err != GLEW_OK)
	{
		m_state = EngineState::Failed;
	}

	glCall(glEnable(GL_BLEND));
	glCall(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));

	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	glClearColor(0.3f, 0.3f, 0.3f, 1.0f);

	m_state = EngineState::Running;
}

void Engine::Run()
{
	/*float vertexData[] =
	{
		0.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f, 1.0f,
		1.0f, 1.0f, 1.0f, 1.0f,
		1.0f, 0.0f, 1.0f, 0.0f
	};

	unsigned int indexBuffer[] =
	{
		0, 1, 2,
		2, 3, 0
	};

	VertexArray va;
	VertexBuffer vb(vertexData, 4 * 4 * sizeof(float));

	VertexBufferLayout layout;
	layout.Push<float>(2);
	layout.Push<float>(2);
	va.AddBuffer(vb, layout);

	IndexBuffer ib(indexBuffer, 6);*/
	Renderer renderer;
	Shader shader("res/shaders/shader.vert", "res/shaders/shader.frag");
	shader.Bind();

	Sprite sprite;
	sprite.Init(&renderer, &shader, 0, 0, 1, 1);

	//float vertexData[8] =
	//{
	//	0, 0,
	//	0, 1,
	//	1, 1,
	//	1, 0
	//};
	//Vertex verts[4];

	//verts[0].position.x = 0;
	//verts[0].position.y = 0;

	//verts[1].position.x = 0;
	//verts[1].position.y = 1;

	//verts[2].position.x = 1;
	//verts[2].position.y = 1;

	//verts[3].position.x = 1;
	//verts[3].position.y = 0;

	//uint32 indexBuffer[6] =
	//{
	//	0, 1, 2,
	//	2, 3, 0
	//};

	//VertexArray va;
	//VertexBuffer* vb = nullptr;
	//vb = new VertexBuffer(vertexData, 8 * sizeof(float));

	//VertexBufferLayout layout;
	//layout.Push<float>(2); // Position
	////layout.Push<float>(2); // Position
	////layout.Push<ubyte>(4); // Color
	//va.AddBuffer(*vb, layout);

	//IndexBuffer* ib = nullptr;
	//ib = new IndexBuffer(indexBuffer, 6);
	//va.Unbind();
	//ib->Unbind();
	//vb->Unbind();


	//shader.SetUniform4f("u_Color", 0.8f, 0.3f, 0.8f, 1.0f);

	/*Texture texture("res/textures/circle.png");
	texture.Bind();
	shader.SetUniform1i("u_Texture", 0);*/
	
	/*va.Unbind();
	ib.Unbind();
	vb.Unbind();*/
	shader.Unbind();


	float r = 0.0f;
	float increment = 0.005f;

	while (m_state == EngineState::Running)
	{
		SDL_Event evnt;
		SDL_PollEvent(&evnt);

		switch (evnt.type)
		{
		case SDL_QUIT:
			m_state = EngineState::Close;
			break;
		default:
			break;
		}

		//Render();

		renderer.Clear();

		shader.Bind();
		//shader.SetUniform4f("u_Color", r, 0.3f, 0.8f, 1.0f);

		//renderer.Draw(va, ib, shader);
		sprite.Draw();
		//renderer.Draw(va, *ib, shader);

		if (r > 1.0f)
			increment = -0.005f;
		else if (r < 0.0f)
			increment = 0.005f;
		r += increment;


		SDL_GL_SwapWindow(m_window);
	}
	/*delete ib;
	delete vb;*/
}

void Engine::DestroyEngine()
{
	SDL_DestroyWindow(m_window);

	SDL_Quit();
}


void Engine::Render()
{
	

	

	
}

NamespaceScarlettEnd