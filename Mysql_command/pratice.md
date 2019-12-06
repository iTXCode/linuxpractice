- 使用年薪进行降序排列

select ename,sal,comm,(sal+
ifnull(comm,0))comm)*12 
from emp
as yearsal order by yearsal;


- 显示工资最高的员工的名字和岗位

select ename ,job from emp
order by sal desc limit 1;

- 显示工资高于平均工资的员工的信息

select * from emp 
where sal>(
    select avg(sal) 
    from  emp
);

# 多表的方式来查询

select * from emp,(
    select avg(sal) as avgsal
     from emp
),tmp 
where sal>tmp.avgsal;


- 显示每个部门的平均工资和最高工资
select deptno,avg(sal),max(sal)
from emp 
group by deptno;

- 显示平均工资低于2000的部门
- 号和它的平均工资

- No1
create view v_tmp as selest
deptno,avg(sal)
as avgsal from emp
group by deptno;

select * from v_tmp
where avgsal<2000;


- NO2
select avg(sal) as avgsal,
deptno from emp
group  by deptno having 
avgsal <2000;

-  显示每种岗位的雇员总数,平均工资

select job,count(*),avg(sal)
from emp group by job;



- 便签应用数据库项目
