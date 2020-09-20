#include "Enemy.h"

Enemy::Enemy(DrawEngine* de, int x = 1, int y = 1, int lives = 3):Object(de, 3, x, y, lives, Route::DOWN){}

void Enemy::EnemyLogic(Storage& NewDraw)
{
	
}