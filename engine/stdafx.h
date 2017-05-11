// stdafx.h: archivo de inclusi�n de los archivos de inclusi�n est�ndar del sistema
// o archivos de inclusi�n espec�ficos de un proyecto utilizados frecuentemente,
// pero rara vez modificados
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // Excluir material rara vez utilizado de encabezados de Windows
// Archivos de encabezado de Windows:
#include <windows.h>
#include <stdio.h> //para q me tome printf
#include <tchar.h> //para q me tome printf

#include <stdlib.h>
#include <malloc.h>
#include <memory.h>

#include <d3d9.h>//Busca el header de directx en los path
#pragma comment (lib, "d3d9.lib") //Incluyo la lib a mi proyecto

#include <d3dx9.h>
#pragma comment (lib, "d3dx9.lib")



// TODO: mencionar aqu� los encabezados adicionales que el programa necesita
