#ifndef USERDELETE_H
#define USERDELETE_H

#include"chooseform.h"

namespace Ui {
	class userdelete;
}

class userdelete : public QWidget
{
	Q_OBJECT

public:
	explicit userdelete(QWidget* parent = 0);
	~userdelete();
private slots:
	void on_gotomainpage_clicked();
	void on_exitlogin_clicked();
	void on_confirmsure_clicked();
	void on_deletesure_clicked();
	void on_addusers_clicked();
	void on_updateusers_clicked();
	void on_deleteusers_clicked();
private:
	Ui::userdelete* ui;
};

#endif // USERDELETE_H
