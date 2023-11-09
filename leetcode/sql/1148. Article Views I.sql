SELECT distinct author_id AS id
FROM views
where author_id = viewer_id
order by author_id;