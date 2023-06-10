#pragma once

#include "Core.h"

namespace Ether {

	//Need this when we inherit in sandbox as this is a dll
	class ETHER_API Application
	{

	public:
		Application();
		virtual ~Application();

		void Run();

	};

	//To be defined in client
	Application* CreateApplication();
}

