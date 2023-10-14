#include "Engine.h"

#include "Renderer/Texture.h"

NamespaceScarlettBegin

void Engine::StartEngine()
{

	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		std::cout << "Failed to init SDL." << std::endl;
		m_state = EngineState::Failed;
		return;
	}

	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

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

	glClearColor(0.3f, 0.3f, 0.3f, 1.0f);

	m_state = EngineState::Running;
}

void Engine::Run()
{
	Shader shader("res/shaders/shader.vert", "res/shaders/shader.frag");
	shader.Bind();
	Renderer renderer;
	//renderer.Init();

	Texture texture("res/textures/circ.png");
	texture.Bind();
	shader.SetUniform1i("u_Texture", 0);

	renderer.AddSprite({ -1.0f, -1.0f, 1.0f, 1.0f }, { 0.0f, 0.0f, 1.0f, 1.0f }, texture.GetId(), 0.0f, Color(255, 0, 255, 255));
	renderer.AddSprite({ 0.0f, 0.0f, 1.0f, 1.0f }, { 0.0f, 0.0f, 1.0f, 1.0f }, texture.GetId(), 0.0f, Color(0, 0, 255, 255));
	renderer.AddSprite({ -1.0f, 0.0f, 1.0f, 1.0f }, { 0.0f, 0.0f, 1.0f, 1.0f }, texture.GetId(), 0.0f, Color(0, 255, 0, 255));
	renderer.AddSprite({ -0.8f, -0.8f, 1.6f, 1.6f }, { 0.0f, 0.0f, 1.0f, 1.0f }, texture.GetId(), 0.0f, Color(255, 255, 0, 255));
	

	Sprite sprite;
	//sprite.Init(&renderer, &shader, 0, 0, 1, 1);

	shader.SetUniform4f("u_Color", 1.0f, 1.0f, 1.0f, 1.0f);
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
		shader.SetUniform4f("u_Color", 1.0f, 1.0f, 1.0f, r);

		//renderer.Draw(va, ib, shader);
		//sprite.Draw();
		renderer.CreateBatches();
		renderer.Draw(shader);
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