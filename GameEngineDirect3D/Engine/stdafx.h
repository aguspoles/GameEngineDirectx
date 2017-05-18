// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
// Windows Header Files:
#include <windows.h>

#include <stdio.h> //para q me tome printf
#include <tchar.h> //para q me tome printf

#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include "EngineApi.h"

#include <d3d9.h>//Busca el header de directx en los path
#pragma comment (lib, "d3d9.lib") //Incluyo la lib a mi proyecto

#include <d3dx9.h>
#pragma comment (lib, "d3dx9.lib")

// TODO: reference additional headers your program requires here
