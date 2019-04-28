#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_MainWindow.h"
#include <QNetworkAccessManager >
#include <QNetworkRequest>
#include <QNetworkReply>
class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = Q_NULLPTR);

private:
	Ui::MainWindowClass ui;
	QNetworkAccessManager netmanager;

public slots:
	void sendText();
	void serviceRequestFinished(QNetworkReply* reply);
};
