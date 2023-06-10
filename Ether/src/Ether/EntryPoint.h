#pragma once

#ifdef ET_PLATFORM_WINDOWS

extern Ether::Application* Ether::CreateApplication();

int main(int argc, char** argv) {
	printf("Ether Engine");
	auto app = Ether::CreateApplication();
	app->Run();
	delete app;
}

#endif // ET_PLATFORM_WINDOWS
