#include "GameScene.h"

#include "FieldDrawer.h"

GameScene::GameScene(ISceneChanger *changer, SceneChangeDirection* scd) : BaseScene(changer, scd) {

	

	/*testobject = std::make_shared<Object3d>();
	testobject.reset(NY_Object3DManager::Get()->CreateModel_Box(50.f, 10.f, 10.f, testTex));

	testobject->SetAffineParam(RVector3(1, 1, 1), RVector3(0, 0, 0), RVector3(0, 0, 0));*/

	FieldDrawer::get()->SetGameMode();
	GameFrame = 0;
}

GameScene::~GameScene()
{
	/*if (testobject) {
		std::cout << "Object deleted" << endl;
	}*/
}

//初期化
void GameScene::Initialize() {
	gmgr.Init();
	timer = (float)MAX_TIMER;
	timerSize = { 64,64 };
	timerPos = { 1280 - 128,0 };
	timerFlag = false;
	timerColor = { 1,1,1,1 };
	timerTime = 0;
	gameSetFlag = false;
	gameSetSize = { 128,64 };
	spriteTimer.CreateAndSetDivisionUVOffsets(10, 10, 1, 64, 64, TexManager::LoadTexture("Resources/Score.png"));
	gameSet.Create(TexManager::LoadTexture("Resources/gameSet.png"));
}

void GameScene::Finalize()
{
}

//更新
void GameScene::Update() {
	GameFrame++;

	//時間経過
	timer -= 0.016f;

	if ((int)timer <= 5)
	{
		timerFlag = true;
	}

	if (timerFlag == false)
	{
		timerSize = { 64,64 };
		timerPos = { 1280 - 128,0 };
	}
	if ((timer <= 5.01 && timer >= 5) || (timer <= 4.01 && timer >= 4) || (timer <= 3.01 && timer >= 3) || (timer <= 2.01 && timer >= 2) || (timer <= 1.01 && timer >= 1))
	{
		timerTime = 0;
	}
	if (timerFlag == true)
	{
		if (timerTime == 0)
		{
			timerPos = { 640 - 128,360 - 128 };
			timerSize = { 256,256 };
			timerColor = { 1,1,1,0.7 };
		}
		else
		{
			timerColor.w -= 0.01f;
		}

		timerTime++;
	}

	if ((timer <= 0.01 && timer >= 0)) {
		gameSetFlag = true;
	}

	if (gameSetFlag == true)
	{
		gameSetSize.x += 1.5f;
		gameSetSize.y += 1.2f;
	}
	if ((int)timer <= -2)
	{
		mSceneChanger->ChangeScene(eScene_Result);
	}

	gmgr.Update(mSceneChangeDirection->GetDirectionStatus());
}

//描画
void GameScene::Draw() {
	//testobject->DrawObject();

	gmgr.Draw();
}

void GameScene::Draw2D()
{
	//testsp.Draw();

	gmgr.UIDraw();
	//制限時間の表示
	spriteTimer.DrawNumSprite(timerPos.x, timerPos.y, timerSize.x, timerSize.y, (int)timer, timerColor);
	spriteTimer.Draw();
	if (gameSetFlag == true)
	{
		gameSet.DrawExtendSprite(640 - gameSetSize.x, 360 - gameSetSize.y, 640 + gameSetSize.x, 360 + gameSetSize.y);
		gameSet.Draw();
	}
}

void GameScene::DrawImgui()
{
	//ImguiMgr::Get()->StartDrawImgui("time", 100, 100);

	//ImGui::Text("time : %d", 60 - (GameFrame / 60));

	//ImguiMgr::Get()->EndDrawImgui();



}

void GameScene::DrawParticle()
{
	gmgr.DrawParticle();
}
