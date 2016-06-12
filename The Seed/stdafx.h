#pragma once

#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <memory>
#include <fstream>
#include <sstream>
#include <chrono>
#include <map>
#include <functional>
#include <atomic>
#include <vector>

//SDL includes
#include <SDL.h>
#pragma comment (lib, "SDL2.lib")

//OpenGL includes
#include <GL/glew.h>
#include <gl/GL.h>

#pragma comment(lib, "opengl32.lib")	
#pragma comment(lib, "glew32.lib")

//GLM includes
#define GLM_FORCE_RADIANS
#include <glm.hpp>
#include <gtc/type_ptr.hpp>
#include <gtc/matrix_transform.hpp>

//FreeImage includes
#include <FreeImage.h>

#pragma comment (lib, "FreeImage.lib")

