import pandas as pd

def latest_login(logins: pd.DataFrame) -> pd.DataFrame:
  logins['time_stamp'] = pd.to_datetime(logins['time_stamp'])
  logins_filtered = logins[logins['time_stamp'].dt.year == 2020]
  latest_logins = logins_filtered.groupby('user_id').agg(last_stamp=('time_stamp', 'max')).reset_index()
  return latest_logins