select a.name as Employee 
from employee a
inner join employee b on a.managerId = b.id
where a.salary > b.salary