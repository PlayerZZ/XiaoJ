#include "MainWindow.h"
#include<QMovie>
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
	static QString request_format("https://www.google.com/search?q=%1");
	QString request_str = request_format.arg(ui.textEdit->toPlainText());
	//������ҪһЩ�����Ķ��� ��������ͷ��ʱ�����棬��������

} 

void MainWindow::serviceRequestFinished(QNetworkReply* reply)
{

}
