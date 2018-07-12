#include "httpsvr.h"
#include <utility>
httpsvr::httpsvr(const std::string& address, const std::string& port,const std::string& doc_root):io_svr(1),acceptor_(io_svr),connection_manager_(),request_handler_(doc_root)
{
	do_await_stop(); //�ر�֮ǰ������
	boost::asio::ip::tcp::resolver resolver(io_svr);  
	boost::asio::ip::tcp::endpoint endpoint =*resolver.resolve(address,port).begin(); //tcp�ս�㣨���յ㣩
	acceptor_.open(endpoint.protocol()); //�Զ�Ӧ����� (tcp)
	acceptor_.set_option(boost::asio::ip::tcp::acceptor::reuse_address(true)); //���õ�ַ����
	acceptor_.bind(endpoint); //��
	acceptor_.listen(); //�����˿�
	do_accept();//��ʼ��������
}
void httpsvr::run()
{
	io_svr.run();//����
}
void httpsvr::do_accept()
{
	acceptor_.async_accept(
		[this](boost::system::error_code ec, boost::asio::ip::tcp::socket socket) //lambda���ʽ
		{
				if (!acceptor_.is_open()) return; //���û������������
				if (!ec) //���û�д���
				{
					connection_manager_.start(std::make_shared<connection>(std::move(socket), connection_manager_, request_handler_));
				}
				do_accept();
		}
	);
}
void httpsvr::do_await_stop() //�رշ�����
{
	acceptor_.close(); //�رս�����
	connection_manager_.stop_all(); //ֹͣ��������
}
