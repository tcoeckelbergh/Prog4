#include "MiniginPCH.h"
#include <SDL.h>
#include <SDL_ttf.h>

#include "TextureComponent.h"
#include "ResourceManager.h"
#include "Renderer.h"
#include "GameObject.h"


dae::TextureComponent::TextureComponent(const std::string& fileName)
	: m_Texture(nullptr)
{
	m_Texture = ResourceManager::GetInstance().LoadTexture(fileName);
}


dae::TextureComponent::~TextureComponent()
{
}

void dae::TextureComponent::Initialize()
{
}

void dae::TextureComponent::Update()
{

}

void dae::TextureComponent::Draw() const
{
	const auto pos = GetGameObject()->GetPosition();
	const auto x = pos.GetPosition().x;
	const auto y = pos.GetPosition().y;
	Renderer::GetInstance().RenderTexture(*m_Texture, x, y);
}
