select count(id) as fish_count, max(coalesce(length,10)) as max_length, fish_type
from fish_info
group by fish_type
having avg(coalesce(length,10)) >= 33
order by fish_type