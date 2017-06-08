#pragma once
#ifdef DLL_EXPORT
#define ENGINE_API _declspec(dllimport)
#else 
#define ENGINE_API _declspec(dllexport)
#endif
