main: main.o                            \
      account/account.o                 \
      savings_account/savings_account.o \
	  current_account/current_account.o
	g++ $^ -o $@

clean: 
	rm **/*.o *.o