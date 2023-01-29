int grtWeekDay(int year,int month,int day)
{
	int century,Weekday;
	if(month<3)
	{
		year--;
		month+=12;
	}
	
	century=year/100;
	year%=100;
	//Zeller formula
	Weekday=(year+year/4+century/4-2*century+(26*(month+1))/10+day-1)%7;
	if(Weekday<0)
	{
		Weekday+=7;
	}
	return Weekday;
}
