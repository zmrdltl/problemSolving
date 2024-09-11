-- PostgreSQL
SELECT user_id, MAX(time_stamp) AS last_stamp
FROM logins
WHERE EXTRACT(YEAR FROM time_stamp) = 2020
GROUP BY user_id;

-- MySQL, MS SQL Server
SELECT user_id, MAX(time_stamp) AS last_stamp
FROM logins
WHERE YEAR(time_stamp) = 2020
GROUP BY user_id;


-- Oracle
SELECT user_id, MAX(time_stamp) AS last_stamp
FROM logins
WHERE TO_CHAR(time_stamp, 'YYYY') = '2020'
GROUP BY user_id;

