# Write your MySQL query statement below
SELECT name as Customers 
FROM Customers LEFT JOIN ORDERS ON Customers.id=ORDERS.customerId 
Where ORDERS.customerId is NULL;