--MySQL
select player_id, min(event_date) as first_login 
from Activity
group by player_id

--Oracle
select PLAYER_ID as player_id, to_char(min(EVENT_DATE), 'yyyy-mm-dd') as first_login
from ACTIVITY
group by PLAYER_ID
