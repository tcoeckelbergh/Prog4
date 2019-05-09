#pragma once
#include "BaseComponent.h"
#include "Transform.h"

namespace dae
{
	class Texture2D;

	class TextureComponent final : public BaseComponent
	{
	public:
		explicit TextureComponent(const std::string& fileName);
		virtual ~TextureComponent();

		TextureComponent(const TextureComponent& other) = delete;
		TextureComponent(TextureComponent&& other) noexcept = delete;
		TextureComponent& operator=(const TextureComponent& other) = delete;
		TextureComponent& operator=(TextureComponent&& other) noexcept = delete;

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Draw() const override;

	private:
		bool m_NeedsUpdate;
		std::shared_ptr<Texture2D> m_Texture;
	};
}