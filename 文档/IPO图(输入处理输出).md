## 借阅模块

1.

逻辑层函数名称：登录 login()

底层函数输入参数：userid

调用底层函数：usersearchid(string userid)

底层函数返回值：返回用户对象信息字符串  //逻辑层可以自行提取用户密码与输入密码进行对比

2.

逻辑层函数名称：分类展示 typeshowbook()

底层函数输入参数：booktype

调用底层函数：booksearchtype(string type)

底层函数返回值：返回书籍对象信息字符串

3.

逻辑层函数名称：书名查找 namesearchbook()

底层函数输入参数：bookname

调用底层函数：booksearchname(string name)

底层函数返回值：返回书籍对象信息字符串

4.

逻辑层函数名称：ISBN查找  ISBNsearchbook()

底层函数输入参数：bookISBN

调用底层函数：booksearchISBN(string ISBN)

返回值：返回同类书籍第一本书对应的对象的首地址   //需要你们遍历此链表，得到链表长度后，循环得到每一个对象

5.

逻辑层函数名称：借书 borrowbook()

底层函数输入参数：bookid，

调用底层函数：modifybook(string id)           //用于修改Book onsheelf变量 和在history变量中添加借书人

底层函数返回值：bool



## 还书模块

1.

逻辑层函数名称：还书 returnbook()

底层函数输入参数：bookid

调用底层函数：modifybook(string id)              //用于修改Book onsheelf

底层函数返回值：bool



## 用户管理模块

1.

逻辑层函数名称：增加用户 createuser

底层函数输入参数：userid

调用底层函数：useradd(string id,string name,string college,string major,string password,string email)

底层函数返回值：bool

2.

逻辑层函数名称：用户是否已经存在 existuser()

底层函数输入参数：userid

调用底层函数：usersearchid(string id)

底层函数返回值：返回用户对象信息字符串

3.

逻辑层函数名称：删除用户 deleteuser()

底层函数输入参数 ：userid

调用底层函数：userdelete(string id)

底层函数返回值：bool

4.

逻辑层函数名称：修改用户借阅信息 modifyuserdata()

底层函数输入参数：userid

调用底层函数：userstatessearch(string id)

底层函数返回值：bookid

底层函数输入参数：bookid

调用底层函数：booksearchid(string id)

底层函数返回值：返回书籍对象信息字符串

调用底层函数：bookmodify(string id) //修改book onsheelf

底层函数返回值：bool



5.

逻辑层函数名称：是否归还全部图书 returnAllBooks()

底层函数输入参数：userid

调用底层函数：usertatessearch(string id)

底层函数返回值：返回书籍id



## 图书管理模块

1.

逻辑层函数名称：删除图书 deletebook()

底层函数输入参数：bookid

调用底层函数：bookdelete(string id)

底层函数返回值：bool

2.

逻辑层函数名称：修改图书 modifybook()

底层函数输入参数：bookid 

调用底层函数：bookmodify(string id)

底层函数返回值：bool

3.

逻辑层函数名称：增加图书 createbook

底层函数输入参数：bookid

调用底层函数：bookadd(string ISBN,string name,string author,string type,string id,string borrowtime,string returntime,string history, bool onsheelf,bool isovertime;)

底层函数返回值：bool

4.

逻辑层函数名称：该图书是否已经存在 existbook()

底层函数输入参数：bookid

调用底层函数：booksearchid(string id)

底层函数返回值：返回图书对象信息字符串







