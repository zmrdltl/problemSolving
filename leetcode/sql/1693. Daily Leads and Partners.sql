-- MySql
select date_id, make_name, count(distinct lead_id) as unique_leads, count(distinct partner_id) as unique_partners
from dailysales
group by date_id, make_name
order by date_id desc

-- Oracle
SELECT TO_CHAR(date_id, 'YYYY-MM-DD') as "date_id",
       make_name as "make_name", 
       COUNT(DISTINCT lead_id) AS "unique_leads", 
       COUNT(DISTINCT partner_id) AS "unique_partners"
FROM DailySales
GROUP BY date_id, make_name
