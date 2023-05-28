#include "checkout.h"
#include "ui_checkout.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QTextCodec>
#include <QDate>
#include <QDebug>
#include "mainwindow.h"
#include "ui_mainwindow.h"

CheckOut::CheckOut(QWidget *parent)
	: QDialog(parent)
	, ui(new Ui::CheckOutClass())
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

CheckOut::~CheckOut()
{
	delete ui;
}


void CheckOut::populateComboBox()
{
	QFile file("currentcheckin.txt");
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
		fields.removeLast();
	}

	QDate currentDate = QDate::currentDate();

	for (int i = 0; i < fields.size(); i++) {
		QStringList data = fields[i].split(" ");
		if (data.size() >= 6) {
			QString checkin = data[3];
			QString yearFromCheckin = checkin.split(".")[2];
			QString monthFromCheckin = checkin.split(".")[1];
			QString dayFromCheckin = checkin.split(".")[0];
			QDate checkinDate = QDate(yearFromCheckin.toInt(), monthFromCheckin.toInt(), dayFromCheckin.toInt());
			if (checkinDate <= currentDate) {
				QString name = data[0];
				QString surname = data[1];
				ui->comboBox->addItem(name);
			}
		}
	}
}

void CheckOut::updateComboBox1(int index)
{
	ui->comboBox1->clear();
	QFile file("currentcheckin.txt");
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
		fields.removeLast();
	}

	QDate currentDate = QDate::currentDate();

	for (int i = 0; i < fields.size(); i++) {
		QStringList data = fields[i].split(" ");
		if (data.size() >= 6) {
			QString checkin = data[3];
			QString yearFromCheckin = checkin.split(".")[2];
			QString monthFromCheckin = checkin.split(".")[1];
			QString dayFromCheckin = checkin.split(".")[0];
			QDate checkinDate = QDate(yearFromCheckin.toInt(), monthFromCheckin.toInt(), dayFromCheckin.toInt());
			if (checkinDate <= currentDate) {
				QString name = data[0];
				QString surname = data[1];
				if (name == ui->comboBox->currentText()) {
					ui->comboBox1->addItem(surname);
				}
			}
		}
	}
}

void CheckOut::updatelineEdit_1(int index)
{
	QFile file("currentcheckin.txt");
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
		fields.removeLast();
	}

	QDate currentDate = QDate::currentDate();

	for (int i = 0; i < fields.size(); i++) {
		QStringList data = fields[i].split(" ");
		if (data.size() >= 6) {
			QString checkin = data[3];
			QString yearFromCheckin = checkin.split(".")[2];
			QString monthFromCheckin = checkin.split(".")[1];
			QString dayFromCheckin = checkin.split(".")[0];
			QDate checkinDate = QDate(yearFromCheckin.toInt(), monthFromCheckin.toInt(), dayFromCheckin.toInt());
			if (checkinDate <= currentDate) {
				QString name = data[0];
				QString surname = data[1];
				if (name == ui->comboBox->currentText() && surname == ui->comboBox1->currentText()) {
					ui->lineEdit_1->setText(data[2]);
				}
			}
		}
	}
}

void CheckOut::updatelineEdit_2(int index)
{
	QFile file("currentcheckin.txt");
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
		fields.removeLast();
	}

	QDate currentDate = QDate::currentDate();

	for (int i = 0; i < fields.size(); i++) {
		QStringList data = fields[i].split(" ");
		if (data.size() >= 6) {
			QString checkin = data[3];
			QString yearFromCheckin = checkin.split(".")[2];
			QString monthFromCheckin = checkin.split(".")[1];
			QString dayFromCheckin = checkin.split(".")[0];
			QDate checkinDate = QDate(yearFromCheckin.toInt(), monthFromCheckin.toInt(), dayFromCheckin.toInt());
			if (checkinDate <= currentDate) {
				QString name = data[0];
				QString surname = data[1];
				if (name == ui->comboBox->currentText() && surname == ui->comboBox1->currentText()) {
					ui->lineEdit_2->setText(data[3]);
				}
			}
		}
	}
}

void CheckOut::updatelineEdit_3(int index)
{
	QFile file("currentcheckin.txt");
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
		fields.removeLast();
	}

	QDate currentDate = QDate::currentDate();

	for (int i = 0; i < fields.size(); i++) {
		QStringList data = fields[i].split(" ");
		if (data.size() >= 6) {
			QString checkin = data[3];
			QString yearFromCheckin = checkin.split(".")[2];
			QString monthFromCheckin = checkin.split(".")[1];
			QString dayFromCheckin = checkin.split(".")[0];
			QDate checkinDate = QDate(yearFromCheckin.toInt(), monthFromCheckin.toInt(), dayFromCheckin.toInt());
			if (checkinDate <= currentDate) {
				QString name = data[0];
				QString surname = data[1];
				if (name == ui->comboBox->currentText() && surname == ui->comboBox1->currentText()) {
					ui->lineEdit_3->setText(data[4]);
				}
			}
		}
	}
}

void CheckOut::updatelineEdit_4(int index)
{
	QFile file("currentcheckin.txt");
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
		fields.removeLast();
	}

	QDate currentDate = QDate::currentDate();

	for (int i = 0; i < fields.size(); i++) {
		QStringList data = fields[i].split(" ");
		if (data.size() >= 6) {
			QString checkin = data[3];
			QString yearFromCheckin = checkin.split(".")[2];
			QString monthFromCheckin = checkin.split(".")[1];
			QString dayFromCheckin = checkin.split(".")[0];
			QDate checkinDate = QDate(yearFromCheckin.toInt(), monthFromCheckin.toInt(), dayFromCheckin.toInt());
			if (checkinDate <= currentDate) {
				QString name = data[0];
				QString surname = data[1];
				if (name == ui->comboBox->currentText() && surname == ui->comboBox1->currentText()) {
					ui->lineEdit_4->setText(data[5]);
				}
			}
		}
	}
}

void CheckOut::updatelineEdit_5(int index)
{
	QFile file("currentcheckin.txt");
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
		fields.removeLast();
	}

	QDate currentDate = QDate::currentDate();

	for (int i = 0; i < fields.size(); i++) {
		QStringList data = fields[i].split(" ");
		if (data.size() >= 6) {
			QString checkin = data[3];
			QString yearFromCheckin = checkin.split(".")[2];
			QString monthFromCheckin = checkin.split(".")[1];
			QString dayFromCheckin = checkin.split(".")[0];
			QDate checkinDate = QDate(yearFromCheckin.toInt(), monthFromCheckin.toInt(), dayFromCheckin.toInt());
			if (checkinDate <= currentDate) {
				QString name = data[0];
				QString surname = data[1];
				if (name == ui->comboBox->currentText() && surname == ui->comboBox1->currentText()) {
					ui->lineEdit_5->setText(data[6]);
				}
			}
		}
	}
}

void CheckOut::on_pushButton1_clicked() {
	QFile file("currentcheckin.txt");
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
		fields.removeLast();
	}

	QDate currentDate = QDate::currentDate();

	for (int i = 0; i < fields.size(); i++) {
		QStringList data = fields[i].split(" ");
		if (data.size() >= 6) {
			QString checkin = data[3];
			QString yearFromCheckin = checkin.split(".")[2];
			QString monthFromCheckin = checkin.split(".")[1];
			QString dayFromCheckin = checkin.split(".")[0];
			QDate checkinDate = QDate(yearFromCheckin.toInt(), monthFromCheckin.toInt(), dayFromCheckin.toInt());
			if (checkinDate <= currentDate) {
				QString name = data[0];
				QString surname = data[1];
				if (name == ui->comboBox->currentText() && surname == ui->comboBox1->currentText()) {
					QFile file("currentcheckout.txt");
					if (!file.open(QIODevice::WriteOnly | QIODevice::Append)) {
						QMessageBox::information(0, "Error", file.errorString());
						return;
					}

					QTextStream out(&file);
					out << name << " " << surname << " " << data[2] << " " << data[3] << " " << data[4] << " " << data[5] << " " << data[6] << "\n";
					file.close();
				} 
			} 
		}
	}
	MainWindow* mainwindow = new MainWindow();
	mainwindow->show();
	this->close();
}


void CheckOut::on_pushButton2_clicked()
{
	MainWindow* mainwindow = new MainWindow();
	mainwindow->show();
	this->close();
}


