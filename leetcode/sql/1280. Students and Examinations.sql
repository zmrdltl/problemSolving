select s.student_id, student_name, su.subject_name, case when s.student_id is null then 0 else count(e.subject_name) end as attended_exams
from Students s
cross join Subjects su
left join Examinations e on s.student_id = e.student_id and su.subject_name = e.subject_name
group by s.student_id, s.student_name, su.subject_name
order by s.student_id, su.subject_name