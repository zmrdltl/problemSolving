-- MySQL
select 
  query_name, 
  ROUND(SUM(rating / position) / COUNT(*) ,2) as quality,
  ROUND(SUM(CASE WHEN rating < 3 then 1 else 0 end) * 100.0 / COUNT(*), 2) poor_query_percentage 
from queries group by query_name having query_name is not null;