SELECT employee_id, department_id
FROM employee e
WHERE primary_flag = 'Y'
OR (
  employee_id in (
    select employee_id from employee
    group by employee_id 
    having count(employee_id) = 1
  )
)