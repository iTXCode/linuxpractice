- 创建学生表
- student(Sno,Sname,Ssex,Sage,Sdept)

create table Student
(
    Sno varchar(10) primary key,
    Sname varchar(20) not null,
    Ssex varchar(4)  ,
    Sage smallint,
    Sdept varchar(20) 
);

insert into Student values
('201215121','李勇','男',20,'CS'),
('201215122','刘晨','女',19,'CS'),
('201215123','王敏','女',18,'MA'),
('201215125','张立','男',19,'IS');

- 创建课程表
- Course(Cno,Cname,Cpno,Ccredit);
create table Course
(
    Cno int primary key comment '课程号',
    Cname varchar(20)  not null comment '课程名字',
    Cpno int comment '先行课',
    Ccredit smallint comment '课程学分',
    foreign key(Cpno) references Course(Cno) 
);

insert into Course
values(1,'数据库',5,4).
(2,'数学', ,2),
(3,'信息系统',1,4),
(4,'操作系统',6,3),
(5,'数据结构',7,4),
(6,'数据处理', ,2),
(7,'PASCAL语言',6,4);
- 创建学生选课表
- SC(Sno,Cno,Grade)

create table SC 
(
    Sno varchar(10),
    Cno int,
    Grade float(5,2),
    primary key(Sno,Cno),
    foreign key(Sno) references Student(Sno),
    foreign key(Cno) references Course(Cno)
);

insert into SC values
('201215121',1,92),
('201215121',2,85),
('201215121',3,88),
('201215122',2,90),
('201215122',3,80);