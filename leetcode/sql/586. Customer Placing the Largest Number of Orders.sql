# select c.customer_number as customer_number from (
#   select customer_number, count(customer_number) as ccnt from orders
#   group by customer_number
#   order by ccnt desc
#   limit 1
# ) c

select customer_number from orders
group by customer_number
order by count(*) desc
limit 1
