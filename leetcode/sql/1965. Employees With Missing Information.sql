select distinct e.employee_id
from employees e
left join salaries s 
on e.employee_id = s.employee_id
where s.salary is NULL
union
select distinct s.employee_id
from salaries s
left join employees e 
on e.employee_id = s.employee_id
where e.name is NULL
order by employee_id