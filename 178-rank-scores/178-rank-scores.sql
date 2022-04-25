# Write your MySQL query statement below

SELECT score,DENSE_RANK() over (ORDER BY score DESC) as "rank" FROM Scores;