with ProcessTime as (
    select 
        machine_id, 
        max(case when activity_type = 'end' then timestamp else null end) -
        max(case when activity_type = 'start' then timestamp else null end) as processing_time
    from activity a
    group by machine_id, process_id
),
MachineAverageTimes as (
    select 
        machine_id,
        round(avg(processing_time), 3) as processing_time
    from ProcessTime
    group by machine_id
)
select machine_id, processing_time from MachineAverageTimes
