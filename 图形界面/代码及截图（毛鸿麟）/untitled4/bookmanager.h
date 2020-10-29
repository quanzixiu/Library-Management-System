#ifndef BOOKMANAGER_H
#define BOOKMANAGER_H

#include"chooseform.h"
namespace Ui {
	class bookmanager;
}

class bookmanager : public QWidget
{
	Q_OBJECT

public:
	explicit bookmanager(QWidget* parent = 0);
	~bookmanager();
private slots:
	void on_gotomainpage_clicked();
	void on_exitlogin_clicked();
	void on_confirmsure_clicked();
	void on_addsure_clicked();
	void on_addbooks_clicked();
	void on_updatebooks_clicked();
	void on_deletebooks_clicked();
private:
	Ui::bookmanager* ui;
};

#endif // BOOKMANAGER_H
