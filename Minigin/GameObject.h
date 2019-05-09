#pragma once
#include <memory>
#include "Transform.h"
#include "Texture2D.h"
#include "SceneObject.h"

namespace dae
{
	class BaseComponent;
	class GameObject final : public SceneObject
	{
	public:
		void Update() override;
		void Render() const override;

		void SetPosition(float x, float y);
		Transform GetPosition() const;

		void AddComponent(BaseComponent* pComp);
		void RemoveComponent(BaseComponent* pComp);

		GameObject() = default;
		virtual ~GameObject();
		GameObject(const GameObject& other) = delete;
		GameObject(GameObject&& other) = delete;
		GameObject& operator=(const GameObject& other) = delete;
		GameObject& operator=(GameObject&& other) = delete;

		//Simplified version of Overlord Engine
		template <class T>
		T* GetComponent()
		{
			const type_info& ti = typeid(T);
			for (auto* component : m_pComponents)
			{
				if (component && typeid(*component) == ti)
					return static_cast<T*>(component);
			}
			return nullptr;
		}

	private:
		Transform mTransform;
		std::vector<BaseComponent*> m_pComponents;
	};
}
