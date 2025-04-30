#include "jppch.h"
#include "ImGuiLayer.h"

#include "imgui.h"
#include "Platform/OpenGL/ImGuiOpenGLRenderer.h"
#include "GLFW/glfw3.h"

#include "Juniper/Application.h"

namespace Juniper {

	ImGuiLayer::ImGuiLayer()
		: Layer("ImGuiLayer")
	{
	}

	ImGuiLayer::~ImGuiLayer()
	{
	}

	void ImGuiLayer::OnAttach()
	{
		ImGui::CreateContext();
		ImGui::StyleColorsDark();

		
		ImGuiIO& io = ImGui::GetIO();
		io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;
		io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;

		// TEMPORARY: should eventually use Juniper key codes
		io.AddKeyEvent(ImGuiKey_Tab, ImGuiKey(GLFW_KEY_TAB));
		io.AddKeyEvent(ImGuiKey_LeftArrow, ImGuiKey(GLFW_KEY_LEFT));
		io.AddKeyEvent(ImGuiKey_RightArrow, ImGuiKey(GLFW_KEY_RIGHT));
		io.AddKeyEvent(ImGuiKey_UpArrow, ImGuiKey(GLFW_KEY_UP));
		io.AddKeyEvent(ImGuiKey_DownArrow, ImGuiKey(GLFW_KEY_DOWN));
		io.AddKeyEvent(ImGuiKey_PageUp, ImGuiKey(GLFW_KEY_PAGE_UP));
		io.AddKeyEvent(ImGuiKey_PageDown, ImGuiKey(GLFW_KEY_PAGE_DOWN));
		io.AddKeyEvent(ImGuiKey_Home, ImGuiKey(GLFW_KEY_HOME));
		io.AddKeyEvent(ImGuiKey_End, ImGuiKey(GLFW_KEY_END));
		io.AddKeyEvent(ImGuiKey_Insert , ImGuiKey(GLFW_KEY_INSERT));
		io.AddKeyEvent(ImGuiKey_Delete , ImGuiKey(GLFW_KEY_DELETE));
		io.AddKeyEvent(ImGuiKey_Backspace, ImGuiKey(GLFW_KEY_BACKSPACE));
		io.AddKeyEvent(ImGuiKey_Space, ImGuiKey(GLFW_KEY_SPACE));
		io.AddKeyEvent(ImGuiKey_Enter, ImGuiKey(GLFW_KEY_ENTER));
		io.AddKeyEvent(ImGuiKey_Escape, ImGuiKey(GLFW_KEY_ESCAPE));
		io.AddKeyEvent(ImGuiKey_A, ImGuiKey(GLFW_KEY_A));
		io.AddKeyEvent(ImGuiKey_C, ImGuiKey(GLFW_KEY_C));
		io.AddKeyEvent(ImGuiKey_V, ImGuiKey(GLFW_KEY_V));
		io.AddKeyEvent(ImGuiKey_X, ImGuiKey(GLFW_KEY_X));
		io.AddKeyEvent(ImGuiKey_Y, ImGuiKey(GLFW_KEY_Y));
		io.AddKeyEvent(ImGuiKey_Z, ImGuiKey(GLFW_KEY_Z));

		ImGui_ImplOpenGL3_Init("#version 410");

	}

	void ImGuiLayer::OnDetach()
	{
	}

	void ImGuiLayer::OnUpdate()
	{
		ImGuiIO& io = ImGui::GetIO();
		Application& app = Application::Get();
		io.DisplaySize = ImVec2(app.GetWindow().GetWidth(), app.GetWindow().GetHeight());

		float time = (float)glfwGetTime();
		io.DeltaTime = m_Time > 0.0f ? (time - m_Time) : (1.0f / 60.0f);
		m_Time = time;

		ImGui_ImplOpenGL3_NewFrame();
		ImGui::NewFrame();

		static bool show = true;
		ImGui::ShowDemoWindow(&show);

		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	}

	void ImGuiLayer::OnEvent(Event& event)
	{
	}

}