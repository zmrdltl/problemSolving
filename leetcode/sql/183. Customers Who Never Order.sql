select name as Customers 
from Customers c
left outer join Orders o 
on c.id = o.customerId
where o.id is null
