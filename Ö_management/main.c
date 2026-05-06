#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#pragma warning (disable: 4996)

typedef struct {
	bool active;
	char name[20];
	int age;
	char role[20];
	int salary;
	int ID;
} person;

void clearScreen() {
	printf("\033[H\033[J");
}

void addEmployee(person Employee[100]) {
	char tmpName[20];
	int tmpAge;
	char tmpRole[20];
	int tmpSalary;
	int tmpID;

	int contin = 1;
	do
	{
		clearScreen();
		printf("Add an employee \n");
		printf("Write the name of the employee: ");
		scanf(" %s", tmpName);
		printf("\nWrite the age of the employee: ");
		scanf(" %i", &tmpAge);
		printf("\nWrite the Role of the employee: ");
		scanf(" %s", tmpRole);
		printf("\nWrite the Salary of the employee (only numbers): ");
		scanf(" %i", &tmpSalary);

		bool useID;
		do
		{
			printf("\nWrite the ID of the employee (only numbers): ");
			scanf(" %i", &tmpID);
			for (int j = 0; j < 100; j++) {
				if (Employee[j].ID == tmpID && Employee[j].active == true) {
					printf("The ID is already in use! \n");
					useID = true;
					break;
				}
				else
				{
					useID = false;
				}
			}
		} while (useID == true);
		printf("\n");


		char usrAns_Corect;
		printf("Is this corect? (y/n) \n");
		printf("Name: %s \nAge: %i \nRole: %s \nSalary: %i \nID: %i \n", tmpName, tmpAge, tmpRole, tmpSalary, tmpID);
		scanf(" %c", &usrAns_Corect);

		if (usrAns_Corect == 'y'){
			contin = 0;
		}
		else
		{
			contin = 1;
		}
	} while (contin == 1);
	
	for (int i = 0; i < 100; i++)
	{
		if (Employee[i].active == false)
		{
			strcpy(Employee[i].name, tmpName);
			Employee[i].age = tmpAge;
			strcpy(Employee[i].role, tmpRole);
			Employee[i].salary = tmpSalary;
			Employee[i].ID = tmpID;
			Employee[i].active = true;
			printf("\nEmployee added succesfully! \n");
			clearScreen();
			break;
		}
	}
	//return 0;
}

bool isAnyUsers(person Employee[100]) {
	for (int i = 0; i < 100; i++)
	{
		if (Employee[i].active == true) {
			return true;
		}
	}
	return false;
}

void printUsr(person Employee[100], int i) {
	printf("%s \n", Employee[i].name);
	printf("Age: %i; Role: %s; Salary: %i; ID: %i", Employee[i].age, Employee[i].role, Employee[i].salary, Employee[i].ID);
	printf("\n");
}

void editEmployee(person Employee[100]) {
	clearScreen();
	if (isAnyUsers(Employee) == true)
	{
		printf("1) Shoose from a list of all employee names \n");
		printf("2) Enter a name manualy \n");
		int usrAns;
		scanf(" %i", &usrAns);

		int usrCount = 0;
		char tmpName[20];
		int tmpAge;
		char tmpRole[20];
		int tmpSalary;
		int tmpID;
		bool nameIsEdited = false;
		bool ageIsEdited = false;
		bool roleIsEdited = false;
		bool salaryIsEdited = false;
		bool IDIsEdited = false;
		switch (usrAns)
		{
		case (1): {
			int i = 0;
			do
			{
				clearScreen();
				usrCount = 0;
				for (i = 0; i < 100; i++)
				{
					if (Employee[i].active == true)
					{
						printf("%i) %s  \n", i + 1, Employee[i].name);
						usrCount++;
					}
				}
				scanf(" %i", &usrAns);
			} while (usrAns > usrCount || usrAns < 0);
			clearScreen();
			usrAns--;
			i = usrAns;

			do
			{
				printUsr(Employee, i);
				printf("Edit: \n1) Name \n2) Age \n3) Role \n4) Salary \n5) ID \n6) Done \n");
				scanf(" %i", &usrAns);

				switch (usrAns)
				{
				case 1:
					printf("Write the new name: ");
					scanf(" %s", &tmpName);
					nameIsEdited = true;
					break;

				case 2:
					printf("Write the new age: ");
					scanf(" %i", &tmpAge);
					ageIsEdited = true;
					break;

				case 3:
					printf("Write the new role: ");
					scanf(" %s", &tmpRole);
					roleIsEdited = true;
					break;

				case 4:
					printf("Write the new salary: ");
					scanf(" %i", &tmpSalary);
					salaryIsEdited = true;
					break;

				case 5:
					printf("Write the new ID: ");
					scanf(" %i", &tmpID);
					for (int j = 0; j < 100; j++) {
						if (Employee[j].ID == tmpID && Employee[i].ID != Employee[j].ID && Employee[j].active == true) {
							printf("The ID is already in use! \n");
							IDIsEdited = false;
						}
						else
						{
							IDIsEdited = true;
						}
					}
					break;

				case 6:

					break;

				default:
					break;
				}
			} while (usrAns != 6);

			// show new info
			do
			{
				if (nameIsEdited == true)
				{
					printf("Name: %s \n", tmpName);
				}
				else if (nameIsEdited == false)
				{
					printf("Name: %s \n", Employee[i].name);
				}

				if (ageIsEdited == true)
				{
					printf("Age: %i \n", tmpAge);
				}
				else if (ageIsEdited == false)
				{
					printf("Age: %i \n", Employee[i].age);
				}

				if (roleIsEdited == true)
				{
					printf("Role: %s \n", tmpRole);
				}
				else if (roleIsEdited == false)
				{
					printf("Role: %s \n", Employee[i].role);
				}

				if (salaryIsEdited == true)
				{
					printf("Salary: %i \n", tmpSalary);
				}
				else if (salaryIsEdited == false)
				{
					printf("Salary: %i \n", Employee[i].salary);
				}

				if (IDIsEdited == true)
				{
					printf("ID: %i \n", tmpID);
				}
				else if (IDIsEdited == false)
				{
					printf("ID: %i \n", Employee[i].ID);
				}
				
				// save changes
				bool saved = false;
				do
				{
					printf("1) Save changes \n2) Disgard changes \n");
					scanf(" %i", &usrAns);

					switch (usrAns)
					{
					case 1:
						if (nameIsEdited == true)
						{
							strcpy(Employee[i].name, tmpName);
						}
						else if (nameIsEdited == false)
						{
						}

						if (ageIsEdited == true)
						{
							Employee[i].age = tmpAge;
						}
						else if (ageIsEdited == false)
						{
						}

						if (roleIsEdited == true)
						{
							strcpy(Employee[i].role, tmpRole);
						}
						else if (roleIsEdited == false)
						{
						}

						if (salaryIsEdited == true)
						{
							Employee[i].salary = tmpSalary;
						}
						else if (salaryIsEdited == false)
						{
						}

						if (IDIsEdited == true)
						{
							Employee[i].ID = tmpID;
						}
						else if (IDIsEdited == false)
						{
						}
						saved = true;
						break;
					case 2:
						saved = true;
						break;
					default:
						break;
					}
					clearScreen();
				} while (saved != true);
			} while (false);

			break;
		}
		case (2): {
			printf("Write the ID of the employee you wich to edit: ");
			scanf(" %i", &tmpID);

			for (int i = 0; i < 100; i++) {
				if (Employee[i].ID == tmpID && Employee[i].active == true) {
					do
					{
						printUsr(Employee, i);
						printf("Edit: \n1) Name \n2) Age \n3) Role \n4) Salary \n5) ID \n6) Done \n");
						scanf(" %i", &usrAns);

						switch (usrAns)
						{
						case 1:
							printf("Write the new name: ");
							scanf(" %s", &tmpName);
							nameIsEdited = true;
							break;

						case 2:
							printf("Write the new age: ");
							scanf(" %i", &tmpAge);
							ageIsEdited = true;
							break;

						case 3:
							printf("Write the new role: ");
							scanf(" %s", &tmpRole);
							roleIsEdited = true;
							break;

						case 4:
							printf("Write the new salary: ");
							scanf(" %i", &tmpSalary);
							salaryIsEdited = true;
							break;

						case 5:
							printf("Write the new ID: ");
							scanf(" %i", &tmpID);
							for (int j = 0; j < 100; j++) {
								if (Employee[j].ID == tmpID && Employee[i].ID != Employee[j].ID && Employee[j].active == true) {
									printf("The ID is already in use! \n");
									IDIsEdited = false;
								}
								else
								{
									IDIsEdited = true;
								}
							}
							break;

						case 6:

							break;

						default:
							break;
						}

					} while (usrAns != 6);
					
					// show new info
					do
					{
						if (nameIsEdited == true)
						{
							printf("Name: %s \n", tmpName);
						}
						else if (nameIsEdited == false)
						{
							printf("Name: %s \n", Employee[i].name);
						}

						if (ageIsEdited == true)
						{
							printf("Age: %i \n", tmpAge);
						}
						else if (ageIsEdited == false)
						{
							printf("Age: %i \n", Employee[i].age);
						}

						if (roleIsEdited == true)
						{
							printf("Role: %s \n", tmpRole);
						}
						else if (roleIsEdited == false)
						{
							printf("Role: %s \n", Employee[i].role);
						}

						if (salaryIsEdited == true)
						{
							printf("Salary: %i \n", tmpSalary);
						}
						else if (salaryIsEdited == false)
						{
							printf("Salary: %i \n", Employee[i].salary);
						}

						if (IDIsEdited == true)
						{
							printf("ID: %i \n", tmpID);
						}
						else if (IDIsEdited == false)
						{
							printf("ID: %i \n", Employee[i].ID);
						}
					} while (false);

					// save changes
					bool saved = false;
					do
					{
						printf("1) Save changes \n2) Disgard changes \n");
						scanf(" %i", &usrAns);

						switch (usrAns)
						{
						case 1:
							if (nameIsEdited == true)
							{
								strcpy(Employee[i].name, tmpName);
							}
							else if (nameIsEdited == false)
							{
							}

							if (ageIsEdited == true)
							{
								Employee[i].age = tmpAge;
							}
							else if (ageIsEdited == false)
							{
							}

							if (roleIsEdited == true)
							{
								strcpy(Employee[i].role, tmpRole);
							}
							else if (roleIsEdited == false)
							{
							}

							if (salaryIsEdited == true)
							{
								Employee[i].salary = tmpSalary;
							}
							else if (salaryIsEdited == false)
							{
							}

							if (IDIsEdited == true)
							{
								Employee[i].ID = tmpID;
							}
							else if (IDIsEdited == false)
							{
							}
							saved = true;
							break;
						case 2:
							saved = true;
							break;
						default:
							break;
						}
						clearScreen();
					} while (saved != true);
				}
			}
			break;
		}
		default:
			break;
		}

	}
	else if (isAnyUsers(Employee) == false) {
		clearScreen();
		printf("There are no employees. You need to add an employee! \n");
	}
	else
	{
		//return 1;
	}
}

void removeEmployee(person Employee[100]) {
	clearScreen();
	if (isAnyUsers(Employee) == true)
	{
		printf("1) Shoose from a list of all employee names \n");
		printf("2) Enter a ID manualy \n");
		int usrAns;
		scanf(" %i", &usrAns);

		int usrCount = 0;
		int tmpID;
		char usrAnswer;
		int i = 0;

		switch (usrAns)
		{
		case (1): {
			do
			{
				clearScreen();
				usrCount = 0;
				for (i = 0; i < 100; i++)
				{
					if (Employee[i].active == true)
					{
						printf("%i) %s  \n", i + 1, Employee[i].name);
						usrCount++;
					}
				}
				scanf(" %i", &usrAns);
			} while (usrAns > usrCount || usrAns < 0);
			clearScreen();
			usrAns--;
			i = usrAns;

			
			do
			{
				printf("Confirm removing user, ");
				printUsr(Employee, i);
				printf("\n (y/n): ");
				scanf(" %c", &usrAnswer);

					
			} while (usrAnswer != 'y' && usrAnswer != 'n');

			if (usrAnswer == 'y') {
				Employee[i].active = false;
			}
				
			break;
		}
		case (2): {
			printf("Write the ID of the employee you wich to remove: ");
			scanf(" %i", &tmpID);

			for (int i = 0; i < 100; i++) {
				if (strcmp(Employee[i].ID, tmpID) == 0 && Employee[i].active == true) {
					printUsr(Employee, i);
				}
			}

			do
			{
				printf("Confirm removing user, ");
				printUsr(Employee, i);
				printf("\n (y/n): ");
				scanf(" %c", &usrAnswer);


			} while (usrAnswer != 'y' && usrAnswer != 'n');

			if (usrAnswer == 'y') {
				Employee[i].active = false;
			}
			break;
		}
		default:
			break;
		}

	}
	else if (isAnyUsers(Employee) == false) {
		clearScreen();
		printf("There are no employees to remove. \n");
	}
	else
	{
		//return 1;
	}



}

void listEmployee(person Employee[100]) {
	clearScreen();
	for (int i = 0; i < 100; i++)
	{
		if (Employee[i].active == true)
		{
			printUsr(Employee, i);
		}
	}

	if (isAnyUsers(Employee) == false) {
		printf("There are no employees. \n");
	}

}

void searchEmployee(person Employee[100]) {
	clearScreen();
	if (isAnyUsers(Employee) == true)
	{
		printf("1) Shoose from a list of all employee names \n");
		printf("2) Enter a ID manualy \n");
		int usrAns;
		scanf(" %i", &usrAns);

		int usrCount = 0;
		int tmpID;
		char usrAnswer;
		int i = 0;

		switch (usrAns)
		{
		case (1): {
			do
			{
				clearScreen();
				usrCount = 0;
				for (i = 0; i < 100; i++)
				{
					if (Employee[i].active == true)
					{
						printf("%i) %s  \n", i + 1, Employee[i].name);
						usrCount++;
					}
				}
				scanf(" %i", &usrAns);
			} while (usrAns > usrCount || usrAns < 0);
			clearScreen();
			usrAns--;
			i = usrAns;

			printUsr(Employee, i);

			break;
		}
		case (2): {
			printf("Write the ID of the employee you wich to search: ");
			scanf(" %i", &tmpID);

			bool noUser;
			for (int i = 0; i < 100; i++) {
				if (Employee[i].ID == tmpID && Employee[i].active == true) {
					printUsr(Employee, i);
					noUser = false;
					break;
				}
				else
				{
					noUser = true;
				}
			}
			if (noUser == true)
			{
				printf("There are no employees with that ID \n");
			}

			break;
		}
		default:
			break;
		}

	}
	else if (isAnyUsers(Employee) == false) {
		clearScreen();
		printf("There are no employees. \n");
	}
	else
	{
		//return 1;
	}


}

void loadFile(person Employee[100]) {

}

void saveFile(person Employee[100]) {
	FILE* file_ptr;

	file_ptr = fopen("save.txt", "w");
	if (file_ptr == NULL) {
		printf("Error opening file!");
		return 1;
	}
	for (int i = 0; i < 100; i++) {
		if (fprintf(file_ptr, "%d %s %d %s %d %d \n", Employee[i].active, Employee[i].name, Employee[i].age, Employee[i].role, Employee[i].salary, Employee[i].ID) < 0) {
			fclose(file_ptr);
			return -1;
		}

	}
	fclose(file_ptr);

}

int main() {
	person Employee[100];
	for (int i = 0; i < 100; i++) { Employee[i].active = false;	}
	
	do
	{
		printf("1) Add Employee \n2) Edit Employee \n3) Remove Employee \n4) List Employees \n5) Search Employee \n6) Load file \n7) Save file \n8) Exit\n");
		int usrAns;
		scanf(" %i", &usrAns);

		switch (usrAns) {
		case 1:
			addEmployee(Employee);
			break;
		case 2:
			editEmployee(Employee);
			break;
		case 3:
			removeEmployee(Employee);
			break;
		case 4:
			listEmployee(Employee);
			break;
		case 5:
			searchEmployee(Employee);
			break;

		case 6:
			loadFile(Employee);
			break;
		case 7:
			saveFile(Employee);
			break;

		case 8:
			return 0;

		default:
			break;
		}
	} while (true);
	

	return 0;
}