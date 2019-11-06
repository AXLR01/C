#include<stdio.h>

#include<math.h>
#include<string.h>

/************************************** MAIN **************************************/
int main()
{

	/*********************************** VARIABLES ************************************/
	int  key, year, age;                          // key is the social security number key, year is the person's birth year and age is the person's age
	long long social_security_number, gender_num; // 2990394081094 key: 71
	char *category;                               // category includes gender and "category" in society
	/********************************* END VARIABLES **********************************/
	printf("Input social security number :"); // ask for social security number and key
	scanf("%lld", &social_security_number);
	printf("Input key :");
	scanf("%d", &key);

	if (social_security_number % 97 == key)
	{
		gender_num = social_security_number / 1000000000000;
		year = (social_security_number / 10000000000) - (gender_num * 100);
		if (year < 10)                                                          // CHILD
		{
			age = 19 - year;
			printf("\nThis person is a child of %d years old.\n", age);
		}
		else if ((year >= 10) && (year < 19))                                   // TEENAGER
		{
			age = 19 - year;

			printf("\nThis person is a teenager of %d years old.\n", age);
			printf("%lld\n", gender_num);
		}
		else if ((year >= 19) && (year < 30))                                   // YOUNG ADULT
		{
			age = 119 - year;
			if (gender_num == 1)
			{
				category = "man";
			}
			else if (gender_num == 2)
			{
				category = "woman";
			}
			else
			{
				category = "autre";
			}
			printf("\nThis person is a young %c of %d years old.\n", *category, age);
			printf("%lld\n", gender_num);
		}
		else if (year >= 30)                                                     // ADULT
		{
			age = 119 - year;
			if (gender_num == 1)
			{
				category = "man";
			}
			else if (gender_num == 2)
			{
				category = "woman";
			}
			else
			{
				category = "autre";
			}
			printf("\nThis person is an adult %c of %d years old.\n", *category, age);
			printf("%lld\n", gender_num);
		}
	}
	else
	{
		printf("Wrong key");
	}
	system("pause");
	return 0;
}
/************************************	END MAIN ************************************/
