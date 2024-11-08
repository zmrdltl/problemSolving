select ID, COALESCE(LENGTH, 0) AS LENGTH from fish_info
order by length desc, id asc
limit 10
