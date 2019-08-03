
	for(i= 0; i < 100; i++) {
		if(delet_book == number[i]) {
			for(int j = i; j < 99; j++)
				number[j] = number[j+1];
			
			number_is_not_prersent = false;
		}
	}
	if(number_is_not_prersent) {
		cout<< "\n\""<< delete_book<< "\""<< " is not present in array";	
	}
	
	else {
		cout<<"\nNew book seating is: ";
		
		for(i = 0; i <= index; i++) {
			cout<< number[i]<< " ";
		}
	}
	
	return 0;
	
}
