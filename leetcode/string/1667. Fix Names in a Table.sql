-- MySQL
SELECT 
    user_id, 
    CONCAT(UPPER(SUBSTRING(name FROM 1 FOR 1)), LOWER(SUBSTRING(name FROM 2))) AS name
FROM 
    Users
ORDER BY 
    user_id;
    
-- Oracle
SELECT 
    user_id, 
    UPPER(SUBSTR(name, 1, 1)) || LOWER(SUBSTR(name, 2)) AS name
FROM 
    Users
ORDER BY 
    user_id;