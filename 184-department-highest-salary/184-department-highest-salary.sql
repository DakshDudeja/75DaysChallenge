# Write your MySQL query statement below

select department.name as Department,employee.name as Employee,salary from employee
Join department on employee.departmentId=department.id
where (departmentid,salary) in
(select departmentid, max(salary) as salary from employee group by departmentid);