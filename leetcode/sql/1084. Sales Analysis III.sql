select p.product_id, p.product_name from sales s
join product p
on p.product_id = s.product_id
group by p.product_id
having sum(case when s.sale_date not between '2019-01-01' and '2019-03-31' then 1 else 0 end) = 0