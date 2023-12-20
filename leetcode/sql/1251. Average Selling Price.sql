-- MySQL, Oracle
SELECT
    p.product_id,
    CASE 
        WHEN SUM(u.units) = 0 OR SUM(u.units) IS NULL THEN 0
        ELSE ROUND(SUM(p.price * u.units) / SUM(u.units)::DECIMAL, 2)
    END AS average_price
FROM prices p
LEFT OUTER JOIN unitssold u ON p.product_id = u.product_id AND u.purchase_date BETWEEN p.start_date AND p.end_date
GROUP BY p.product_id;

-- PostgreSQL
SELECT
    p.product_id,
    CASE 
        WHEN SUM(u.units) = 0 OR SUM(u.units) IS NULL THEN 0
        ELSE ROUND(SUM(p.price * u.units) / SUM(u.units)::DECIMAL, 2)
    END AS average_price
FROM prices p
LEFT OUTER JOIN unitssold u ON p.product_id = u.product_id AND u.purchase_date BETWEEN p.start_date AND p.end_date
GROUP BY p.product_id;