SELECT 
    HOUR(DATETIME) HOUR, 
    COUNT(HOUR(DATETIME)) COUNT 
FROM ANIMAL_OUTS 
GROUP BY HOUR
HAVING HOUR >= 9 AND HOUR < 20
ORDER BY HOUR