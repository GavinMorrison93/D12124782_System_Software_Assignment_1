CC = gcc

objects = main.o create_backup.o date_and_time_source.o intranet_folder_monitor.o file_privileges.o update_live_website.o file_audit.o

headers = create_backup.h date_and_time_source.h intranet_folder_monitor.h file_privileges.h update_live_website.h file_audit.h

myprog : $(objects)
	$(CC) -o daemonProg $(objects) -lm

main.o : main.c $(headers)
	$(CC) -c main.c

create_backup.o : create_backup.c
	$(CC) -c create_backup.c

date_and_time_source.o : date_and_time_source.c
	$(CC) -c date_and_time_source.c

intranet_folder_monitor.o : intranet_folder_monitor.c
	$(CC) -c intranet_folder_monitor.c

file_privileges.o : file_privileges.c
	$(CC) -c file_privileges.c

update_live_website.o : update_live_website.c
	$(CC) -c update_live_website.c

file_audit.o : file_audit.c
	$(CC) -c file_audit.c

clean:
	rm daemonProg) $(objects)


	
