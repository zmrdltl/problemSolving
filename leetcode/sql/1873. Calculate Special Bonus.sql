SELECT 
    employee_id,
    CASE 
        WHEN (SELECT e.salary 
              FROM employees e 
              WHERE e.employee_id = employees.employee_id 
                AND e.employee_id % 2 = 1 
                AND e.name NOT LIKE 'M%') IS NULL 
        THEN 0 
        ELSE (SELECT e.salary 
              FROM employees e 
              WHERE e.employee_id = employees.employee_id 
                AND e.employee_id % 2 = 1 
                AND e.name NOT LIKE 'M%')
    END AS bonus
FROM 
    employees
order by employee_id