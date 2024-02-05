#include "main.h"
#include "manager.h"
#include "renderer.h"
#include "input.h"
#include "timeManager.h"

//#include "polygon2D.h"
//#include "camera.h"
//#include "field.h"
//#include "player.h"
#include "scene.h"
#include "game.h"
#include "title.h"
#include "audio.h"


Scene* Manager::m_Scene;//static need call

void Manager::Init()
{
	Renderer::Init();
	Input::Init();
	Audio::InitMaster();
	/*m_Scene = new Title();
	m_Scene->Init();*/

	//SetScene<Title>();
	SetScene<Game>();
}


void Manager::Uninit()
{

	m_Scene->Uninit();
	delete m_Scene;

	Audio::UninitMaster();
	Renderer::Uninit();
	Input::Uninit();
}

void Manager::Update()
{
	Input::Update();
	m_Scene->Update();
}

void Manager::Draw()
{

	Renderer::Begin();

	m_Scene->Draw();

	Renderer::End();
}

Scene* Manager::GetScene()
{
	return m_Scene;
}

template <typename T>
void Manager::AddGameObject()
{
	T* object= m_Scene->AddGameObject<T>();
}
