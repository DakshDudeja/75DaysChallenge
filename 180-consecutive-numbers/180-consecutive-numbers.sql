# Write your MySQL query statement below
SELECT distinct l1.num as ConsecutiveNums FROM logs l1
join logs l2 ON l1.id = l2.id+1 and l1.num=l2.num
join logs l3 ON l1.id = l3.id+2 and l1.num=l3.num;