
#generic solution
SELECT IFNULL((SELECT distinct salary FROM  Employee ORDER BY salary DESC LIMIT 1 OFFSET 1),NULL) 
as SecondHighestSalary;




#not an generic way but a way to just find 2nd highest salary
# SELECT MAX(salary) as SecondHighestSalary FROM Employee
# WHERE salary < ( SELECT MAX(salary) FROM Employee);  

