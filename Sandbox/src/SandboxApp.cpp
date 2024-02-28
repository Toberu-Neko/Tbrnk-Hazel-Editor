#include "tbrnkpch.h"
#include "TBRNK.h"

class ExampleLayer : public TBRNK::Layer 
{
	public:
		ExampleLayer() : Layer("Example") {

	}

		void OnUpdate() override {
		TBRNK_INFO("ExampleLayer::Update");
	}

		void OnEvent(TBRNK::Event& event) override {
		TBRNK_TRACE("{0}", event);
	}

};

class Sandbox : public TBRNK::Application 
{
public:
	Sandbox() {
		PushLayer(new ExampleLayer());
		PushOverlay(new TBRNK::ImGuiLayer());
	}

	~Sandbox() {

	}

};

TBRNK::Application* TBRNK::CreateApplication() {
	return new Sandbox();
}