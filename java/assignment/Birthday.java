package day7;

//Liang Xing
//Assignment #7

import java.util.*;

public class Birthday {
	
	public static void main(String[] args){
		Scanner console = new Scanner(System.in);
		System.out.println("Birthday counter");
		do{
			System.out.println();
			System.out.print("What is today's date (month and day)? ");
			SimpleDate date = new SimpleDate(console.nextInt(),console.nextInt());
			System.out.print("What is your birthday (month and day)? ");
			SimpleDate birthday = new SimpleDate(console.nextInt(),console.nextInt());		
			System.out.println("There are "+birthday.daysInMonth()+" days in month #"+birthday.getMonth());
		if(birthday.equals(date))
			System.out.println("Happy birthday!");
		else
			System.out.println("Number of days until birthday "+birthday.toString()+": "+compute(date,birthday));
		}while(confirm(console));
	}
	public static int compute(SimpleDate date,SimpleDate birthday){
		int sum = 0;
		if(birthday.getMonth()>date.getMonth())
			sum = getDays(date,birthday);
		else if(birthday.getMonth() == date.getMonth()){
			if(birthday.getDay()>date.getDay())
				sum = birthday.getDay()-date.getDay();
			else
				sum = 365+birthday.getDay()-date.getDay();
		}
		else
			sum = 364 - getDays(birthday,date);			
		return sum;
	}
	public static int getDays(SimpleDate date1,SimpleDate date2){
		int sum = 0;
		int[] days = {31,28,31,30,31,30,31,31,30,31,30,31};
		sum += date1.daysInMonth()-date1.getDay();
		for(int i=date1.getMonth()+1;i<date2.getMonth();i++)
			sum += days[i];
		sum += date2.getDay();
		return sum;
	}
	public static boolean confirm(Scanner console){
		String str;
		do{
			System.out.print("More? ");
			str = console.next();
		}		
		while(!str.equals("yes")&&!str.equals("no"));
		if(str.equals("yes"))
			return true;
		return false;
	}
}