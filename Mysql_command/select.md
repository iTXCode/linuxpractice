
# 创建数据库的命令
create database jack;
# 进入数据库
use jack;
# 创建一个学生表
create table student(
    id char(10),
    name char(10),
    age int,
    addr char(20)
);

# 使用主键修饰创建一个表
create table man(
    name char(10) primary key,
    age int ,
    addr char(20)
);







