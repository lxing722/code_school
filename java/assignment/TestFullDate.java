package day7;

//Liang Xing
//Assignment #7

import java.util.*;

public class TestFullDate {
	
	public static void main(String[] args){
		Scanner console = new Scanner(System.in);
		System.out.println("Day counter");
		do{
			System.out.println();
			System.out.print("Enter first date (y m d): ");
			FullDate date1 = new FullDate(console.nextInt(),console.nextInt(),console.nextInt());
			System.out.print("Enter second date (y m d): ");
			FullDate date2 = new FullDate(console.nextInt(),console.nextInt(),console.nextInt());
			if(date2.lessOrEqual(date1))
				System.out.println("There are "+compute(date1,date2)+" days between "+date2.toString()+" "+date1.toString());
			else
				System.out.println("There are "+compute(date2,date1)+" days between "+date1.toString()+" "+date2.toString());
		}while(confirm(console));
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
	public static int compute(FullDate date1,FullDate date2){
		int sum = 0;
		if(date1.getMonth()>date2.getMonth())
			sum = 365*(date1.getYear()-date2.getYear())+getDays(date1,date2);		
		else if(date1.getMonth()==date2.getMonth())
			sum = 365*(date1.getYear()-date2.getYear())+date1.getDay()-date2.getDay();
		else
			sum = 365*(date1.getYear()-date2.getYear())-getDays(date2,date1);
		return sum;
	}
	public static int getDays(FullDate date1,FullDate date2){
		int sum = 0;
		int[] days = {31,28,31,30,31,30,31,31,30,31,30,31};
		sum += date2.daysInMonth()-date2.getDay();
		for(int i=date2.getMonth();i<date1.getMonth()-1;i++)
			sum += days[i];
		sum += date1.getDay();
		return sum;
	}
}
