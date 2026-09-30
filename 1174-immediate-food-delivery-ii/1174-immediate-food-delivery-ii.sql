# Write your MySQL query statement below
select  
round(sum(if(min_order_date = min_customer_pref_delivery_date,1,0)*100)/count(min_order_date),2) as immediate_percentage 
from 
(select delivery_id, customer_id ,
min(order_date) as min_order_date,
min(customer_pref_delivery_date) as min_customer_pref_delivery_date from delivery
group by customer_id) as new_table;