#include "Collision.h"
#include "ECS\ColliderComponent.h"
bool Collision::AABB(const SDL_Rect& recA, const SDL_Rect& recB)
{
	if (
	//recA.x + recA.w >= recB.x &&
	//recA.x + recB.w >= recA.x &&
	//recA.y + recA.h >= recB.y &&
	//recB.y + recB.h >= recA.y
		recA.x == recB.x + 15 && recA.y == recB.y+15 //condition for collision
	)
{
		return true;
}
return false;
}
//bool Collision::AABB(const ColliderComponent& colA, const ColliderComponent& colB)
//{
//	if (AABB(colA.collider, colB.collider))
//	{
//		std::cout << colA.tag << "hit: " << colB.tag << std::endl;
//		return true;
//	}
//	else
//		return false;
// }