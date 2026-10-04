# Write your MySQL query statement below
select Department,Employee,Salary from
(select d.name as Department,e.name as Employee, e.salary as Salary,
dense_rank() over(partition by d.name order by e.salary desc) as ranks
from  Employee e
left join Department d
on e.departmentId  = d.id) temp 
where ranks <= 3;
