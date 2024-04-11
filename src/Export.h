#pragma once
#ifdef OGREMAN_EXPORT
#define OGREMAN_API __declspec(dllexport)
#else
#define OGREMAN_API __declspec(dllimport)
#endif
#pragma once
