#include<iostream>
#include<string>
#include<boost/asio.hpp>
#include <boost/program_options.hpp>
#include"httpsvr.h"
using namespace std;
namespace bpo = boost::program_options;
int main(int argc, char const* argv[])
{
	string address,port,docroot; //address ipaddress(ip��ַ) port �˿� docroot documentroot(�ĵ���ַ)
	bpo::options_description opt("all allowed options");//��ʾ��Ϣ
	bpo::variables_map vm;//������������
	opt.add_options()
		("address", bpo::value<string>(&address)->default_value("0.0.0.0"), "ip address")
		("port", bpo::value<string>(&port)->default_value("80"), "server port")
		("docroot", bpo::value<string>(&docroot)->default_value("."), "website root")
		("help", "get help information");//����Ҫ����ı�������
	try
	{
		bpo::store(parse_command_line(argc, argv, opt), vm); //�������
	}
	catch(...) //�쳣����
	{ 
		cerr << "Illegal argument" << endl;
		cerr << "use --help to see all allowed options" << endl;
		return 0;
	}
	bpo::notify(vm); //����
	if (vm.empty()) //�޲���
	{
		cerr << "Illegal argument" << endl;
		cerr << "use --help to see all allowed options" << endl;
		return 0;
	}
	if (vm.count("help")) //--help����
	{
		cout << opt << endl;
		return 0;
	}
	cout << "server info" << endl;
	cout << address << endl;
	cout << port << endl;
	cout << docroot << endl; //��������ǰ��Ϣ��ӡ
	httpsvr svr(address, port, docroot); //��ʼ��http������
	svr.run(); //http����������
	return 0;
}