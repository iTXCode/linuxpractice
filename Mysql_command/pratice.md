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
)
where sal>avgsal;
- 显示每个部门的平均工资和最高工资

