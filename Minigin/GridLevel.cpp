#include "MiniginPCH.h"
//#include "GridLevel.h"
//#include "Minigin.h"
//#include "GameObject.h"
//#include "TextureComponent.h"
//
//dae::GridLevel::GridLevel(const NodeVector nodes)
//	: m_Nodes(nodes)
//{
//}
//
//dae::GridLevel::~GridLevel()
//{
//	for (size_t i = 0; i < m_Nodes.size(); i++)
//	{
//	/*	for (size_t j = 0; j < m_Nodes[i].size(); j++)
//		{
//			delete &m_Nodes[i][j];
//		}*/
//		m_Nodes[i].clear();
//	}
//	m_Nodes.clear(); // TODO::Make sure this cleans everything
//}
//
//void dae::GridLevel::CreateGrid()
//{
//	for (size_t i = 0, nrRows = m_Nodes.size(); i < nrRows; i++)
//	{
//		for (size_t j = 0, nrCols = m_Nodes[i].size(); j < nrCols; j++)
//		{
//
//			// Calculate position for node
//			float xPos = i * (dae::g_ScreenWidth / nrCols);
//			float yPos = j * (dae::g_ScreenHeight / nrRows);
//
//			// Add components to gameobject
//			std::string resource;
//
//			if (m_Nodes[i][j].isDug)
//				resource = "Resources/DugGround.png";
//			else
//			{
//				switch (m_Nodes[i][j].layer)
//				{
//				case GroundLayer::FIRST_LAYER:
//					resource = "Resources/Layer1.png";
//					break;
//				case GroundLayer::SECOND_LAYER:
//					resource = "Resources/Layer2.png";
//					break;
//				case GroundLayer::THIRD_LAYER:
//					resource = "Resources/Layer3.png";
//					break;
//				case GroundLayer::FOURTH_LAYER:
//					resource = "Resources/Layer4.png";
//					break;
//				}
//			}
//			m_Nodes[i][j].gameObject->AddComponent(new dae::TextureComponent(resource));
//
//			// Translate gameobject to the correct position
//			m_Nodes[i][j].gameObject->SetPosition(xPos, yPos);
//		}
//	}
//}
