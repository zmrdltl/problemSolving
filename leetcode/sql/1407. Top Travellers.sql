SELECT 
    u.name AS NAME, 
    COALESCE(SUM(r.distance), 0) AS TRAVELLED_DISTANCE 
FROM users u
LEFT JOIN rides r ON r.user_id = u.id 
GROUP BY u.id, u.name
ORDER BY COALESCE(SUM(r.distance), 0) DESC, u.name;
