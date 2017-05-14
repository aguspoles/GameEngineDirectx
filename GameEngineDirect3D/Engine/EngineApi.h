#pragma once
#ifdef DLL_EXPORT
#define ENGINE_API _declspec(dllexport)
#else 
#define ENGINE_API _declspec(dllimport)
#endif
