#include "checkin.h"
#include "ui_checkin.h"
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <iostream>
#include <QTextCodec>
#include <QDate>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>


CheckIn::CheckIn(QWidget *parent)
	: QDialog(parent)
	, ui(new Ui::CheckInClass())
{
	ui->setupUi(this);
	populateComboBox();
	connect(ui->comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(updateComboBox1(int)));
	connect(ui->comboBox1, SIGNAL(currentIndexChanged(int)), this, SLOT(updatelineEdit_1(int)));
	connect(ui->comboBox1, SIGNAL(currentIndexChanged(int)), this, SLOT(updatelineEdit_2(int)));
	connect(ui->comboBox1, SIGNAL(currentIndexChanged(int)), this, SLOT(updatelineEdit_3(int)));
	connect(ui->comboBox1, SIGNAL(currentIndexChanged(int)), this, SLOT(updatelineEdit_4(int)));
	connect(ui->comboBox1, SIGNAL(currentIndexChanged(int)), this, SLOT(updatelineEdit_5(int)));
}

CheckIn::~CheckIn()
{
	delete ui;
	

}

void CheckIn::populateComboBox()
{
	QFile file("user_database.sql");
	if (!file.open(QIODevice::ReadOnly)) {
		QMessageBox::information(0, "Error", file.errorString());
		return;
	}

	QByteArray fileData = file.readAll();
	QTextCodec* codec = QTextCodec::codecForName("UTF-8");
	QString text = codec->toUnicode(fileData);
	QStringList fields = text.split("\n");
	file.close();

	if (fields.size() >= 2) {
		fields.removeFirst();
		fields.removeLast();
	}

	QDate currentDate = QDate::currentDate();

	for (int i = 0; i < fields.size(); i++) {
		QStringList data = fields.at(i).split(" ");
		QString checkinDate = data.at(3);
		QString checkoutDate = data.at(4);
		if (checkinDate == currentDate.toString("dd.MM.yyyy")) {
			ui->comboBox->addItem(data.at(0));
		}
	}
}


void CheckIn::updateComboBox1(int index)
{
	QFile file("user_database.sql");
	if (!file.open(QIODevice::ReadOnly)) {
		QMessageBox::information(0, "Error", file.errorString());
		return;
	}

	QByteArray fileData = file.readAll();
	QTextCodec* codec = QTextCodec::codecForName("UTF-8");
	QString text = codec->toUnicode(fileData);
	QStringList fields = text.split("\n");
	file.close();

	if (fields.size() >= 2) {
		fields.removeFirst();
		fields.removeLast();
	}

	QDate currentDate = QDate::currentDate();

	ui->comboBox1->clear();

	QString name = ui->comboBox->itemText(index).trimmed();

	for (int i = 0; i < fields.size(); i++) {
		QStringList data = fields.at(i).split(" ");
		QString checkinDate = data.at(3);
		QString checkoutDate = data.at(4);
		// If the name is the same as the name in the database and the check-in date is today, add the surname to the second comboBox
		if (checkinDate == currentDate.toString("dd.MM.yyyy") && data.at(0).trimmed() == name) { 
			ui->comboBox1->addItem(data.at(1));
		}
	}
}


void CheckIn::updatelineEdit_1(int index)
{
	QFile file("user_database.sql");
	if (!file.open(QIODevice::ReadOnly)) {
		QMessageBox::information(0, "Error", file.errorString());
		return;
	}

	QByteArray fileData = file.readAll();
	QTextCodec* codec = QTextCodec::codecForName("UTF-8");
	QString text = codec->toUnicode(fileData);
	QStringList fields = text.split("\n");
	file.close();

	if (fields.size() >= 2) {
		fields.removeFirst();
		fields.removeLast();
	}

	QDate currentDate = QDate::currentDate();

	QString name = ui->comboBox->itemText(ui->comboBox->currentIndex()).trimmed(); 
	QString surname = ui->comboBox1->itemText(index).trimmed(); 

	for (int i = 0; i < fields.size(); i++) {
		QStringList data = fields.at(i).split(" ");
		QString checkinDate = data.at(3);
		QString checkoutDate = data.at(4);
		if (checkinDate == currentDate.toString("dd.MM.yyyy") && data.at(0).trimmed() == name && data.at(1).trimmed() == surname) { 
					ui->lineEdit_1->setText(data.at(2));
				}
	}
}

void CheckIn::updatelineEdit_2(int index)
{
	QFile file("user_database.sql");
	if (!file.open(QIODevice::ReadOnly)) {
		QMessageBox::information(0, "Error", file.errorString());
		return;
	}

	QByteArray fileData = file.readAll();
	QTextCodec* codec = QTextCodec::codecForName("UTF-8");
	QString text = codec->toUnicode(fileData);
	QStringList fields = text.split("\n");
	file.close();

	if (fields.size() >= 2) {
		fields.removeFirst();
		fields.removeLast();
	}

	QDate currentDate = QDate::currentDate();

	QString name = ui->comboBox->itemText(ui->comboBox->currentIndex()).trimmed(); 
	QString surname = ui->comboBox1->itemText(index).trimmed();

	for (int i = 0; i < fields.size(); i++) {
		QStringList data = fields.at(i).split(" ");
		QString checkinDate = data.at(3);
		QString checkoutDate = data.at(4);
		if (checkinDate == currentDate.toString("dd.MM.yyyy") && data.at(0).trimmed() == name && data.at(1).trimmed() == surname) { 
					ui->lineEdit_2->setText(data.at(3));
				}
	}
}

void CheckIn::updatelineEdit_3(int index)
{
	QFile file("user_database.sql");
	if (!file.open(QIODevice::ReadOnly)) {
		QMessageBox::information(0, "Error", file.errorString());
		return;
	}

	QByteArray fileData = file.readAll();
	QTextCodec* codec = QTextCodec::codecForName("UTF-8");
	QString text = codec->toUnicode(fileData);
	QStringList fields = text.split("\n");
	file.close();

	if (fields.size() >= 2) {
		fields.removeFirst();
		fields.removeLast();
	}

	QDate currentDate = QDate::currentDate();

	QString name = ui->comboBox->itemText(ui->comboBox->currentIndex()).trimmed(); 
	QString surname = ui->comboBox1->itemText(index).trimmed();

	for (int i = 0; i < fields.size(); i++) {
		QStringList data = fields.at(i).split(" ");
		QString checkinDate = data.at(3);
		QString checkoutDate = data.at(4);
		if (checkinDate == currentDate.toString("dd.MM.yyyy") && data.at(0).trimmed() == name && data.at(1).trimmed() == surname) { 
							ui->lineEdit_3->setText(data.at(4));
						}
	}
}

void CheckIn::updatelineEdit_4(int index)
{
	QFile file("user_database.sql");
	if (!file.open(QIODevice::ReadOnly)) {
		QMessageBox::information(0, "Error", file.errorString());
		return;
	}

	QByteArray fileData = file.readAll();
	QTextCodec* codec = QTextCodec::codecForName("UTF-8");
	QString text = codec->toUnicode(fileData);
	QStringList fields = text.split("\n");
	file.close();

	if (fields.size() >= 2) {
		fields.removeFirst();
		fields.removeLast();
	}

	QDate currentDate = QDate::currentDate();

	QString name = ui->comboBox->itemText(ui->comboBox->currentIndex()).trimmed(); 
	QString surname = ui->comboBox1->itemText(index).trimmed(); 

	for (int i = 0; i < fields.size(); i++) {
		QStringList data = fields.at(i).split(" ");
		QString checkinDate = data.at(3);
		QString checkoutDate = data.at(4);
		if (checkinDate == currentDate.toString("dd.MM.yyyy") && data.at(0).trimmed() == name && data.at(1).trimmed() == surname) { 
									ui->lineEdit_4->setText(data.at(5));
								}
	}
}

void CheckIn::updatelineEdit_5(int index)
{
	QFile file("user_database.sql");
	if (!file.open(QIODevice::ReadOnly)) {
		QMessageBox::information(0, "Error", file.errorString());
		return;
	}

	QByteArray fileData = file.readAll();
	QTextCodec* codec = QTextCodec::codecForName("UTF-8");
	QString text = codec->toUnicode(fileData);
	QStringList fields = text.split("\n");
	file.close();

	if (fields.size() >= 2) {
		fields.removeFirst();
		fields.removeLast();
	}

	QDate currentDate = QDate::currentDate();

	QString name = ui->comboBox->itemText(ui->comboBox->currentIndex()).trimmed();
	QString surname = ui->comboBox1->itemText(index).trimmed();

	for (int i = 0; i < fields.size(); i++) {
		QStringList data = fields.at(i).split(" ");
		QString checkinDate = data.at(3);
		QString checkoutDate = data.at(4);
		if (checkinDate == currentDate.toString("dd.MM.yyyy") && data.at(0).trimmed() == name && data.at(1).trimmed() == surname) { 
													ui->lineEdit_5->setText(data.at(6));
												}
	}
}

void CheckIn::on_pushButton2_clicked() {
	MainWindow* mainwindow = new MainWindow();
	mainwindow->show();
	this->close();
}

void CheckIn::on_pushButton1_clicked() {
	QFile file("user_database.sql");
	if (!file.open(QIODevice::ReadOnly)) {
		QMessageBox::information(0, "Error", file.errorString());
		return;
	}

	QByteArray fileData = file.readAll();
	QTextCodec* codec = QTextCodec::codecForName("UTF-8");
	QString text = codec->toUnicode(fileData);
	QStringList fields = text.split("\n");
	file.close();

	if (fields.size() >= 2) {
		fields.removeFirst();
		fields.removeLast();
	}

	QDate currentDate = QDate::currentDate();
	QList<QStringList> matchingEntries;

	QString name = ui->comboBox->currentText().trimmed();
	QString surname = ui->comboBox1->currentText().trimmed(); 

	for (int i = 0; i < fields.size(); i++) {
		QStringList data = fields.at(i).split(" ");
		QString checkinDate = data.at(3);
		QString checkoutDate = data.at(4);
		if (checkinDate == currentDate.toString("dd.MM.yyyy") && data.at(0).trimmed() == name && data.at(1).trimmed() == surname) { 
			matchingEntries.append(data);
		}
	}

	QFile outFile("currentcheckin.txt");
	if (!outFile.open(QIODevice::WriteOnly | QIODevice::Append)) {
		QMessageBox::information(0, "Error", outFile.errorString());
		return;
	}

	QTextStream out(&outFile);
	for (int i = 0; i < matchingEntries.size(); i++) {
		QStringList data = matchingEntries.at(i);
		out << data.at(0) << " " << data.at(1) << " " << data.at(2) << " " << data.at(3) << " " << data.at(4) << " " << data.at(5) << " " << data.at(6) << "\n";
	}

	outFile.close();

	MainWindow* mainwindow = new MainWindow();
	mainwindow->show();
	this->close();
}




