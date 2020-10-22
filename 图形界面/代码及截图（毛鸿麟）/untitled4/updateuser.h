#ifndef UPDATEUSER_H
#define UPDATEUSER_H

#include "chooseform.h"

namespace Ui {
	class updateuser;
}

class updateuser : public QWidget
{
	Q_OBJECT

public:
	explicit updateuser(QWidget* parent = 0);
	~updateuser();
	void setchoice(int c) { choice = c; }
	int getchoice() { return choice; }
private slots:
	void on_updateid_clicked();
	void on_updatename_clicked();
	void on_updateschool_clicked();
	void on_updatemajor_clicked();
	void on_updateemail_clicked();
	void on_gotomainpage_clicked();
	void on_returnusermanager_clicked();
	void on_confirm1_clicked();
	void on_confirm2_clicked();
	void on_updatesure_clicked();
private:
	Ui::updateuser* ui;
	int choice; //选择，1-5分别为侧边从上到下5个按钮
};

#endif // UPDATEUSER_H
