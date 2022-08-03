#pragma once

#ifdef MATHLIBRARY_EXPORTS
#define MATHLIBRARY_API __declspec(dllexport)
#else
#define MATHLIBRARY_API __declspec(dllimport)
#endif

extern "C" MATHLIBRARY_API void inputArray(int* a, int& size);

extern "C" MATHLIBRARY_API void outputArray(int* a, int& size);
