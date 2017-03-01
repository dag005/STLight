#pragma once

#ifdef STLIGHT_EXPORTS
#define STLIGHT_API __declspec(dllexport)
#else
#define STLIGHT_API __declspec(dllimport)
#endif