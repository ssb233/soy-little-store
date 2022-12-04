#define YEAR(d) (d / 10000)
#define MONTH(d) ((d / 100) % 100)
#define DAY(d) (d % 100)
#define LONGDAY(y, m, d) (y * 10000 + m * 100 + d)
//需要结合取出合法日期这个函数一起使用； 
int nextDay(int *year, int *month, int *day) {
	int days = getDaysOfMonth(*year, *month);
	if (*day < days) {
		(*day)++;
	} else {
		*day = 1;
		if (*month < 12) {
			(*month)++;
		} else {
			(*month) = 1;
			(*year)++;
		}
	}
	return LONGDAY(*year, *month, *day);
}
//计算>=d的第一个能够表示为合法日期的8位数
int nextDate(int d) {
	int year = YEAR(d), month = MONTH(d), day = DAY(d);
	if (month == 0) {
		return LONGDAY(year, 1, 1);
	} else if (month > 12) {
		return LONGDAY(year + 1, 1, 1);
	} else {
		if (day == 0)
			return LONGDAY(year, month, 1);
		else if (day <= getDaysOfMonth(year, month))
			return LONGDAY(year, month, day);
		else {
			return (month < 12) ?
			       LONGDAY(year, month + 1, 1) : LONGDAY(year + 1, 1, 1);
		}
	}
}
