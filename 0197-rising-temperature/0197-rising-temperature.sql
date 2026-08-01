SELECT w1.id
from Weather as w1, Weather as w2
where w1.recordDate = DATE_ADD(w2.recordDate,Interval 1 Day)
AND w1.temperature > w2.temperature
