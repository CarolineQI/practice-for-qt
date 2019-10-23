MYSQL 学习笔记

## 一、终端操作 MYSQL数据库

### 1.基本操作

#### 登录数据库服务器

在MySQL安装目录的 bin 目录下执行命令：

```mysql
mysql -u root -p
```



#### 查询数据库服务器中所有的数据库

```mysql
show databases;
```



#### 选中某一个数据库进行操作 

```mysql
use mysql;
```



#### 查询数据库中所有的数据表

```mysql
show tables;
```



#### 退出服务器

```mysql
exit;
```



#### 在数据库服务器创建数据库

```mysql
create database qiyi;
```



#### 创建数据表

```mysql
mysql> create table pet(  
 	-> name VARCHAR(20),
    -> sex CHAR(1),
    -> birth DATE);

mysql> show tables;
+----------------+
| Tables_in_qiyi |
+----------------+
| pet            |
+----------------+
1 row in set (0.00 sec)

mysql> describe pet;
+-------+-------------+------+-----+---------+-------+
| Field | Type        | Null | Key | Default | Extra |
+-------+-------------+------+-----+---------+-------+
| name  | varchar(20) | YES  |     | NULL    |       |
| sex   | char(1)     | YES  |     | NULL    |       |
| birth | date        | YES  |     | NULL    |       |
+-------+-------------+------+-----+---------+-------+
3 rows in set (0.00 sec)
```



#### 删除数据表

```mysql
drop table user2;
```



#### 向数据表中添加记录

```mysql
insert into pet values('cat','m','1899-03-30');
```



#### 删除数据表中记录

```mysql
delete from pet where name='cat';
```



#### 修改数据表中记录

```mysql
update pet set sex='m' where name='rabit';
```



#### 查找数据表中记录

```mysql
select * from user;

select * from city where ID=1;
```



#### MYSQL常见数据类型

MySQL中定义数据字段的类型对你数据库的优化是非常重要的。 

 MySQL支持多种类型，大致可以分为三类：数值、日期/时间和字符串(字符)类型。 

##### **数值类型**

MySQL支持所有标准SQL数值数据类型。

这些类型包括严格数值数据类型(INTEGER、SMALLINT、DECIMAL和NUMERIC)，以及近似数值数据类型(FLOAT、REAL和DOUBLE PRECISION)。

关键字INT是INTEGER的同义词，关键字DEC是DECIMAL的同义词。

 BIT数据类型保存位字段值，并且支持MyISAM、MEMORY、InnoDB和BDB表。 

 作为SQL标准的扩展，MySQL也支持整数类型TINYINT、MEDIUMINT和BIGINT。下面的表显示了需要的每个整数类型的存储和范围。 

| 类型         | 大小                                     | 范围（有符号）                                               | 范围（无符号）                                               | 用途            |
| ------------ | ---------------------------------------- | ------------------------------------------------------------ | ------------------------------------------------------------ | --------------- |
| TINYINT      | 1 字节                                   | (-128，127)                                                  | (0，255)                                                     | 小整数值        |
| SMALLINT     | 2 字节                                   | (-32 768，32 767)                                            | (0，65 535)                                                  | 大整数值        |
| MEDIUMINT    | 3 字节                                   | (-8 388 608，8 388 607)                                      | (0，16 777 215)                                              | 大整数值        |
| INT或INTEGER | 4 字节                                   | (-2 147 483 648，2 147 483 647)                              | (0，4 294 967 295)                                           | 大整数值        |
| BIGINT       | 8 字节                                   | (-9,223,372,036,854,775,808，9 223 372 036 854 775 807)      | (0，18 446 744 073 709 551 615)                              | 极大整数值      |
| FLOAT        | 4 字节                                   | (-3.402 823 466 E+38，-1.175 494 351 E-38)，0，(1.175 494 351 E-38，3.402 823 466 351 E+38) | 0，(1.175 494 351 E-38，3.402 823 466 E+38)                  | 单精度 浮点数值 |
| DOUBLE       | 8 字节                                   | (-1.797 693 134 862 315 7 E+308，-2.225 073 858 507 201 4 E-308)，0，(2.225 073 858 507 201 4 E-308，1.797 693 134 862 315 7 E+308) | 0，(2.225 073 858 507 201 4 E-308，1.797 693 134 862 315 7 E+308) | 双精度 浮点数值 |
| DECIMAL      | 对DECIMAL(M,D) ，如果M>D，为M+2否则为D+2 | 依赖于M和D的值                                               | 依赖于M和D的值                                               | 小数值          |

##### **日期和时间类型**

 表示时间值的日期和时间类型为DATETIME、DATE、TIMESTAMP、TIME和YEAR。

每个时间类型有一个有效值范围和一个"零"值，当指定不合法的MySQL不能表示的值时使用"零"值。

TIMESTAMP类型有专有的自动更新特性，将在后面描述。

| 类型      | 大小 (字节) | 范围                                                         | 格式                | 用途                     |
| --------- | ----------- | ------------------------------------------------------------ | ------------------- | ------------------------ |
| DATE      | 3           | 1000-01-01/9999-12-31                                        | YYYY-MM-DD          | 日期值                   |
| TIME      | 3           | '-838:59:59'/'838:59:59'                                     | HH:MM:SS            | 时间值或持续时间         |
| YEAR      | 1           | 1901/2155                                                    | YYYY                | 年份值                   |
| DATETIME  | 8           | 1000-01-01 00:00:00/9999-12-31 23:59:59                      | YYYY-MM-DD HH:MM:SS | 混合日期和时间值         |
| TIMESTAMP | 4           | 1970-01-01 00:00:00/2038   结束时间是第 **2147483647** 秒，北京时间 **2038-1-19 11:14:07**，格林尼治时间 2038年1月19日 凌晨 03:14:07 | YYYYMMDD HHMMSS     | 混合日期和时间值，时间戳 |

##### **字符串类型**

字符串类型指CHAR、VARCHAR、BINARY、VARBINARY、BLOB、TEXT、ENUM和SET。该节描述了这些类型如何工作以及如何在查询中使用这些类型。 

| 类型       | 大小                | 用途                            |
| ---------- | ------------------- | ------------------------------- |
| CHAR       | 0-255字节           | 定长字符串                      |
| VARCHAR    | 0-65535 字节        | 变长字符串                      |
| TINYBLOB   | 0-255字节           | 不超过 255 个字符的二进制字符串 |
| TINYTEXT   | 0-255字节           | 短文本字符串                    |
| BLOB       | 0-65 535字节        | 二进制形式的长文本数据          |
| TEXT       | 0-65 535字节        | 长文本数据                      |
| MEDIUMBLOB | 0-16 777 215字节    | 二进制形式的中等长度文本数据    |
| MEDIUMTEXT | 0-16 777 215字节    | 中等长度文本数据                |
| LONGBLOB   | 0-4 294 967 295字节 | 二进制形式的极大文本数据        |
| LONGTEXT   | 0-4 294 967 295字节 | 极大文本数据                    |

CHAR 和 VARCHAR 类型类似，但它们保存和检索的方式不同。它们的最大长度和是否尾部空格被保留等方面也不同。在存储或检索过程中不进行大小写转换。

BINARY 和 VARBINARY 类似于 CHAR 和 VARCHAR，不同的是它们包含二进制字符串而不要非二进制字符串。也就是说，它们包含字节字符串而不是字符字符串。这说明它们没有字符集，并且排序和比较基于列值字节的数值值。

BLOB 是一个二进制大对象，可以容纳可变数量的数据。有 4 种 BLOB 类型：TINYBLOB、BLOB、MEDIUMBLOB 和 LONGBLOB。它们区别在于可容纳存储范围不同。 

 有 4 种 TEXT 类型：TINYTEXT、TEXT、MEDIUMTEXT 和 LONGTEXT。对应的这 4 种 BLOB 类型，可存储的最大长度不同，可根据实际情况选择。 

### 2.约束

####   分类

- **主键约束(primary key) PK**   

  PRIMARY KEY:主键，用于保证该字段的值具有唯一性，并且非空

- **自增约束(auto increment)**

- **外键约束(foreign key) FK**

  FOREIGN KEY:外键，用于限制两个表的关系，用于保证该字段的值必须来自于主表的关联列的值
  在从表添加外键约束，用于引用主表中某列的值
  比如学生表的专业编号，员工表的部门编号，员工表的工种编号

- **唯一性约束(unique)**

  UNIQUE:唯一，用于保证该字段的值具有唯一性，可以为空
  比如座位号

- **非空约束(not null)**  

  NOT NULL:非空 ，用于保证该字段的值不能为空  比如姓名、学号等

- **默认约束（default）**

  DEFAULT:默认，用于保证该字段有默认值
  比如性别

- **检查约束(目前MySQL不支持、Oracle支持)**

  CHECK:检查约束【mysql中不支持】
  比如年龄、性别

  PRIMARY KEY:主键，用于保证该字段的值具有唯一性，并且非空

#### 主键约束(primary key) PK   

  它能够唯一确定一张表中的一条记录，也就是我们通过给某个字段添加约束，就可以使得改字段不重复且不为空。比如学号、员工编号等

  ```mysql
  create table user(id int primary key, name varchar(20));
  
  mysql> describe user;
  +-------+-------------+------+-----+---------+-------+
  | Field | Type        | Null | Key | Default | Extra |
  +-------+-------------+------+-----+---------+-------+
  | id    | int(11)     | NO   | PRI | NULL    |       |
  | name  | varchar(20) | YES  |     | NULL    |       |
  +-------+-------------+------+-----+---------+-------+
  2 rows in set (0.01 sec)
  mysql> insert into user values(1,'张三');
  Query OK, 1 row affected (0.01 sec)
  
  mysql> select * from user;
  +----+------+
  | id | name |
  +----+------+
  |  1 | 张三 |
  +----+------+
  1 row in set (0.00 sec)
  
  mysql> insert into user values(1,'fg');
  ERROR 1062 (23000): Duplicate entry '1' for key 'PRIMARY'
  
  mysql> insert into user values(NULL,'fg');
  ERROR 1048 (23000): Column 'id' cannot be null
  ```

##### 复合主键

只要复合的主键值加起来不重复就可以，但复合组件内任何组件都不能为空。

```mysql
create table user2(
id int, name varchar(20), password varchar(20), primary key(id,name)
);

mysql> describe user2;
+----------+-------------+------+-----+---------+-------+
| Field    | Type        | Null | Key | Default | Extra |
+----------+-------------+------+-----+---------+-------+
| id       | int(11)     | NO   | PRI | NULL    |       |
| name     | varchar(20) | NO   | PRI | NULL    |       |
| password | varchar(20) | YES  |     | NULL    |       |
+----------+-------------+------+-----+---------+-------+

mysql> insert into user2 values(1,'abd','521334');
mysql> insert into user2 values(2,'abd','521334');
mysql> insert into user2 values(1,'abc','521334');

mysql>  select * from user2;
+----+------+----------+
| id | name | password |
+----+------+----------+
|  1 | abc  | 521334   |
|  1 | abd  | 521334   |
|  2 | abd  | 521334   |
+----+------+----------+

```

##### 自增约束(auto increment)

```mysql
create table user3(
	id int primary key auto_increment,
    name varchar(20),
    Password varchar(20)
);

insert into user3 (name) value('zhsng');

insert into user3 (name,Password) value('zhsndsgdnmg','53121534');

select * from user3;
+----+-------------+----------+
| id | name        | Password |
+----+-------------+----------+
|  1 | zhsng       | NULL     |
|  2 | zhsndsgdnmg | 53121534 |
+----+-------------+----------+
```

##### 建表后添加/删除/修改主键

```mysql
create table user4(
	id int,
    name varchar(20),
    Password varchar(20)
);
##添加主键约束
alter table user4 add primary key (id);

desc user4;
+----------+-------------+------+-----+---------+-------+
| Field    | Type        | Null | Key | Default | Extra |
+----------+-------------+------+-----+---------+-------+
| id       | int(11)     | NO   | PRI | NULL    |       |
| name     | varchar(20) | YES  |     | NULL    |       |
| Password | varchar(20) | YES  |     | NULL    |       |
+----------+-------------+------+-----+---------+-------+

##删除主键约束
alter table user4 drop primary key;

##修改主键约束
alter table user4 modify id int primary key;
```

#### 唯一性约束(unique)

  UNIQUE:唯一，用于保证该字段的值具有唯一性，可以为空
  比如座位号

```mysql

create table user5(
	id int,
    name varchar(20) unique,
    Password varchar(20)
);
##或者
create table user5(
	id int,
    name varchar(20),
    Password varchar(20)
);
alter table user5 add unique(name);
##或者
create table user6(
	id int,
    name varchar(20),
    password varchar(20),
    unique (id, name)##类似于复合主键
);


insert into user5 values(1,'abd','521334');
insert into user5 values(2,'abd','521334');


##删除唯一约束
alter table user5 drop index id;

##修改主键约束
alter table user5 modify id int unique;

```



#### 非空约束(not null) 

  NOT NULL:非空 ，用于保证该字段的值不能为空  比如姓名、学号等

```mysql
create table user6(
	id int,
    name varchar(20) not null,
    Password varchar(20)
);

 insert into user6 (id) value (1);
## ERROR 1364 (HY000): Field 'name' doesn't have a default value

insert into user6 (id,name) value (1,'dgsdkl');

mysql> select * from user6;
+------+--------+----------+
| id   | name   | Password |
+------+--------+----------+
|    1 | dgsdkl | NULL     |
+------+--------+----------+

```



#### 默认约束（default）

  DEFAULT:默认，用于保证该字段有默认值
  比如性别

```mysql
create table user7(
	id int,
    name varchar(20),
    age int default 10,
    Password varchar(20)
);

 desc user7;
+----------+-------------+------+-----+---------+-------+
| Field    | Type        | Null | Key | Default | Extra |
+----------+-------------+------+-----+---------+-------+
| id       | int(11)     | YES  |     | NULL    |       |
| name     | varchar(20) | YES  |     | NULL    |       |
| age      | int(11)     | YES  |     | 10      |       |
| Password | varchar(20) | YES  |     | NULL    |       |
+----------+-------------+------+-----+---------+-------+
4 rows in set (0.01 sec)

insert into user7 (id,name) value(1,'zhakgn');
Query OK, 1 row affected (0.00 sec)

mysql> select * from user7;
+------+--------+------+----------+
| id   | name   | age  | Password |
+------+--------+------+----------+
|    1 | zhakgn |   10 | NULL     |
+------+--------+------+----------+
1 row in set (0.00 sec)
```



#### 外键约束(foreign key) FK

  FOREIGN KEY:外键，用于限制两个表的关系，用于保证该字段的值必须来自于主表的关联列的值
  在从表添加外键约束，用于引用主表中某列的值
  比如学生表的专业编号，员工表的部门编号，员工表的工种编号

```mysql
##班级
create table classes(
	id int primary key auto_increment,
    name varchar(20)
);

##学生
create table students(
	id int primary key auto_inrement,
    name varchar(20),
    class_id int,
    foreign key(class_id) references classes(id)
);

insert into classes (name) value('一班');
insert into classes (name) value('二班');
insert into classes (name) value('三班');
insert into classes (name) value('四班');

 select * from classes;
+----+------+
| id | name |
+----+------+
|  1 | 一班 |
|  2 | 二班 |
|  3 | 三班 |
|  4 | 四班 |
+----+------+
4 rows in set (0.00 sec)

insert into students (name,class_id) value('一班',1);
insert into students (name,class_id) value('二班',2);
insert into students (name,class_id) value('三班',3);
insert into students (name,class_id) value('四班',4);

 select * from students;
+----+------+----------+
| id | name | class_id |
+----+------+----------+
|  1 | 一班 |        1 |
|  2 | 二班 |        2 |
|  3 | 三班 |        3 |
|  4 | 四班 |        4 |
+----+------+----------+
4 rows in set (0.00 sec)

mysql>  insert into students (name,class_id) value('五班',5);
ERROR 1452 (23000): Cannot add or update a child row: a foreign key constraint fails (`qiyi`.`students`, CONSTRAINT `students_ibfk_1` FOREIGN KEY (`class_id`) REFERENCES `classes` (`id`))


```

* 主表中没有的数据值，副表是不可以使用的
* 主表中被副表引用的记录不可以被删除

#### 检查约束(目前MySQL不支持、Oracle支持)

  CHECK:检查约束【mysql中不支持】
  比如年龄、性别

### 3.数据表设计范式

关系数据库中的关系必须满足一定的要求，即满足不同的范式。

关系数据库有六种范式：第一范式（1NF）、第二范式（2NF）、第三范式（3NF）、巴德斯科范式（BCNF）、第四范式（4NF）和第五范式（5NF）。满足最低要求的范式是第一范式（1NF）。在第一范式的基础上进一步满足更多要求的称为第二范式（2NF），其余范式以次类推。一般说来，数据库只需满足第三范式（3NF）就行了。

#### 第一范式1NF

**无重复的列**

数据库表的每一列都是不可分割的原子数据项，而不能是集合，数组，记录等非原子数据项。如果实体中的某个属性有多个值时，必须拆分为不同的属性。

```mysql
create table student2(
	id int primary key,
    name varchar(20),
    address varchar(30));
insert into student2 values(1,'张三','中国四川省成都市武侯区武侯大道100号');
insert into student2 values(2,'李四','中国四川省成都市武侯区京城大道200号');
insert into student2 values(3,'王五','中国四川省成都市高新区天府大道90号');

select * from student2;
+----+------+-------------------------------------+
| id | name | address                             |
+----+------+-------------------------------------+
|  1 | 张三 | 中国四川省成都市武侯区武侯大道100号 |
|  2 | 李四 | 中国四川省成都市武侯区京城大道200号 |
|  3 | 王五 | 中国四川省成都市高新区天府大道90号  |
+----+------+-------------------------------------+

create table student3(
    id int primary key,
    name varchar(20),
    cuntry varchar(30),
    privence varchar(30),
    city varchar(30),
    area varchar(30),
    details varchar(30)
);
insert into student3 values(1,'张三','中国','四川省','成都市','武侯区','武侯大道100号');
insert into student3 values(2,'李四','中国','四川省','成都市','武侯区','京城大道200号');
insert into student3 values(3,'王五','中国','四川省','成都市','高新区','天府大道90号');

select * from student3;
+----+------+--------+----------+--------+--------+---------------+
| id | name | cuntry | privence | city   | area   | details       |
+----+------+--------+----------+--------+--------+---------------+
|  1 | 张三  | 中国   | 四川省    | 成都市  | 武侯区  | 武侯大道100号  |
|  2 | 李四  | 中国   | 四川省    | 成都市  | 武侯区  | 京城大道200号  |
|  3 | 王五  | 中国   | 四川省    | 成都市  | 高新区  | 天府大道90号   |
+----+------+--------+----------+--------+--------+---------------+

## 尽量保证列不可拆分

```



#### 第二范式2NF

**属性完全依赖于主键**

第二范式（2NF）是在第一范式（1NF）的基础上建立起来的，即满足第二范式（2NF）必须先满足第一范式（1NF）。

当存在多个主键的时候，才会发生不符合第二范式的情况。比如有两个主键，不能存在这样的属性，它只依赖于其中一个主键，这就是不符合第二范式。

如果存在不符合第二范式的情况，那么这个属性和主关键字的这一部分应该分离出来形成一个新的实体，新实体与原实体之间是一对多的关系。

```mysql
create table myorder(
	product_id int,
    customer_id int,
    product_name varchar(20),
    customer_name varchar(20),
    primary key(product_id,customer_id)
);

##问题？
##除主键以外的其他列，只依赖与主键的部分字段。
##拆表

create table myorder(
	order_id int primary key,
    product_id int,
    customer_id int
); 
create table product(
	id int primary key,
    name varchar(20)
); 
create table customer(
	id int primary key,
    name varchar(20)
);

```



#### 第三范式3NF

**属性不能传递依赖于主属性（属性不依赖于其它非主键属性）**

第三范式（3NF）是在第二范式（2NF）的基础上建立起来的，即满足第三范式（3NF）必须先满足第二范式（2NF）。

如果某一属性依赖于其他非主键属性，而其他非主键属性又依赖于主键，那么这个属性就是间接依赖于主键，这被称作传递依赖于主属性。

和主键直接相关,而不是间接相关

3NF是对字段冗余的约束，既字段不能由其他字段派生出来，它要求字段没有冗余。

### 4.查询练习

#### **创建数据表**

```mysql
##学生表
Student
学号
姓名
性别
出生年月日
所在班级

create table student(
	stuNum varchar(10) primary key,
    stuName varchar(20) not null,
    stuSex varchar(10) not null,
    stuBirthday datetime,
    class varchar(20)
);

##教师表
Teacher
教师编号
教师名字
教师性别
出生年月日
职称
所在部门
create table teacher(
	tNum varchar(10) primary key,
    tName varchar(20) not null,
    tSex varchar(10) not null,
    tBirthday datetime,
    prof varchar(20) not null,
    depart varchar(20) not null
);

##课程表
Course
课程号
课程名称
教师编号
create table course(
	cNum varchar(10) primary key,
    cName varchar(20) not null,
    tNum varchar(20) not null,
    foreign key(tNum) references teacher(tNum)
);

##成绩表
Score 
学号
课程号
成绩

create table score(
	stuNum varchar(20) not null,
    cNum varchar(20) not null,
    score decimal not null,
    foreign key(stuNum) references student(stuNum),
    foreign key(cNum) references course(cNum),
    primary key(stuNum,cNum)
);
```

#### **插入数据**

```mysql
#添加学生表
insert into student values('101','曾华','男','1977-09-01','95033');
insert into student values ('102','匡明','男','1975-10-02','95031');
insert into student values('103','王丽','女','1976-01-23','95033');
insert into student values('104','李军','男','1976-02-20','95033');
insert into student values('105','王芳','女','1975-02-10','95031');
insert into student values('106','陆君','男','1974-06-03','95031');
insert into student values('107','王尼玛','男','1976-02-20','95033');
insert into student values('108','张全蛋','男','1975-02-101','95031');
insert into student values('109','赵铁柱','男','1974-06-03','95031');

#添加教师表

insert into teacher values('804', '李成', '男', '1958-12-02', '副教授', '计算机系');
insert into teacher values('856', '张旭', '男', '1969-03-12', '讲师', '电子工程系');
insert into teacher values('825', '王萍', '女', '1972-05-05', '助教' , '计算机系');
insert into teacher values('831', '刘冰', '女', '1977-08-14', '助教', '电子工程系');

#添加课程表

insert into course values('3-105', '计算机导论', '825');
insert into course values('3-245', '操作系统', '804');
insert into course values('6-166', '数字电路', '856');
insert into course values('9-888', '高等数学', '831');

#添加成绩表
#Add transcript
insert score value ('103', '3-245', '86');
insert score value ('105', '3-245', '75');
insert score value ('109', '3-245', '68');
insert score value ('103', '3-105', '92');
insert score value ('105', '3-105','88');
insert score value ('109', '3-105', '76');
insert score value ('103', '6-166', '85');
insert score value ('105', '6-166', '79');
insert score value ('109', '6-166', '81');
```

#### **查询**

##### 1、查询stuent表的所有记录。

```mysql
select * from student;
+--------+---------+--------+---------------------+-------+
| stuNum | stuName | stuSex | stuBirthday         | class |
+--------+---------+--------+---------------------+-------+
| 101    | 曾华    | 男     | 1977-09-01 00:00:00 | 95033 |
| 102    | 匡明    | 男     | 1975-10-02 00:00:00 | 95031 |
| 103    | 王丽    | 女     | 1976-01-23 00:00:00 | 95033 |
| 104    | 李军    | 男     | 1976-02-20 00:00:00 | 95033 |
| 105    | 王芳    | 女     | 1975-02-10 00:00:00 | 95031 |
| 106    | 陆君    | 男     | 1974-06-03 00:00:00 | 95031 |
| 107    | 王尼玛  | 男     | 1976-02-20 00:00:00 | 95033 |
| 109    | 赵铁柱  | 男     | 1974-06-03 00:00:00 | 95031 |
+--------+---------+--------+---------------------+-------+
```

##### 2、查询student表中的所有记录的stuName、stuSex和class列。

```mysql
select stuName,stuSex,class from student;
+---------+--------+-------+
| stuName | stuSex | class |
+---------+--------+-------+
| 曾华    | 男     | 95033 |
| 匡明    | 男     | 95031 |
| 王丽    | 女     | 95033 |
| 李军    | 男     | 95033 |
| 王芳    | 女     | 95031 |
| 陆君    | 男     | 95031 |
| 王尼玛  | 男     | 95033 |
| 赵铁柱  | 男     | 95031 |
+---------+--------+-------+
```

##### 3、查询教师所有的单位即不重复的depart列。
```mysql
select depart from teacher;
+------------+
| depart     |
+------------+
| 计算机系   |
| 计算机系   |
| 电子工程系 |
| 电子工程系 |
+------------+

#distinct 排重

select distinct depart from teacher;
+------------+
| depart     |
+------------+
| 计算机系   |
| 电子工程系 |
+------------+
```

##### 4、查询score表中成绩在60到80之间的所有记录。

```mysql
select * from score where score between 60 and 80;
+--------+-------+-------+
| stuNum | cNum  | score |
+--------+-------+-------+
| 105    | 3-245 |    75 |
| 105    | 6-166 |    79 |
| 109    | 3-105 |    76 |
| 109    | 3-245 |    68 |
+--------+-------+-------+
select * from score where score>=60 and score<=80;
+--------+-------+-------+
| stuNum | cNum  | score |
+--------+-------+-------+
| 105    | 3-245 |    75 |
| 105    | 6-166 |    79 |
| 109    | 3-105 |    76 |
| 109    | 3-245 |    68 |
+--------+-------+-------+
```

##### 5、查询score表中成绩为85，86或88的记录。

```mysql
select * from score where score in(85,86,88);
+--------+-------+-------+
| stuNum | cNum  | score |
+--------+-------+-------+
| 103    | 3-245 |    86 |
| 103    | 6-166 |    85 |
| 105    | 3-105 |    88 |
+--------+-------+-------+
```

##### 6、查询student表中“95031"班或性别为“女”的同学记录。

```mysql
select * from student where class='95031' or stuSex='女';
+--------+---------+--------+---------------------+-------+
| stuNum | stuName | stuSex | stuBirthday         | class |
+--------+---------+--------+---------------------+-------+
| 102    | 匡明    | 男     | 1975-10-02 00:00:00 | 95031 |
| 103    | 王丽    | 女     | 1976-01-23 00:00:00 | 95033 |
| 105    | 王芳    | 女     | 1975-02-10 00:00:00 | 95031 |
| 106    | 陆君    | 男     | 1974-06-03 00:00:00 | 95031 |
| 109    | 赵铁柱  | 男     | 1974-06-03 00:00:00 | 95031 |
+--------+---------+--------+---------------------+-------+
```

##### 7、以class降序查询student表的所有记录。

```mysql
#desc--降序
select * from student order by class desc;
+--------+---------+--------+---------------------+-------+
| stuNum | stuName | stuSex | stuBirthday         | class |
+--------+---------+--------+---------------------+-------+
| 101    | 曾华    | 男     | 1977-09-01 00:00:00 | 95033 |
| 103    | 王丽    | 女     | 1976-01-23 00:00:00 | 95033 |
| 104    | 李军    | 男     | 1976-02-20 00:00:00 | 95033 |
| 107    | 王尼玛  | 男     | 1976-02-20 00:00:00 | 95033 |
| 102    | 匡明    | 男     | 1975-10-02 00:00:00 | 95031 |
| 105    | 王芳    | 女     | 1975-02-10 00:00:00 | 95031 |
| 106    | 陆君    | 男     | 1974-06-03 00:00:00 | 95031 |
| 109    | 赵铁柱  | 男     | 1974-06-03 00:00:00 | 95031 |
+--------+---------+--------+---------------------+-------+
#asc--升序（默认是升序）
select * from student order by class asc;
+--------+---------+--------+---------------------+-------+
| stuNum | stuName | stuSex | stuBirthday         | class |
+--------+---------+--------+---------------------+-------+
| 102    | 匡明    | 男     | 1975-10-02 00:00:00 | 95031 |
| 105    | 王芳    | 女     | 1975-02-10 00:00:00 | 95031 |
| 106    | 陆君    | 男     | 1974-06-03 00:00:00 | 95031 |
| 109    | 赵铁柱  | 男     | 1974-06-03 00:00:00 | 95031 |
| 101    | 曾华    | 男     | 1977-09-01 00:00:00 | 95033 |
| 103    | 王丽    | 女     | 1976-01-23 00:00:00 | 95033 |
| 104    | 李军    | 男     | 1976-02-20 00:00:00 | 95033 |
| 107    | 王尼玛  | 男     | 1976-02-20 00:00:00 | 95033 |
+--------+---------+--------+---------------------+-------+
```

##### 8、以cno升序、score降序查询score表的所有记录。

```mysql
select * from score order by cNum asc, score desc;
+--------+-------+-------+
| stuNum | cNum  | score |
+--------+-------+-------+
| 103    | 3-105 |    92 |
| 105    | 3-105 |    88 |
| 109    | 3-105 |    76 |
| 103    | 3-245 |    86 |
| 105    | 3-245 |    75 |
| 109    | 3-245 |    68 |
| 103    | 6-166 |    85 |
| 109    | 6-166 |    81 |
| 105    | 6-166 |    79 |
+--------+-------+-------+
```

##### 9、查询“95031”班的学生人数。(统计 count)

```mysql
select count(*) from student where class='95031';
+----------+
| count(*) |
+----------+
|        4 |
+----------+
select * from student where class='95031';
+--------+---------+--------+---------------------+-------+
| stuNum | stuName | stuSex | stuBirthday         | class |
+--------+---------+--------+---------------------+-------+
| 102    | 匡明    | 男     | 1975-10-02 00:00:00 | 95031 |
| 105    | 王芳    | 女     | 1975-02-10 00:00:00 | 95031 |
| 106    | 陆君    | 男     | 1974-06-03 00:00:00 | 95031 |
| 109    | 赵铁柱  | 男     | 1974-06-03 00:00:00 | 95031 |
+--------+---------+--------+---------------------+-------+
```

##### 10、查询score表中的最高分的学生学号和课程号。（子查询或者排序）

```mysql
#子查询

select stuNum,cNum from score where score=( select max(score) from score);

+--------+-------+
| stuNum | cNum  |
+--------+-------+
| 103    | 3-105 |
+--------+-------+

# 第一步：找到最高分

select max(score) from score;
+------------+
| max(score) |
+------------+
|         92 |
+------------+
#第二步：查询92分的学生学号和课程号
select stuNum,cNum from score where score='92';
+--------+-------+
| stuNum | cNum  |
+--------+-------+
| 103    | 3-105 |
+--------+-------+

#排序的做法：
select stuNum,cNum,score from score order by score desc limit 0,1;

+--------+-------+-------+
| stuNum | cNum  | score |
+--------+-------+-------+
| 103    | 3-105 |    92 |
+--------+-------+-------+
```

##### 11、查询每门课的平均成绩。
```mysql
+-------+------------+------+
| cNum  | cName      | tNum |
+-------+------------+------+
| 3-105 | 计算机导论 | 825  |
| 3-245 | 操作系统   | 804  |
| 6-166 | 数字电路   | 856  |
| 9-888 | 高等数学   | 831  |
+-------+------------+------+
select avg(score) from score where cNum ='3-105';
+------------+
| avg(score) |
+------------+
|    85.3333 |
+------------+
select * from score where cNum ='3-105';
+--------+-------+-------+
| stuNum | cNum  | score |
+--------+-------+-------+
| 103    | 3-105 |    92 |
| 105    | 3-105 |    88 |
| 109    | 3-105 |    76 |
+--------+-------+-------+

select cNum,avg(score) from score group by cNum;
+-------+------------+
| cNum  | avg(score) |
+-------+------------+
| 3-105 |    85.3333 |
| 3-245 |    76.3333 |
| 6-166 |    81.6667 |
+-------+------------+
```

##### 12、查询score表中至少有2名学生选修的并以3开头的课程的平均分数。

```mysql
select * from score group by cNum having count(cNum)>=2;
+-------+
| cNum  |
+-------+
| 3-105 |
| 3-245 |
| 6-166 |
+-------+

select cNum from score group by cNum having count(cNum)>=2 and cNum like '3%' ;

+-------+
| cNum  |
+-------+
| 3-105 |
| 3-245 |
+-------+
select cNum ,avg(score),count(*) from score group by cNum having count(cNum)>=2 and cNum like '3%' ;
+-------+------------+----------+
| cNum  | avg(score) | count(*) |
+-------+------------+----------+
| 3-105 |    85.3333 |        3 |
| 3-245 |    76.3333 |        3 |
+-------+------------+----------+
```

##### 13、查询分数大于70，小于90的sno列。(范围查询)

```mysql
select stuNum,score from score where score>70 and score<90;

+--------+-------+
| stuNum | score |
+--------+-------+
| 103    |    86 |
| 103    |    85 |
| 105    |    88 |
| 105    |    75 |
| 105    |    79 |
| 109    |    76 |
| 109    |    81 |
+--------+-------+

select stuNum,score from score where score between 70 and 90;
+--------+-------+
| stuNum | score |
+--------+-------+
| 103    |    86 |
| 103    |    85 |
| 105    |    88 |
| 105    |    75 |
| 105    |    79 |
| 109    |    76 |
| 109    |    81 |
+--------+-------+
```

##### 14、(多表查询)查询所有学生的 stuName、cNum和score列。
```mysql
select stuNum,stuName from student;
+--------+---------+
| stuNum | stuName |
+--------+---------+
| 101    | 曾华    |
| 102    | 匡明    |
| 103    | 王丽    |
| 104    | 李军    |
| 105    | 王芳    |
| 106    | 陆君    |
| 107    | 王尼玛  |
| 109    | 赵铁柱  |
+--------+---------+

select stuNum,cNum ,score from score;
+--------+-------+-------+
| stuNum | cNum  | score |
+--------+-------+-------+
| 103    | 3-105 |    92 |
| 103    | 3-245 |    86 |
| 103    | 6-166 |    85 |
| 105    | 3-105 |    88 |
| 105    | 3-245 |    75 |
| 105    | 6-166 |    79 |
| 109    | 3-105 |    76 |
| 109    | 3-245 |    68 |
| 109    | 6-166 |    81 |
+--------+-------+-------+

select stuName,cNum, score from student, score where student.stuNum=score.stuNum;

+---------+-------+-------+
| stuName | cNum  | score |
+---------+-------+-------+
| 王丽    | 3-105 |    92 |
| 王丽    | 3-245 |    86 |
| 王丽    | 6-166 |    85 |
| 王芳    | 3-105 |    88 |
| 王芳    | 3-245 |    75 |
| 王芳    | 6-166 |    79 |
| 赵铁柱  | 3-105 |    76 |
| 赵铁柱  | 3-245 |    68 |
| 赵铁柱  | 6-166 |    81 |
+---------+-------+-------+
```



##### 15、查询所有学生的stuNum、cName和score列。

```mysql
select stuNum,cName, score from course, score where course.cNum=score.cNum;
+--------+------------+-------+
| stuNum | cName      | score |
+--------+------------+-------+
| 103    | 计算机导论 |    92 |
| 105    | 计算机导论 |    88 |
| 109    | 计算机导论 |    76 |
| 103    | 操作系统   |    86 |
| 105    | 操作系统   |    75 |
| 109    | 操作系统   |    68 |
| 103    | 数字电路   |    85 |
| 105    | 数字电路   |    79 |
| 109    | 数字电路   |    81 |
+--------+------------+-------+
```

##### 16、查询所有学生的stuName、cName和score列。

```mysql
stuName->student 
cName->course
score->score
select stuName,cName, score from student, course, score where student.stuNum=score.stuNum and course.cNum=score.cNum;
+---------+------------+-------+
| stuName | cName      | score |
+---------+------------+-------+
| 王丽    | 计算机导论 |    92 |
| 王丽    | 操作系统   |    86 |
| 王丽    | 数字电路   |    85 |
| 王芳    | 计算机导论 |    88 |
| 王芳    | 操作系统   |    75 |
| 王芳    | 数字电路   |    79 |
| 赵铁柱  | 计算机导论 |    76 |
| 赵铁柱  | 操作系统   |    68 |
| 赵铁柱  | 数字电路   |    81 |
+---------+------------+-------+

select stuName,cName, score, student.stuNum, course.cNum from student, course, score where student.stuNum=score.stuNum and course.cNum=score.cNum;

+---------+------------+-------+--------+-------+
| stuName | cName      | score | stuNum | cNum  |
+---------+------------+-------+--------+-------+
| 王丽    | 计算机导论 |    92 | 103    | 3-105 |
| 王丽    | 操作系统   |    86 | 103    | 3-245 |
| 王丽    | 数字电路   |    85 | 103    | 6-166 |
| 王芳    | 计算机导论 |    88 | 105    | 3-105 |
| 王芳    | 操作系统   |    75 | 105    | 3-245 |
| 王芳    | 数字电路   |    79 | 105    | 6-166 |
| 赵铁柱  | 计算机导论 |    76 | 109    | 3-105 |
| 赵铁柱  | 操作系统   |    68 | 109    | 3-245 |
| 赵铁柱  | 数字电路   |    81 | 109    | 6-166 |
+---------+------------+-------+--------+-------+
```

##### 17、查询“95031"班学生每门课的平均分。

```mysql
class->student
score->score

select *from score where stuNum in(select stuNum from student where class='95031') order by cNum;
+--------+-------+-------+
| stuNum | cNum  | score |
+--------+-------+-------+
| 105    | 3-105 |    88 |
| 109    | 3-105 |    76 |
| 105    | 3-245 |    75 |
| 109    | 3-245 |    68 |
| 105    | 6-166 |    79 |
| 109    | 6-166 |    81 |
+--------+-------+-------+

select *,avg(score) from score where stuNum in(select stuNum from student where class='95031') group by cNum ;
+--------+-------+-------+------------+
| stuNum | cNum  | score | avg(score) |
+--------+-------+-------+------------+
| 105    | 3-105 |    88 |    82.0000 |
| 105    | 3-245 |    75 |    71.5000 |
| 105    | 6-166 |    79 |    80.0000 |
+--------+-------+-------+------------+

select *from score where stuNum in(select stuNum from student where class='95031') order by cNum;
```

##### 18、查询选修“3-105”课程的成绩高于“109”号同学“3-105”成绩的所有同学的记录。

```mysql
select *from score where cNum='3-105'and score>(select score from score where cNum='3-105'and stuNum='109');
+--------+-------+-------+
| stuNum | cNum  | score |
+--------+-------+-------+
| 103    | 3-105 |    92 |
| 105    | 3-105 |    88 |
+--------+-------+-------+
```

##### 19、查询成绩高于学号为“109”、课程号为“3-105”的成绩的所有记录。

```mysql
select *from score where score>(select score from score where cNum='3-105'and stuNum='109');
+--------+-------+-------+
| stuNum | cNum  | score |
+--------+-------+-------+
| 103    | 3-105 |    92 |
| 103    | 3-245 |    86 |
| 103    | 6-166 |    85 |
| 105    | 3-105 |    88 |
| 105    | 6-166 |    79 |
| 109    | 6-166 |    81 |
+--------+-------+-------+
```

##### 20、查询和学号为108、101的同学同年出生的所有学生的stuNum、stuName和stuBirthday列。

```mysql
select stuNum,stuName,stuBirthday from student where year(stuBirthday) in (select year(stuBirthday) from student where stuNum in ('107','101'));
+--------+---------+---------------------+
| stuNum | stuName | stuBirthday         |
+--------+---------+---------------------+
| 101    | 曾华    | 1977-09-01 00:00:00 |
| 103    | 王丽    | 1976-01-23 00:00:00 |
| 104    | 李军    | 1976-02-20 00:00:00 |
| 107    | 王尼玛  | 1976-02-20 00:00:00 |
+--------+---------+---------------------+
```

##### 21、查询“张旭“教师任课的学生成绩。

```mysql
select * from score where cNum in (select cNum from course where tNum = (select tNum from teacher where tName='张旭') );
+--------+-------+-------+
| stuNum | cNum  | score |
+--------+-------+-------+
| 103    | 6-166 |    85 |
| 105    | 6-166 |    79 |
| 109    | 6-166 |    81 |
+--------+-------+-------+
```

##### 22、查询选修某课程的同学人数多于5人的教师姓名。

```mysql
insert into score values('101','3-105','90');
insert into score values('102','3-105','91');
insert into score values('104','3-105','89');

select * from teacher where tNum in (select tNum from course where cNum in (select cNum from score group by cNum having count(cNum)>5));

+------+-------+------+---------------------+------+----------+
| tNum | tName | tSex | tBirthday           | prof | depart   |
+------+-------+------+---------------------+------+----------+
| 825  | 王萍  | 女   | 1972-05-05 00:00:00 | 助教 | 计算机系 |
+------+-------+------+---------------------+------+----------+
```

##### 23、查询95033班和95031班全体学生的记录。

```mysql
select * from student where class in('95033','95031');

+--------+---------+--------+---------------------+-------+
| stuNum | stuName | stuSex | stuBirthday         | class |
+--------+---------+--------+---------------------+-------+
| 101    | 曾华    | 男     | 1977-09-01 00:00:00 | 95033 |
| 102    | 匡明    | 男     | 1975-10-02 00:00:00 | 95031 |
| 103    | 王丽    | 女     | 1976-01-23 00:00:00 | 95033 |
| 104    | 李军    | 男     | 1976-02-20 00:00:00 | 95033 |
| 105    | 王芳    | 女     | 1975-02-10 00:00:00 | 95031 |
| 106    | 陆君    | 男     | 1974-06-03 00:00:00 | 95031 |
| 107    | 王尼玛  | 男     | 1976-02-20 00:00:00 | 95033 |
| 109    | 赵铁柱  | 男     | 1974-06-03 00:00:00 | 95031 |
+--------+---------+--------+---------------------+-------+

```

##### 24、查询存在有85分以上成绩的课程cNum.

```mysql
select cNum,score from score where score>85;
+-------+-------+
| cNum  | score |
+-------+-------+
| 3-105 |    90 |
| 3-105 |    91 |
| 3-105 |    92 |
| 3-245 |    86 |
| 3-105 |    89 |
| 3-105 |    88 |
+-------+-------+
```

##### 25、查询出“计算机系”教师所教课程的成绩。

```mysql
select * from score where cNum in (select cNum from course where tNum in(select tNum from teacher where depart='计算机系'));
+--------+-------+-------+
| stuNum | cNum  | score |
+--------+-------+-------+
| 103    | 3-245 |    86 |
| 105    | 3-245 |    75 |
| 109    | 3-245 |    68 |
| 101    | 3-105 |    90 |
| 102    | 3-105 |    91 |
| 103    | 3-105 |    92 |
| 104    | 3-105 |    89 |
| 105    | 3-105 |    88 |
| 109    | 3-105 |    76 |
+--------+-------+-------+
```



##### 26、(not in 和 union)查询“计算机系”与“电子工程系“不同职称的教师的tname和prof.

```mysql

select * from teacher where depart='计算机系' and prof not in (select prof from teacher where depart='电子工程系');
+------+-------+------+---------------------+--------+----------+
| tNum | tName | tSex | tBirthday           | prof   | depart   |
+------+-------+------+---------------------+--------+----------+
| 804  | 李成  | 男   | 1958-12-02 00:00:00 | 副教授 | 计算机系 |
+------+-------+------+---------------------+--------+----------+
select * from teacher where depart='电子工程系' and prof not in (select prof from teacher where depart='计算机系');
+------+-------+------+---------------------+------+------------+
| tNum | tName | tSex | tBirthday           | prof | depart     |
+------+-------+------+---------------------+------+------------+
| 856  | 张旭  | 男   | 1969-03-12 00:00:00 | 讲师 | 电子工程系 |
+------+-------+------+---------------------+------+------------+

select tName, prof from teacher where depart='计算机系' and prof not in (select prof from teacher where depart='电子工程系') 
union
select tName, prof from teacher where depart='电子工程系' and prof not in (select prof from teacher where depart='计算机系');

+-------+--------+
| tName | prof   |
+-------+--------+
| 李成  | 副教授 |
| 张旭  | 讲师   |
+-------+--------+

```

##### 27、(any)查询选修编号为“3-105“课程且成绩至少高于选修编号为“3-245”的同学的cNum、stuNum和score，并按score从高到低次序排序。

```mysql
select * from score where cNum='3-105' and score> any (select score from score where cNum='3-245') order by score desc;

+--------+-------+-------+
| stuNum | cNum  | score |
+--------+-------+-------+
| 103    | 3-105 |    92 |
| 102    | 3-105 |    91 |
| 101    | 3-105 |    90 |
| 104    | 3-105 |    89 |
| 105    | 3-105 |    88 |
| 109    | 3-105 |    76 |
+--------+-------+-------+
```



##### 28、(all)查询选修编号为“3-105“且成绩高于选修编号为“3-245”课程的同学的cNum、stuNum和score.

```mysql
select * from score where cNum='3-105' and score> all (select score from score where cNum='3-245');

+--------+-------+-------+
| stuNum | cNum  | score |
+--------+-------+-------+
| 101    | 3-105 |    90 |
| 102    | 3-105 |    91 |
| 103    | 3-105 |    92 |
| 104    | 3-105 |    89 |
| 105    | 3-105 |    88 |
+--------+-------+-------+

```



##### 29、(as 取别名)查询所有教师和同学的name、sex和birthday。

```mysql
select stuName as name,stuSex as sex,stuBirthday as birthday from student 
union
select tName,tSex,tBirthday from teacher ;
+--------+-----+---------------------+
| name   | sex | birthday            |
+--------+-----+---------------------+
| 曾华   | 男  | 1977-09-01 00:00:00 |
| 匡明   | 男  | 1975-10-02 00:00:00 |
| 王丽   | 女  | 1976-01-23 00:00:00 |
| 李军   | 男  | 1976-02-20 00:00:00 |
| 王芳   | 女  | 1975-02-10 00:00:00 |
| 陆君   | 男  | 1974-06-03 00:00:00 |
| 王尼玛 | 男  | 1976-02-20 00:00:00 |
| 赵铁柱 | 男  | 1974-06-03 00:00:00 |
| 李成   | 男  | 1958-12-02 00:00:00 |
| 王萍   | 女  | 1972-05-05 00:00:00 |
| 刘冰   | 女  | 1977-08-14 00:00:00 |
| 张旭   | 男  | 1969-03-12 00:00:00 |
+--------+-----+---------------------+
```

##### 30、(union)查询所有“女”教师和“女”同学的name、sex和birthday。

```mysql
select stuName as name,stuSex as sex,stuBirthday as birthday from student where stuSex='女'
union
select tName,tSex,tBirthday from teacher where tSex='女';

+------+-----+---------------------+
| name | sex | birthday            |
+------+-----+---------------------+
| 王丽 | 女  | 1976-01-23 00:00:00 |
| 王芳 | 女  | 1975-02-10 00:00:00 |
| 王萍 | 女  | 1972-05-05 00:00:00 |
| 刘冰 | 女  | 1977-08-14 00:00:00 |
+------+-----+---------------------+
```

##### 31、查询成绩比该课程平均成绩低的同学的成绩表。

```mysql
select * from score a where score < (
select avg(score) from score b where a.cNum=b.cNum) group by cNum;

+--------+-------+-------+
| stuNum | cNum  | score |
+--------+-------+-------+
| 105    | 3-245 |    75 |
| 105    | 6-166 |    79 |
| 109    | 3-105 |    76 |
| 109    | 3-245 |    68 |
| 109    | 6-166 |    81 |
+--------+-------+-------+

select stuNum ,cNum ,avg(score) from score group by cNum; 

+--------+-------+------------+
| stuNum | cNum  | avg(score) |
+--------+-------+------------+
| 101    | 3-105 |    87.6667 |
| 103    | 3-245 |    76.3333 |
| 103    | 6-166 |    81.6667 |
+--------+-------+------------+
```

##### 32、查询所有任课教师的tName和depart.

```mysql
 select tName,depart from teacher where tNum in(select tNum from course where cNum in (select cNum from score )) ;
+-------+------------+
| tName | depart     |
+-------+------------+
| 李成  | 计算机系   |
| 王萍  | 计算机系   |
| 张旭  | 电子工程系 |
+-------+------------+

 select distinct tName,depart from teacher,course,score where course.cNum=score.cNum and teacher.tNum=course.tNum ;
 +-------+------------+
| tName | depart     |
+-------+------------+
| 李成  | 计算机系   |
| 王萍  | 计算机系   |
| 张旭  | 电子工程系 |
+-------+------------+
```

##### 33、查询至少有2名男生的班号。

```mysql
select class from student  where stuSex='男' group by class having count(*)>1 ;
+-------+
| class |
+-------+
| 95033 |
| 95031 |
+-------+
```

##### 34、查询student表中不姓“王”的同学记录

```mysql
select * from student  where  stuName not like '王%' ;
+--------+---------+--------+---------------------+-------+
| stuNum | stuName | stuSex | stuBirthday         | class |
+--------+---------+--------+---------------------+-------+
| 101    | 曾华    | 男     | 1977-09-01 00:00:00 | 95033 |
| 102    | 匡明    | 男     | 1975-10-02 00:00:00 | 95031 |
| 104    | 李军    | 男     | 1976-02-20 00:00:00 | 95033 |
| 106    | 陆君    | 男     | 1974-06-03 00:00:00 | 95031 |
| 109    | 赵铁柱  | 男     | 1974-06-03 00:00:00 | 95031 |
+--------+---------+--------+---------------------+-------+
```

##### 35、查询student表中每个学生的姓名和年龄。

```mysql
select stuName, year(now())-year(stuBirthday) as age from student;
+---------+------+
| stuName | age  |
+---------+------+
| 曾华    |   42 |
| 匡明    |   44 |
| 王丽    |   43 |
| 李军    |   43 |
| 王芳    |   44 |
| 陆君    |   45 |
| 王尼玛  |   43 |
| 赵铁柱  |   45 |
+---------+------+
```

##### 36、查询student表中最大和最小的sbirthday日期值。

```mysql
select max(stuBirthday) as '最大',min(stuBirthday) as '最小' from student ;
+---------------------+---------------------+
| 最大                | 最小                |
+---------------------+---------------------+
| 1977-09-01 00:00:00 | 1974-06-03 00:00:00 |
+---------------------+---------------------+
```

##### 37、以班号和年龄从大到小的顺序查询student表中的全部记录。

```mysql
select * from student order by class desc, stuBirthday asc;

+--------+---------+--------+---------------------+-------+
| stuNum | stuName | stuSex | stuBirthday         | class |
+--------+---------+--------+---------------------+-------+
| 103    | 王丽    | 女     | 1976-01-23 00:00:00 | 95033 |
| 104    | 李军    | 男     | 1976-02-20 00:00:00 | 95033 |
| 107    | 王尼玛  | 男     | 1976-02-20 00:00:00 | 95033 |
| 101    | 曾华    | 男     | 1977-09-01 00:00:00 | 95033 |
| 106    | 陆君    | 男     | 1974-06-03 00:00:00 | 95031 |
| 109    | 赵铁柱  | 男     | 1974-06-03 00:00:00 | 95031 |
| 105    | 王芳    | 女     | 1975-02-10 00:00:00 | 95031 |
| 102    | 匡明    | 男     | 1975-10-02 00:00:00 | 95031 |
+--------+---------+--------+---------------------+-------+
```

##### 38、查询“男”教师及其所上的课程。

```mysql
select tName,cName,tSex from teacher,course where tSex='男' and teacher.tNum=course.tNum;

+-------+----------+------+
| tName | cName    | tSex |
+-------+----------+------+
| 李成  | 操作系统 | 男   |
| 张旭  | 数字电路 | 男   |
+-------+----------+------+

#或者

select cName,cNum from course where tNum in (select tNum from teacher where tSex='男');

+----------+-------+
| cName    | cNum  |
+----------+-------+
| 操作系统 | 3-245 |
| 数字电路 | 6-166 |
+----------+-------+
```



##### 39、查询最高分同学的stuNum、cNum和score列。

```mysql

select * from score where score in (select max(score)from score);

+--------+-------+-------+
| stuNum | cNum  | score |
+--------+-------+-------+
| 103    | 3-105 |    92 |
+--------+-------+-------+
```

##### 40、查询和“李军“同性别的所有同学的Sname.

```mysql
select stuName from student where stuSex = (select stuSex from student where stuName = '李军');

+---------+
| stuName |
+---------+
| 曾华    |
| 匡明    |
| 李军    |
| 陆君    |
| 王尼玛  |
| 赵铁柱  |
+---------+
```



##### 41、查询和“李军”同性别并同班的同学Sname.

```mysql
select stuName from student where stuSex = (select stuSex from student where stuName = '李军') and  class = (select class from student where stuName = '李军');
+---------+
| stuName |
+---------+
| 曾华    |
| 李军    |
| 王尼玛  |
+---------+
```



##### 42、查询所有选修“计算机导论“课程的“男”同学的成绩表。

```mysql
select * from score where stuNum in (select stuNum from student where stuSex='男') and  cNum in (select cNum from course where cName='计算机导论'); 

+--------+-------+-------+
| stuNum | cNum  | score |
+--------+-------+-------+
| 101    | 3-105 |    90 |
| 102    | 3-105 |    91 |
| 104    | 3-105 |    89 |
| 109    | 3-105 |    76 |
+--------+-------+-------+

```

##### 43、建立了一个grade表,查询所有同学的stuNum、cNum和rank列。

```mysql
create table grade(
    low int(3),
    up int(3),
    grade char(1)
); 
insert into grade values(90,100,'A');
insert into grade values(80,89,'B');
insert into grade values(70,79,'C');
insert into grade values(60,69,'D');
insert into grade values(0,59,'E');

select stuNum,cNum,grade as 'rank' from score, grade where  score between low and up order by grade;

+--------+-------+------+
| stuNum | cNum  | rank |
+--------+-------+------+
| 101    | 3-105 | A    |
| 102    | 3-105 | A    |
| 103    | 3-105 | A    |
| 104    | 3-105 | B    |
| 105    | 3-105 | B    |
| 103    | 3-245 | B    |
| 109    | 6-166 | B    |
| 103    | 6-166 | B    |
| 105    | 3-245 | C    |
| 105    | 6-166 | C    |
| 109    | 3-105 | C    |
| 109    | 3-245 | D    |
+--------+-------+------+
```

#### SQL 的四种连接查询

```mysql
#创建两个表
#person表
id，name，cardId
create table person(
    id int,
    name varchar(28),
    cardId int
);

#card表
id，name
create table card(
    id int, 
    name varchar(28)
);

insert into card values(1,'饭卡');
insert into card values(2,'建行卡');
insert into card values(3,'农行卡');
insert into card values(4,'工商卡');
insert into card values(5,'邮政卡');

+------+--------+
| id   | name   |
+------+--------+
|    1 | 饭卡   |
|    2 | 建行卡 |
|    3 | 农行卡 |
|    4 | 工商卡 |
|    5 | 邮政卡 |
+------+--------+

insert into person values(1,'张三',1);
insert into person values(2,'李四',3);
insert into person values(3,'王五',6);

+------+------+--------+
| id   | name | cardId |
+------+------+--------+
|    1 | 张三 |      1 |
|    2 | 李四 |      3 |
|    3 | 王五 |      6 |
+------+------+--------+
```



##### 内连接

**inner join** 或者 **join**

组合两个表中的记录，返回关联字段相符的记录，也就是返回两个表的交集（阴影）部分。

![inner-join](https://www.liaoxuefeng.com/files/attachments/1246892164662976/l)

```mysql
#inner join 查询 显式内连接

select * from person inner join card on person.cardId=card.id;
select * from person join card on person.cardId=card.id;
+------+------+--------+------+--------+
| id   | name | cardId | id   | name   |
+------+------+--------+------+--------+
|    1 | 张三 |      1 |    1 | 饭卡   |
|    2 | 李四 |      3 |    3 | 农行卡 |
+------+------+--------+------+--------+

#隐式内连接

select * from person , card where person.cardId=card.id;
+------+------+--------+------+--------+
| id   | name | cardId | id   | name   |
+------+------+--------+------+--------+
|    1 | 张三 |      1 |    1 | 饭卡   |
|    2 | 李四 |      3 |    3 | 农行卡 |
+------+------+--------+------+--------+
```



##### 外连接

###### 左连接**left join** 或者**left outer join**

left join 是left outer join的简写，它的全称是左外连接，是外连接中的一种。 左(外)连接，左表(a_table)的记录将会全部表示出来，而右表(b_table)只会显示符合搜索条件的记录。右表记录不足的地方均为NULL。

![left-outer-join](https://www.liaoxuefeng.com/files/attachments/1246893588481376/l)

```mysql
# left join 左外连接
select * from person left join card on person.cardId=card.id;
+------+------+--------+------+--------+
| id   | name | cardId | id   | name   |
+------+------+--------+------+--------+
|    1 | 张三 |      1 |    1 | 饭卡   |
|    2 | 李四 |      3 |    3 | 农行卡 |
|    3 | 王五 |      6 | NULL | NULL   |
+------+------+--------+------+--------+
select * from card left join person on person.cardId=card.id;
+------+--------+------+------+--------+
| id   | name   | id   | name | cardId |
+------+--------+------+------+--------+
|    1 | 饭卡   |    1 | 张三 |      1 |
|    3 | 农行卡 |    2 | 李四 |      3 |
|    2 | 建行卡 | NULL | NULL |   NULL |
|    4 | 工商卡 | NULL | NULL |   NULL |
|    5 | 邮政卡 | NULL | NULL |   NULL |
+------+--------+------+------+--------+
```



###### 右连接 **right join** 或者 **right outer join**

right join是right outer 
join的简写，它的全称是右外连接，是外连接中的一种。与左(外)连接相反，右(外)连接，左表(a_table)只会显示符合搜索条件的记录，而右表(b_table)的记录将会全部表示出来。左表记录不足的地方均为NULL。

![right-outer-join](https://www.liaoxuefeng.com/files/attachments/1246893609222688/l)

```mysql
# right join 左外连接
select * from person right join card on person.cardId=card.id;

+------+------+--------+------+--------+
| id   | name | cardId | id   | name   |
+------+------+--------+------+--------+
|    1 | 张三 |      1 |    1 | 饭卡   |
|    2 | 李四 |      3 |    3 | 农行卡 |
| NULL | NULL |   NULL |    2 | 建行卡 |
| NULL | NULL |   NULL |    4 | 工商卡 |
| NULL | NULL |   NULL |    5 | 邮政卡 |
+------+------+--------+------+--------+

select * from card right join person on person.cardId=card.id;

+------+--------+------+------+--------+
| id   | name   | id   | name | cardId |
+------+--------+------+------+--------+
|    1 | 饭卡   |    1 | 张三 |      1 |
|    3 | 农行卡 |    2 | 李四 |      3 |
| NULL | NULL   |    3 | 王五 |      6 |
+------+--------+------+------+--------+
```

###### 完全外链接 **full join** 或者 **full outer join**

FULL OUTER JOIN则是选出左右表都存在的记录

![full-outer-join](https://www.liaoxuefeng.com/files/attachments/1246893632359424/l)

```mysql
#全外连接
#mysql不支持全外连接
select * from card full join person on person.cardId=card.id;
 
 ==
 
 select * from card left join person on person.cardId=card.id
 union
  select * from card right join person on person.cardId=card.id;


+------+--------+------+------+--------+
| id   | name   | id   | name | cardId |
+------+--------+------+------+--------+
|    1 | 饭卡   |    1 | 张三 |      1 |
|    3 | 农行卡 |    2 | 李四 |      3 |
|    2 | 建行卡 | NULL | NULL |   NULL |
|    4 | 工商卡 | NULL | NULL |   NULL |
|    5 | 邮政卡 | NULL | NULL |   NULL |
| NULL | NULL   |    3 | 王五 |      6 |
+------+--------+------+------+--------+
```



### 5.事务

#### 事务处理的两种方式

##### 1、用 BEGIN, ROLLBACK, COMMIT来实现

- **BEGIN** 开始一个事务
- **ROLLBACK** 事务回滚
- **COMMIT**  事务确认

##### 2、直接用 SET 来改变 MySQL 的自动提交模式: 

- **SET AUTOCOMMIT=0**   禁止自动提交

- **SET AUTOCOMMIT=1** 开启自动提交

  

mysql中，事务其实是一个最小的不可分割的工作单元。事务能够保证一个业务的完整性。

比如我们的银行转账：

```mysql
a->-100
update user set money=money-100 where name='a';
b->+100
update user set money=money+100 where name='b';
```

—-实际的程序中，如果只有一条语句执行成功了，而另外一条没有执行成功？
—-出现数据前后不一致。
--多条sq1语句，可能会有同时成功的要求，要么就同时失败。

1、mysql默认是开启务的（自动提交）。

```mysql
select @@autocommit;

+--------------+
| @@autocommit |
+--------------+
|            1 |
+--------------+
1 row in set (0.00 sec)

```

-默认事务开启的作用是什么？
一当我们云抗行一个sqL语句的时候，效果会立即体现出来，且不能回滚。

```mysql

create table user(
    id int primary key, 
    name varchar(20), 
    money int
);
insert into user values(1,'a',1000);
+----+------+-------+
| id | name | money |
+----+------+-------+
|  1 | a    |  1000 |
+----+------+-------+
```

事务回滚：撤销sql语句执行效果

```mysql
mysql> rollback;
Query OK, 0 rows affected (0.00 sec)

mysql> select * from user;
+----+------+-------+
| id | name | money |
+----+------+-------+
|  1 | a    |  1000 |
+----+------+-------+
1 row in set (0.00 sec)

## 说明当前事务不能回滚
```

2.设置mysql自动提交为false

```mysql
 set autocommit=0;
 +--------------+
| @@autocommit |
+--------------+
|            0 |
+--------------+

insert into user values(2,'b',1240);

+----+------+-------+
| id | name | money |
+----+------+-------+
|  1 | a    |  1000 |
|  2 | b    |  1240 |
+----+------+-------+

rollback;

select * from user;
+----+------+-------+
| id | name | money |
+----+------+-------+
|  1 | a    |  1000 |
+----+------+-------+

# 回滚成功
```

3.手动提交数据

```mysql
#再一次插入数据
insert into user values(2,'b',1240);
+----+------+-------+
| id | name | money |
+----+------+-------+
|  1 | a    |  1000 |
|  2 | b    |  1240 |
+----+------+-------+
#手动提交数据
commit;
+----+------+-------+
| id | name | money |
+----+------+-------+
|  1 | a    |  1000 |
|  2 | b    |  1240 |
+----+------+-------+
#无法撤销（持久性）
rollback;
+----+------+-------+
| id | name | money |
+----+------+-------+
|  1 | a    |  1000 |
|  2 | b    |  1240 |
+----+------+-------+

```

设置转账事务

```mysql
update user set money=money-100 where name='a';
update user set money=money+100 where name='b';

+----+------+-------+
| id | name | money |
+----+------+-------+
|  1 | a    |   900 |
|  2 | b    |  1340 |
+----+------+-------+

rollback;

+----+------+-------+
| id | name | money |
+----+------+-------+
|  1 | a    |  1000 |
|  2 | b    |  1240 |
+----+------+-------+

#事务提供给我们可以撤回的机会

```

**手动开启事务**

**begin**或者 **start transaction**都可以帮我们手动开启一个事务；

```mysql
#开启自动提交(无法回滚)
set autocommit=1;
select @@autocommit;
+--------------+
| @@autocommit |
+--------------+
|            1 |
+--------------+

+----+------+-------+
| id | name | money |
+----+------+-------+
|  1 | a    |  1000 |
|  2 | b    |  1240 |
+----+------+-------+

begin;# 或者 start transaction;
update user set money=money-100 where name='a';
update user set money=money+100 where name='b';


+----+------+-------+
| id | name | money |
+----+------+-------+
|  1 | a    |   900 |
|  2 | b    |  1340 |
+----+------+-------+

rollback;

+----+------+-------+
| id | name | money |
+----+------+-------+
|  1 | a    |  1000 |
|  2 | b    |  1240 |
+----+------+-------+

```

#### ACID特征与使用

 一般来说，事务是必须满足4个条件（ACID）：

原子性（**A**tomicity，或称不可分割性）、一致性（**C**onsistency）、隔离性（**I**solation，又称独立性）、持久性（**D**urability）。 

- **原子性：**一个事务（transaction）中的所有操作，要么全部完成，要么全部不完成，不会结束在中间某个环节。事务在执行过程中发生错误，会被回滚（Rollback）到事务开始前的状态，就像这个事务从来没有执行过一样。
- **一致性：**在事务开始之前和事务结束以后，数据库的完整性没有被破坏。这表示写入的资料必须完全符合所有的预设规则，这包含资料的精确度、串联性以及后续数据库可以自发性地完成预定的工作。
- **隔离性：**数据库允许多个并发事务同时对其数据进行读写和修改的能力，隔离性可以防止多个事务并发执行时由于交叉执行而导致数据的不一致。事务隔离分为不同级别，包括读未提交（Read  uncommitted）、读提交（read committed）、可重复读（repeatable  read）和串行化（Serializable）。
- **持久性：**事务处理结束后，对数据的修改就是永久的，即便系统故障也不会丢失。

#### 事务隔离

[事务的四种隔离级别](https://www.cnblogs.com/ubuntu1/p/8999403.html)

1、read uncommitted；	读未提交的



读未提交，顾名思义，就是一个事务可以读取另一个未提交事务的数据。

事例：老板要给程序员发工资，程序员的工资是3.6万/月。但是发工资时老板不小心按错了数字，按成3.9万/月，该钱已经打到程序员的户口，但是事务还没有提交，就在这时，程序员去查看自己这个月的工资，发现比往常多了3千元，以为涨工资了非常高兴。但是老板及时发现了不对，马上回滚差点就提交了的事务，将数字改成3.6万再提交。

分析：实际程序员这个月的工资还是3.6万，但是程序员看到的是3.9万。他看到的是老板还没提交事务时的数据。这就是脏读。

------

那怎么解决脏读呢？Read committed！读提交，能解决脏读问题。

------



2、read committed；		 读已经提交的

读提交，顾名思义，就是一个事务要等另一个事务提交后才能读取数据。

事例：程序员拿着信用卡去享受生活（卡里当然是只有3.6万），当他埋单时（程序员事务开启），收费系统事先检测到他的卡里有3.6万，就在这个时候！！程序员的妻子要把钱全部转出充当家用，并提交。当收费系统准备扣款时，再检测卡里的金额，发现已经没钱了（第二次检测金额当然要等待妻子转出金额事务提交完）。程序员就会很郁闷，明明卡里是有钱的…

分析：这就是读提交，若有事务对数据进行更新（UPDATE）操作时，读操作事务要等待这个更新操作事务提交后才能读取数据，可以解决脏读问题。但在这个事例中，出现了一个事务范围内两个相同的查询却返回了不同数据，这就是不可重复读。

------

那怎么解决可能的不可重复读问题？Repeatable read ！

------



3、repeatable read； 		可以重复读

重复读，就是在开始读取数据（事务开启）时，不再允许修改操作

事例：程序员拿着信用卡去享受生活（卡里当然是只有3.6万），当他埋单时（事务开启，不允许其他事务的UPDATE修改操作），收费系统事先检测到他的卡里有3.6万。这个时候他的妻子不能转出金额了。接下来收费系统就可以扣款了。

分析：重复读可以解决不可重复读问题。写到这里，应该明白的一点就是，不可重复读对应的是修改，即UPDATE操作。但是可能还会有幻读问题。因为幻读问题对应的是插入INSERT操作，而不是UPDATE操作。

------

**什么时候会出现幻读？**

事例：程序员某一天去消费，花了2千元，然后他的妻子去查看他今天的消费记录（全表扫描FTS，妻子事务开启），看到确实是花了2千元，就在这个时候，程序员花了1万买了一部电脑，即新增INSERT了一条消费记录，并提交。当妻子打印程序员的消费记录清单时（妻子事务提交），发现花了1.2万元，似乎出现了幻觉，这就是幻读。

------

那怎么解决幻读问题？Serializable！



4、serializable；				  串行化

Serializable 是最高的事务隔离级别，在该级别下，事务串行化顺序执行，可以避免脏读、不可重复读与幻读。但是这种事务隔离级别效率低下，比较耗数据库性能，一般不使用。

------

值得一提的是：大多数数据库默认的事务隔离级别是Read committed，比如Sql Server , Oracle。Mysql的默认隔离级别是Repeatable read。



```mysql
# 查看隔离级别

select @@global.transaction_isolation;
+--------------------------------+
| @@global.transaction_isolation |
+--------------------------------+
| REPEATABLE-READ                |
+--------------------------------+

# 修改隔离级别

set global transaction isolation level read uncommitted;
+--------------------------------+
| @@global.transaction_isolation |
+--------------------------------+
| READ-UNCOMMITTED               |
+--------------------------------+

```



## 二、可视化工具操作数据库



## 三、编程语言操作数据库

