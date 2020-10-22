#ifndef BOOKUPDATE_H
#define BOOKUPDATE_H

#include"chooseform.h"

namespace Ui {
	class bookupdate;
}

class bookupdate : public QWidget
{
	Q_OBJECT

public:
	explicit bookupdate(QWidget* parent = 0);
	~bookupdate();
	int getchoice() { return choice; }
	void setchoice(int c) { choice = c; }
private slots:
	void on_updateid_clicked();
	void on_updateisbn_clicked();
	void on_updatebookname_clicked();
	void on_updatewriter_clicked();
	void on_updatebooktype_clicked();
	void on_updateshelf_clicked();
	void on_updatestatus_clicked();
	void on_confirm1_clicked();
	void on_confirm2_clicked();
	void on_updatesure_clicked();
	void on_gotomainpage_clicked();
	void on_returnbookmanager_clicked();
private:
	Ui::bookupdate* ui;
	int choice; //1-7分对应侧边栏从上到下按钮
};

#endif // BOOKUPDATE_H
