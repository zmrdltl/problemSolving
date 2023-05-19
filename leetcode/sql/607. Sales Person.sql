#MySQL
select s.name from salesperson s
where s.sales_id not in  (
  select sales_id from orders o
  left join company as c on o.com_id = c.com_id
  where c.name = 'RED'
)
