-- MySQL & Oracle

select max(m.num) as num from (
  select num
  from mynumbers 
  group by num
  having count(*) = 1
) m 
