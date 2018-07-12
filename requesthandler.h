#pragma once
#include <string>
#include<boost/noncopyable.hpp>
struct reply;
struct request;
class requesthandler:public boost::noncopyable
{
	public:
		requesthandler(const std::string& doc_root) :doc_root_(doc_root) {}; //���캯��
		void handlerequest(const request& req, reply& rep);  //������
	private:
		std::string doc_root_; //�ĵ���ַ
		static bool url_decode(const std::string& in, std::string& out); //url���� 16����asciiת�ַ�
};