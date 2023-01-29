#define YEAR(d) (d / 10000)
#define MONTH(d) ((d / 100) % 100)
#define DAY(d) (d % 100)
#define LONGDAY(y, m, d) (y * 10000 + m * 100 + d)
//��Ҫ���ȡ���Ϸ������������һ��ʹ�ã� 
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
//����>=d�ĵ�һ���ܹ���ʾΪ�Ϸ����ڵ�8λ��
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
