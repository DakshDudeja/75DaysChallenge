# Write your MySQL query statement below

SELECT name as Customers FROM Customers 
WHERE id not in (select customerId from orders);

# SELECT name as Customers 
# FROM Customers c LEFT JOIN ORDERS o ON c.id=o.customerId 
# Where o.customerId is NULL;