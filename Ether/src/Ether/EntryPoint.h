#pragma once

#ifdef ET_PLATFORM_WINDOWS

extern Ether::Application* Ether::CreateApplication();

int main(int argc, char** argv) {

	Ether::Log::Init();
	ET_CORE_WARN("Initialized Log");
	ET_CLIENT_TRACE("Client Msg");

	auto app = Ether::CreateApplication();
	app->Run();
	delete app;
}

#endif // ET_PLATFORM_WINDOWS
