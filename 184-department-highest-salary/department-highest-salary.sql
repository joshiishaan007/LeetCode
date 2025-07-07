-- Write your PostgreSQL query statement below

-- SELECT d.name AS Department, e.name AS Employee, MAX(SELECT e1.salary FROM Employee e1 LEFT JOIN Department d1 ON e1.departmentId=d1.id GROUP BY d1.name) AS Salary FROM Employee e LEFT JOIN Department d ON e.departmentId = d.id GROUP BY d.name;

SELECT d1.name AS Department, e1.name AS Employee, e1.salary AS Salary FROM Employee e1 LEFT JOIN Department d1 ON e1.departmentId = d1.id WHERE (d1.name, e1.salary) IN (SELECT d.name, MAX(e.salary) FROM Employee e LEFT JOIN Department d ON e.departmentId = d.id GROUP BY d.name);