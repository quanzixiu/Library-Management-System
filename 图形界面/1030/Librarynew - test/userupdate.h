#ifndef USERUPDATE_H
#define USERUPDATE_H

#include"chooseform.h"
#include"userdocking.h"
#include"supervisor.h"

namespace Ui {
	class UserUpdate;
}

class UserUpdate : public QWidget
{
	Q_OBJECT

public:
	explicit UserUpdate(QWidget* parent = 0);
	~UserUpdate();
	void setchoice(int c) { choice = c; }
	int getchoice() { return choice; }
    bool getexist() { return exist; }
    bool setexist(bool e) { exist = e; }
private slots:
    void on_updatepassword_clicked();
	void on_updatename_clicked();
	void on_updateschool_clicked();
	void on_updatemajor_clicked();
	void on_updateemail_clicked();
	void on_gotomainpage_clicked();
	void on_returnusermanager_clicked();
	void on_confirm1_clicked();
    void on_confirm2_clicked();

private:
	Ui::UserUpdate* ui;
	int choice; //选择，1-5分别为侧边从上到下5个按钮
    bool exist; //判断用户是否存在
};

#endif // USERUPDATE_H
