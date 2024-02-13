SELECT FLAVOR from FIRST_HALF where TOTAL_ORDER>3000 AND
Flavor in (select Flavor from ICECREAM_INFO where ingredient_type like 'fruit%') order by total_order desc;
