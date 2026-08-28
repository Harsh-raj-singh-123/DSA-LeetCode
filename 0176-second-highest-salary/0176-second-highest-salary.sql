SELECT max(salary) AS SecondHighestSalary
FROM Employee
WHERE salary < (
    Select max(salary)
    FROM Employee
);
