# 打开此文档时先看，输入数据时千万不要超过规定值

## 1.数据结构

### (1)Book类

Book类数据结构（或数据模块）的形式为 

```c++
(int id, string value)
//value字符串的长度固定为80，包含：ISBN, name, author, type,  borrowtime, returntime, history, onshelf, isovertime。
//onshelf, isovertime两个变量的取值为0或1，对应类中bool值，使用时转换类型即可。
```



​	在上述数据结构中限定ISBN长度为6，id长度为6，name长度为8，author长度为4，type长度为4，borrowtime格式yy-mm-dd，returntime同，长度各为8。history长度为40，onshelf、isovertime长度为1，取值为0或1。value字符串的格式如下：

![EXCEL_[41] 2020-10-19 15_59_05](D:/Github/Library-Management-System/文档/img/EXCEL_[41] 2020-10-19 15_59_05.png)

​	主要的功能为增加、删除、修改、查询，数据结构为B+树，此种数据结构可以保持数据稳定有序，插入、修改有较稳定的对数时间复杂度![image-20201012211813060](D:/Github/Library-Management-System/文档/img/image-20201012211813060.png)。

​	使用cache作为缓冲区，利用文件读取的局部性加速读写，cache在内存中，断电不保存。

### (2). user类

```C++
(int id, string value)
//value字符串的长度固定为56，包含：name,college,major,password,email.
```

​	在上述数据结构中限定id长度为8，格式为gg（年级） aa（学院） mm（专业） nn（序号）,如18010244. 限定name长度为8，college长度为4（2个中文字符的缩写，或者4个英文字符的缩写），major长度为4（同上），password长度为16，email长度为24.

![EXCEL_[37] 2020-10-18 23_14_44](D:/Github/Library-Management-System/文档/img/EXCEL_[37] 2020-10-18 23_14_44.png)

### (3).userstates类

```c++
(int id, string bookid)
//id和user类的id是同一个id，bookid长度120，是一个20*6的顺序表，可以同时容纳最多20个借阅信息（限制用户借阅数量最大值为20）。
```

![EXCEL_[38] 2020-10-18 23_14_58](D:/Github/Library-Management-System/文档/img/EXCEL_[38] 2020-10-18 23_14_58.png)



# 特别声明

涉及book.history时history中保存的userid必须是8位，这个userid必须是在创建时就确定的8位数字。保存时需经过int到string的类型转换

涉及userstates.bookid时bookid中保存的书的id必须是6位，这个id必须是在创建时就确定的8位数字。保存时需经过int到string的类型转换





## 借阅模块

1.

逻辑层函数名称：登录 login()

底层函数输入参数：userid

调用底层函数：string usersearch(string userid)

底层函数返回值：返回用户对象信息字符串  //逻辑层可以自行提取用户密码与输入密码进行对比

-----------------------------------------------------------------------------------

//以下部分先不做实现

2.

逻辑层函数名称：分类展示 typeshowbook()

底层函数输入参数：booktype

调用底层函数：booksearchid(string type)

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

---------------------------------------------------------------------------------------------

5.

逻辑层函数名称：借书 borrowbook()

底层函数输入参数：bookid，history,onsheelf

调用底层函数：

bool uscreate(int userid, string bookid);//如果这个人是第一次借书，那么先生成他的【在借书单】，如果不是第一次借的话会返回false
bool usadd(int userid,string bookid);//如果不是第一次借的话，往这个人的【在借书单】中添加这本书的id    此时书的id必须是6位 以后我们创建一万本书的时候会把所有书的id都取6位，但是现在测试时建议在创建图书时就把图书的id设为6位数字

bool bookmodifyhistroy(int id, string history);//在书的history中添加这个人的id  此时人的id必须是8位  以后我们创建一百个同学的时候会把所有人的id都取8位，但是现在测试时建议在创建用户时就把人的id设为8位数字

往history中添加userid时，给出一个参考算法

```
去掉history末尾格式化所加的空格  (规定userid应该都是8位的)

history=hsitory+(经过string类型转换的)bookid
//string类型的变量可以直接+   代表字符串连接

填充空格使其满足40位

更新history
```







bool bookmodifyonsheelf(int id, string onsheelf);           

//用于修改Book onsheelf变量 和在history变量中添加借书人

底层函数返回值：bool



## 还书模块

1.

逻辑层函数名称：还书 returnbook()

底层函数输入参数：bookid

调用底层函数：

bool bookmodifyonsheelf(int id, string onsheelf);             //用于修改Book onsheelf

bool usdelete(int userid,string bookid); //在这个人的在借书籍清单中删除这本书的id   此时书的id必须是6位 以后我们创建一万本书的时候会把所有书的id都取6位，但是现在测试时建议在创建图书时就把图书的id设为6位数字

底层函数返回值：bool



## 用户管理模块

1.

逻辑层函数名称：增加用户 createuser

底层函数输入参数：userid

调用底层函数：

bool useradd(int id, string name, string college, string major, string password, string email);

底层函数返回值：bool

2.

逻辑层函数名称：用户是否已经存在 existuser()

底层函数输入参数：userid

调用底层函数：bool userexist(int id)

底层函数返回值：bool

3.

逻辑层函数名称：删除用户 deleteuser()

底层函数输入参数 ：userid

调用底层函数：userdelete(int id)

底层函数返回值：bool

4.

逻辑层函数名称：修改图书 modifyuse()

底层函数输入参数：userid  要修改的信息

调用底层函数：

-   bool usermodifyname(int id, string name);
-   bool usermodifycollege(int id, string college);
-   bool usermodifymajor(int id, string major);
-   bool usermodifypassword(int id, string password);
-   bool usermodifyremail(int id, string email);

底层函数返回值：bool

5.

逻辑层函数名称：是否归还全部图书 returnAllBooks()

底层函数输入参数：userid

调用底层函数：string ussearch(int userid);

底层函数返回值：返回书籍id字符串



## 图书管理模块

int id，string value 

value：

isbn长度为6，name长度为8，author长度为4，type长度为4，borrowtime格式yy-mm-dd，returntime同，长度各为8。history长度为20，onshelf、isovertime长度为1，取值为0或1。

输入的信息不足长度的 用空格填充

**输入到modify函数和add函数中的参数必须是经过格式化（dataformating）的参数**

1.

逻辑层函数名称：删除图书 deletebook()

底层函数输入参数：bookid

调用底层函数：bool bookdelete(int id)

底层函数返回值：bool

2.

逻辑层函数名称：修改图书 modifybook()

底层函数输入参数：bookid  要修改的信息

调用底层函数：

-   bool bookmodifyISBN(int id, string ISBN);
-   bool bookmodifyname(int id, string name);
-   bool bookmodifyauthor(int id, string author);
-   bool bookmodifytype(int id, string type);
-   bool bookmodifyborrowtime(int id, string borrowtime);
-   bool bookmodifyreturntime(int id, string returntime);
-   bool bookmodifyhistroy(int id, string history);
-   bool bookmodifyonsheelf(int id, string sheelf);
-   bool bookmodifyisovertime(int id, string isorvertime);

底层函数返回值：bool

3.

逻辑层函数名称：增加图书 createbook

底层函数输入参数：bookid

调用底层函数：bool bookadd(string ISBN,string name,string author,string type,string borrowtime,string returntime,string history, bool onsheelf,bool isovertime;)

底层函数返回值：bool

4.

逻辑层函数名称：查询图书 

底层函数输入参数：bookid 

调用底层函数：string booksearch(int id);

底层函数返回值：包含图书信息的字符串

5.

逻辑层函数名称：该图书是否已经存在 existbook()

底层函数输入参数：bookid 

调用底层函数：bool bookexist(string id)

底层函数返回值：bool







