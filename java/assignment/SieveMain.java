package day9;

//Liang Xing
//Assignment #9

import java.util.*;

public class SieveMain {
	
	public static void main(String[] main){
		
		Scanner input = new Scanner(System.in);	
		Sieve pri = new Sieve();
		System.out.println("This program computes all prime numbers up to a\nmaximum using the Sieve of Eratosthenes. \n");
		int num = readInput(input);
		while(num != 0){			
			System.out.println();
			System.out.println("Primes up to "+num+" are as follows:");
			pri.computeTo(num);
			pri.reportResults();
			System.out.println("\n% of primes = "+(int)Math.round(pri.getCount()*100/pri.getMax()));
			System.out.println();
			num = readInput(input);
		}
		input.close();
	}
	public static int readInput(Scanner input){
		int temp;
		do{
			System.out.print("Maximum n to compute (0 to quit)? ");
			temp = input.nextInt();
		}while(temp<2&&temp!=0);
		return temp;
	}
}
