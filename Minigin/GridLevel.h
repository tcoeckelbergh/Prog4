//#pragma once
//#include <vector>
//
//namespace dae
//{
//	class GameObject;
//
//	enum GroundLayer
//	{
//		FIRST_LAYER = 0,
//		SECOND_LAYER = 1,
//		THIRD_LAYER = 2,
//		FOURTH_LAYER = 3
//	};
//
//	struct GridNode
//	{
//		GameObject* gameObject;
//		GroundLayer layer;
//		bool isDug;
//	};
//
//	class GridLevel
//	{
//		using NodeVector = std::vector<std::vector<GridNode&>&>&;
//
//	public:
//		GridLevel(const NodeVector nodes);
//		~GridLevel();
//
//		NodeVector GetGridNodes() const
//		{
//			return m_Nodes;
//		}
//
//		const GridNode& GetGridNode(int rowIdx, int colIdx) const
//		{
//			return m_Nodes[rowIdx][colIdx];
//		}
//
//	private:
//		void CreateGrid();
//
//		NodeVector m_Nodes;
//	};
//
//}
//
