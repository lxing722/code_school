package day10;

// Class AssassinMain is the driver program for the assassin management task.
// It reads names from a file, shuffles them if the user so desires, and uses
// them to start the game.  The user is asked for the name of the next victim
// until the game is over.
// YOU MUST NOT CHANGE THE CONTENT OF THAT CLASS

import java.io.*;
import java.util.*;

public class AssassinMain {
	public static void main(String[] args) throws FileNotFoundException {

		Scanner console = new Scanner(System.in);
		System.out.println("Welcome to the Assassin Manager Program");
		System.out.println();
		// prompt for file name
		System.out.print("What name file do you want to use this time? ");
		String fileName = console.nextLine();

		// for scanning the file of names
		Scanner input = new Scanner(new File(fileName));
		// creates the AssassinManager object
		AssassinManager manager = new AssassinManager(input);
		System.out.println();

		// prompt the user for victims until the game is over
		while ( ! manager.gameOver() )
			oneKill(console, manager);

		// report who won
		System.out.println( "Game was won by " + manager.winner() );
		System.out.println( "Final graveyard is as follows:" );
		manager.printGraveyard();
	}

	// Handles the details of recording one victim.  Shows the current kill
	// ring and graveyard to the user, prompts for a name and records the
	// kill if the name is legal.
	public static void oneKill(Scanner console, AssassinManager manager) {
		System.out.println("Current kill ring:");
		manager.printKillRing();
		System.out.println("Current graveyard:");
		manager.printGraveyard();
		System.out.println();
		System.out.print("next victim? ");
		String name = console.nextLine().trim();
		if ( manager.graveyardContains(name) )
			System.out.println( name + " is already dead." );
		else if ( ! manager.killRingContains(name) )
			System.out.println("Unknown person.");
		else
			manager.kill(name);
		System.out.println();
	}

	// asks the user a question, forcing an answer of "y" or "n";
	// returns true if the answer was yes, returns false otherwise
	public static boolean yesTo(Scanner console, String prompt) {
		for (;;) {
			System.out.print(prompt + " (y/n)? ");
			String response = console.nextLine().trim().toLowerCase();
			if (response.equals("y"))
				return true;
			else if (response.equals("n"))
				return false;
			else
				System.out.println("Please answer y or n.");
		}
	}
}
