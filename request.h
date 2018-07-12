#pragma once
#include <string>
#include <vector>
#include "httpheader.h"
struct request //url 
{
	std::string method; //����Э��(post/get�ȣ�
	std::string uri; //(uniform resource indentifier)ͳһ��Դ��ʶ��
	int http_version_major; //http���汾�� 1/2 Ŀǰ����ȫΪ1
	int http_version_minor; //http���汾�� һ��ҲΪ1 ��http1.1
	std::vector<header> headers; //����ͷ����ʽ name=value
};