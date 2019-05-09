#pragma once

namespace dae
{
	class GameObject;

	class BaseComponent
	{
		friend class GameObject;
		// Required to let GameObject access the private and protected members of this class

	public:
		BaseComponent() = default;
		virtual ~BaseComponent() = default;

		BaseComponent(const BaseComponent& other) = delete;
		BaseComponent(BaseComponent&& other) noexcept = delete;
		BaseComponent& operator=(const BaseComponent& other) = delete;
		BaseComponent& operator=(BaseComponent&& other) noexcept = delete;

		GameObject* GetGameObject() const { return m_pGameObject; }

	protected:
		virtual void Initialize() = 0;
		virtual void Update() = 0;
		virtual void Draw() const = 0;

		GameObject* m_pGameObject = nullptr;
	};
}

