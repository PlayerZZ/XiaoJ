#include "MainWindow.h"
#include<QMovie>
#include <QUrl>
MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	QMovie *m_movie = new QMovie(this);
	m_movie->setFileName(":/images/Resources/YASINA.gif");
	ui.label->setMovie(m_movie);
	m_movie->start();
	connect(&netmanager, SIGNAL(finished(QNetworkReply*)), this, SLOT(serviceRequestFinished(QNetworkReply*)));

}

void MainWindow::sendText()
{
	//��ȸ跢������ ���費��Ҫ��֤ɶ��
	//https://www.google.com/search?q=xxx
	static QString request_format("http://www.google.com/search?q=%1");
	QString request_str = request_format.arg(ui.textEdit->toPlainText());
	//������ҪһЩ�����Ķ��� ��������ͷ��ʱ�����棬��������
	QUrl t_url(request_str);
	QNetworkRequest request;
	request.setUrl(t_url);
	request.setHeader(QNetworkRequest::ContentTypeHeader, "text/html; charset=UTF-8");
	netmanager.get(request);
} 

void MainWindow::serviceRequestFinished(QNetworkReply* reply)
{
	auto estr = reply->errorString();
	auto datas = reply->readAll();
	ui.textBrowser->setText(datas);
}
