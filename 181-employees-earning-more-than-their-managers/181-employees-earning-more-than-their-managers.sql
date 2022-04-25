# Write your MySQL query statement below

SELECT e1.name as employee FROM employee e1
JOIN employee e2 ON e1.managerId = e2.id 
and e1.salary > e2.salary;