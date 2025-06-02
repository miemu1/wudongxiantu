// atoi.c

int atoi(string str)
{
	int v;

	if( !stringp(str) || !sscanf(str, "%d", v) ) return 0;
	return v;
}

int time()
{
	return 28800+efun::time();
}

int rand2(int seed,int lv)
{
	int k,m,n;

	k = pow(seed,lv);
	m = random(k);
	n = to_int(pow(k,1.0/lv)-pow(m,1.0/lv));
	return n;
}

int same_week(int time1, int time2)
{
	int day;
	int monday1;
	int monday2;

	if (!time1)
		time1 = time();
	
	if (!time2)
		time2 = time();

	if ((time1/86400) != (time2/86400)) {
		day = localtime(time1)[6];
		if (day == 0) day = 7;
		day--;
		monday1 = time1 - day*86400;

		day = localtime(time2)[6];
		if (day == 0) day = 7;
		day--;
		monday2 = time2 - day*86400;

		if ((monday1/86400) == (monday2/86400))
			return 1;
		else
			return 0;
	} 
	return 1;
}
