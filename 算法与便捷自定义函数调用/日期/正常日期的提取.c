int isLeap(int year) {
	return (year % 4 == 0) && // ��������
	       (year % 100 != 0) || // ���겻��
	       (year % 400 == 0); // �İ�����
}

int getDaysOfMonth(int year, int month) {
	int days = 0;
	switch (month) {
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			days = 31;
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			days = 30;
			break;
		case 2:
			days = isLeap(year) ? 29 : 28;
			break;
	}
	return days;
}

//���ǵڶ���ȡ�����ڵķ�����
/*int getDaysOfMonth(int year, int month)
{
int days[2][13]={{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};
int leap = isLeap(year);
return days[leap][month];
}*/
