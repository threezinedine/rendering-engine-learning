#pragma once
#include <spdlog/spdlog.h>

#define NTT_LOG_TRACE(...) spdlog::get("console")->trace(__VA_ARGS__)
#define NTT_LOG_DEBUG(...) spdlog::get("console")->debug(__VA_ARGS__)
#define NTT_LOG_INFO(...)  spdlog::get("console")->info(__VA_ARGS__)
#define NTT_LOG_WARN(...)  spdlog::get("console")->warn(__VA_ARGS__)
#define NTT_LOG_ERROR(...) spdlog::get("console")->error(__VA_ARGS__)

#define NTT_LOG_SETUP()                                                                                                \
	do                                                                                                                 \
	{                                                                                                                  \
		spdlog::stdout_color_mt("console")->set_level(spdlog::level::debug);                                           \
		spdlog::get("console")->set_pattern("%^[%l] [%H:%M:%S] [%n] %v%$");                                            \
	} while (0)