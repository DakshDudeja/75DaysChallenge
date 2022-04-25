
# #generic solution
# SELECT IFNULL((SELECT distinct salary FROM  Employee ORDER BY salary DESC LIMIT 1 OFFSET 1),NULL) 
# as SecondHighestSalary;

#2nd generic solution using dense rank
SELECT IFNULL((SELECT distinct salary FROM (SELECT salary,DENSE_RANK() over (ORDER BY salary DESC) as denserank  FROM  Employee) temp WHERE temp.denserank = 2),NULL)
as SecondHighestSalary;




#not an generic way but a way to just find 2nd highest salary
# SELECT MAX(salary) as SecondHighestSalary FROM Employee
# WHERE salary < ( SELECT MAX(salary) FROM Employee);  

