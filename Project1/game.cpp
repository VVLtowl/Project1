#include "main.h"
#include "game.h"

#include "polygon2D.h"
#include "camera.h"
#include "field.h"
#include "player.h"
#include "bullet.h"
#include "enemy.h"
#include "explosion.h"
#include "sky.h"
#include "audio.h"
void Game::Init()
{
	{
		Enemy::Load();
		Bullet::Load();
		Explosion::Load();
		Sky::Load();
		Field::Load();

		AddGameObject<Camera>(layerType_camera);
		AddGameObject<Sky>(layerType_3DObject)->SetScale(D3DXVECTOR3(50, 50, 50));
		//????????????????????????????????????????????????????????



		FieldManager::InitFieldsHorizontal();
		AddGameObject<Player>(layerType_3DObject);

		AddGameObject<Enemy>(layerType_3DObject)->SetPosition(D3DXVECTOR3(-6, -0.5, 5));
		AddGameObject<Enemy>(layerType_3DObject)->SetPosition(D3DXVECTOR3(0, -0.5, 5));
		AddGameObject<Enemy>(layerType_3DObject)->SetPosition(D3DXVECTOR3(5, -0.5, 5));
		//AddGameObject<Explosion>(layerType_2DObject);


		//AddGameObject<Bullet>();
		AddGameObject<Polygon2D>(layerType_2DUI);


		//Audio* bgm = AddGameObject<Audio>(layerType_3DAudio);
		//bgm->Load("asset\\audio\\bgm.wav");
		//bgm->Play(true);
	}
}

void Game::Uninit()
{
	Enemy::Unload();
	Bullet::Unload();
	Sky::Unload();
	Explosion::Unload();
	Field::Unload();

	Scene::Uninit();//??????????????????????????????????????????????????????????????!!!!!!!!!!!!!!!!!!!!!!!!!
}

void Game::Update()
{
	Scene::Update();
}
