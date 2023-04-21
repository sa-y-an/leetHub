CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
DECLARE M INT;
SET M=N-1;
  RETURN (
      # Write your MySQL query statement below.
        SELECT 
          IFNULL((
            SELECT DISTINCT salary FROM Employee 
            ORDER BY Salary DESC 
            LIMIT 1 
            OFFSET M
              ),NULL)
        AS SecondHighestSalary 
  );
END