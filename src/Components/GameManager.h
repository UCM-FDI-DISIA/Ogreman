#pragma once
#ifndef GAMEMANAGER_OGREMAN
#define GAMEMANAGER_OGREMAN
#include "Manager.h"
#include "SceneManager.h"
#include "NodeComponent.h"
#include "GridComponent.h"

//comentario aclaratorio: contamos con un game manager que llama al SceneManager que tiene una lista de Escenas
namespace Ogreman {
	class  GameManager:public VeryReal::Manager<GameManager>
	{
	private:
		std::vector<NodeComponent*> pathNodes;
		std::vector<NodeComponent*> patrolNodes;
		GridComponent* grid = nullptr;
	public:
		
		virtual ~GameManager();
		std::pair<bool,std::string> Start();
		void Win();
		void Lose();
		void Menu();
		void Play();
		void NextLevel();
		void Pause();
		void Controls();
		static bool Init() {
			GameManager* a = new GameManager();
			if (a != nullptr) {
				instance_pointer.reset(a);
				return true;
			}
			return false;

		}
		inline void RegisterGridComponent(GridComponent* g) {
			grid = g;
		}
		inline GridComponent* GetGris() { return grid; }
		inline std::vector<NodeComponent*> GetPathNode() {
			return pathNodes;
		}
		void RegisterPathNode(NodeComponent* node) {
			pathNodes.push_back(node);

		}
		inline std::vector<NodeComponent*> GetPatrolNode() {
			return patrolNodes;
		}
		void RegisterPatrolNode(NodeComponent* node) {
			patrolNodes.push_back(node);

		}

		static void GenerateTree(int n);
	};
}



#endif // GAMEMANAGER_OGREMAN

