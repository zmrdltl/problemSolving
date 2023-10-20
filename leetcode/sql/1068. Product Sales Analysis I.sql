select product_name, year, price from sales s
left outer join product p on s.product_id = p.product_id