SELECT DR_NAME,DR_ID,MCDP_CD,Date_format(HIRE_YMD,'%Y-%m-%d') FROM DOCTOR WHERE MCDP_CD='CS' OR MCDP_CD ='GS' order by HIRE_YMD desc, DR_NAME asc;