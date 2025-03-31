select member_id, member_name, gender, date_format(date_of_birth,'%Y-%m-%d') as date_of_birth from member_profile
where tlno is not null and gender = 'W' and date_format(date_of_birth,'%m') ='03'
ORDER BY MEMBER_ID;