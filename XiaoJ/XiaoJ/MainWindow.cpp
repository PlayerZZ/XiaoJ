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
	//向谷歌发送请求 看需不需要验证啥的
	//https://www.google.com/search?q=xxx
	static QString request_format("https://www.google.com/search?q=%1");
	QString request_str = request_format.arg(ui.textEdit->toPlainText());
	//但是需要一些其他的东西 就是请求头暂时不会玩，先这样吧

} 

void MainWindow::serviceRequestFinished(QNetworkReply* reply)
{

}
