-- postgresql
SELECT 
    sell_date, 
    COUNT(DISTINCT product) AS num_sold, 
    STRING_AGG(DISTINCT product, ',' ORDER BY product) AS products
FROM activities
GROUP BY sell_date;

-- mysql
SELECT 
    sell_date, 
    COUNT(DISTINCT product) AS num_sold, 
    GROUP_CONCAT(DISTINCT product ORDER BY product ASC) AS products
FROM activities
GROUP BY sell_date;

