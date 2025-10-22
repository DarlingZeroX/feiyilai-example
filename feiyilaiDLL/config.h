#pragma once

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
#ifdef FYL_EXPORT
#define FYL_API __declspec(dllexport)
#else
#define FYL_API __declspec(dllimport)
#endif
#endif
