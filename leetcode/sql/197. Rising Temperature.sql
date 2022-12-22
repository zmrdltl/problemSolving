select a.id as Id 
from Weather a
left outer join Weather b
on datediff(a.recordDate, b.recordDate) = 1 
where a.temperature > b.temperature