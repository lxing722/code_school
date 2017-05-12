package day8;

//Liang Xing
//Assignment #8

import java.util.*;

public class TestCheckBalance {
	
	public static void main(String[] args){
		Scanner console = new Scanner(System.in);
		System.out.println("Welcome to the Balance Checking program");
		String input;
		do{
			System.out.println();
			System.out.print("Enter the string you wish to check: ");
			input = console.nextLine();
			CheckBalance check = new CheckBalance(input);
			if(check.balanced())
				System.out.println("The string is balanced!\n");
			else{
				System.out.println("The string is unbalanced:\n");
				System.out.println(input);
				System.out.printf("%"+(check.index()+1)+"s\n","^");
			}
		}while(confirm(console));
		console.close();
	}
	public static boolean confirm(Scanner console){
		String str;
		do{
			System.out.print("More? ");
			str = console.nextLine();
		}		
		while(!str.equals("yes")&&!str.equals("no"));
		if(str.equals("yes"))
			return true;
		return false;
	}
}
