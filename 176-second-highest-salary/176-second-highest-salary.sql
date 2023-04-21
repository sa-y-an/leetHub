# Write your MySQL query statement below
SELECT 
  IFNULL((
    SELECT DISTINCT salary FROM Employee 
    ORDER BY Salary DESC 
    LIMIT 1 
    OFFSET 1
      ),NULL)
AS SecondHighestSalary 
