#include "Scene.h"

Scene::Scene() {}

void Scene::Init(){
	inputHandler_ = new InputHandler();

	inputHandler_->AssignMoveLeft2PressKeyA();
	inputHandler_->AssignMoveRight2PressKeyD();

	player_ = new Player();
	player_->Init();
}

void Scene::Update(){
	iCommand_ = inputHandler_->HandleInput();

	if (iCommand_) {
		iCommand_->Exec(*player_);
	}

	player_->Update();
}

void Scene::Draw(){
	player_->Draw();
}
