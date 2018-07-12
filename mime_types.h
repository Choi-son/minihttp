#pragma once
#include <string>
namespace mime_types //http1.1 mime ���Ͷ���
{
	struct mapping
	{
		const char* extension;
		const char* mime_type;
	} 
	mappings[] =
	{
		{ "gif","image/gif" },
		{ "htm","text/html" },
		{ "html","text/html" },
		{ "jpg","image/jpeg" },
		{ "png","image/png" }
	};//http 1.1 standard non css 
	std::string extension_to_type(const std::string& extension) //�򵥵�ͨ����չ���ƶ�mime����
	{
		for (mapping m:mappings)
		{
			if (m.extension==extension) //�ҵ���Ӧ����
			{
				return m.mime_type;
			}
		}
		return "text/plain"; //css will be regarded as plain text
	}
} 