#define TINYGLTF_IMPLEMENTATION
#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "gltf_loader.h"

void load_model(const std::string& path)
{
	tinygltf::Model	   model;
	tinygltf::TinyGLTF loader;
	std::string		   err;
	std::string		   warn;

	bool ret = loader.LoadASCIIFromFile(&model, &err, &warn, path);

	if (!warn.empty())
	{
		NTT_LOG_WARN("GLTF Loader Warning: {}", warn);
	}

	if (!err.empty())
	{
		NTT_LOG_ERROR("GLTF Loader Error: {}", err);
	}

	if (!ret)
	{
		NTT_LOG_ERROR("Failed to load GLTF model: {}", path);
	}
	else
	{
		NTT_LOG_DEBUG("Successfully loaded GLTF model: {}", path);
	}
}