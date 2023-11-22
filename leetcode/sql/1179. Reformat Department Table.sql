SELECT
    id,
    MAX(CASE WHEN month = 'Jan' THEN revenue ELSE NULL END) AS Jan_Revenue,
    MAX(CASE WHEN month = 'Feb' THEN revenue ELSE NULL END) AS Feb_Revenue,
    MAX(CASE WHEN month = 'Mar' THEN revenue ELSE NULL END) AS Mar_Revenue,
    MAX(CASE WHEN month = 'Apr' THEN revenue ELSE NULL END) AS Apr_Revenue,
    MAX(CASE WHEN month = 'May' THEN revenue ELSE NULL END) AS May_Revenue,
    MAX(CASE WHEN month = 'Jun' THEN revenue ELSE NULL END) AS Jun_Revenue,
    MAX(CASE WHEN month = 'Jul' THEN revenue ELSE NULL END) AS Jul_Revenue,
    MAX(CASE WHEN month = 'Aug' THEN revenue ELSE NULL END) AS Aug_Revenue,
    MAX(CASE WHEN month = 'Sep' THEN revenue ELSE NULL END) AS Sep_Revenue,
    MAX(CASE WHEN month = 'Oct' THEN revenue ELSE NULL END) AS Oct_Revenue,
    MAX(CASE WHEN month = 'Nov' THEN revenue ELSE NULL END) AS Nov_Revenue,
    MAX(CASE WHEN month = 'Dec' THEN revenue ELSE NULL END) AS Dec_Revenue
FROM Department
GROUP BY id;