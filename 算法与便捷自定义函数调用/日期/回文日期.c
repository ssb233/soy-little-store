void rev_data(){
	for (int i = 0; i <= 9; i++) {
			for (int j = 0; j <= 9; j++) {
				int k = i * 10100101 + j * 1011010;
				if (checkDate(k))save[cnt++] = k;
				
				for(int p=0;p<=9;p++){
					for(int q=0;q<=9;q++){
						int t=i*10000001+j*1000010+p*100100+q*11000;
						if (checkDate(t))rev[num_rev++] = t;
					}
				}
			}
		}
		qsort(rev, num_rev, sizeof(int), compare); // Use > 0 to swap
		qsort(save, cnt, sizeof(int), compare); // Use > 0 to swap
}
