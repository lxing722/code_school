package day4;

//Liang Xing
//Assignment #4

import java.util.*;

public class Guess {
	public static Scanner console = new Scanner(System.in);
	public static int best_game = 1000;
	public static int total_guess = 0;
	public static void main(String[] args){
		Welcome();
		Result(Play_Game(10));
	}
	private static void Welcome(){
		System.out.println("Welcome to play this game!\n");
	}
	private static int Play_Game(int n){
		int count_game = 0;
		do{
			int temp = Game(n);
			total_guess += temp ;
			if(temp<best_game){
				best_game = temp;
			}
			count_game++;
		}while(Read());
		return count_game;
	}
	private static boolean Read(){
		String str = "";
		do{
			System.out.print("Do you want to play again? ");
			str = console.next();
			str = str.substring(0, 1).toUpperCase();
		}while(!isYN(str));
		System.out.println();
		if(str.equals("Y")){
			return true;
		}
		return false;
	}
	private static boolean isYN(String str){
		if(str.equals("Y")||str.equals("N"))
			return true;
		return false;
	}
	private static int Game(int n){
		int result = Game_begin(n);
		int count_guess = 0;
		System.out.print("Your guess? ");
		int num = 0;
		do{
			num = console.nextInt();
			count_guess++;		
		}while(!Compare(num,result));
		System.out.printf("You got it right in %d guesses\n",count_guess);		
		return count_guess;
	}
	private static boolean Compare(int num,int result){
		if(num > result){
			Compare2("lower");
			return false;
		}
		else if(num < result){
			Compare2("higher");
			return false;
		}
		return true;
	}
	private static void Compare2(String str){
		System.out.println("It's "+str+".");
		System.out.print("Your guess? ");
	}
	private static int Game_begin(int n){
		System.out.println("I'm thinking of a number between 1 and "+n+"...");
		Random rand = new Random();
		int result = rand.nextInt(n)+1;
		return result;
	}
	private static void Result(int n){
		System.out.println("Overall results:");
		System.out.println("  total games = "+n);
		System.out.println("  total guesses = "+total_guess);
		double guesses_game = total_guess/n;
		System.out.printf("  guesses/game = %.1f\n",guesses_game);
		System.out.println("  best game = "+best_game);
	}
}
