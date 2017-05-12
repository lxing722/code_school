package day3;

//Liang Xing
//Assignment #3

import java.util.*;

public class Admit2 {
	public static Scanner console = new Scanner(System.in);
	public static void main(String[] args){
		System.out.print("This program compares two applicants to\ndetermine which one seems like the stronger\napplicant.  For each candidate I will need\neither SAT or ACT scores plus a weighted GPA.\n\n");		
		double score1 = Applicant(1);
		double score2 = Applicant(2);
		double score3 = Applicant(3);		
		Compare(score1,score2,score3);
	}
	public static double Applicant(int n){
		System.out.printf("Information for applicant #%d:\n",n);
		System.out.print("\tdo you have 1) SAT scores or 2) ACT scores? ");
		int choice = console.nextInt();
		double total_score = 0.0;
		if(choice == 1 ){
			total_score = SAT()+GPA();
		}
		else if(choice == 2){
			total_score = ACT()+GPA();
		}
		System.out.println();
		return total_score;
	}
	public static double SAT(){
		System.out.print("\tSAT math? ");
		int math = console.nextInt();
		System.out.print("\tSAT critical reading? ");
		int reading = console.nextInt();
		System.out.print("\tSAT writing? ");
		int writing = console.nextInt();
		double score = Compute_SAT(math,reading,writing);
		System.out.printf("\texam score = %.1f\n",score);
		return score;
	}
	public static double ACT(){
		System.out.print("\tACT English? ");
		int english = console.nextInt();
		System.out.print("\tACT math? ");
		int math = console.nextInt();
		System.out.print("\tACT reading? ");
		int reading = console.nextInt();
		System.out.print("\tACT science? ");
		int science = console.nextInt();
		double score = Compute_ACT(english,math,reading,science);
		System.out.printf("\texam score = %.1f\n",score);
		return score;
	}
	public static double GPA(){
		System.out.print("\toverall GPA? ");
		double overall_GPA = console.nextDouble();
		System.out.print("\tmax GPA? ");
		double max_GPA = console.nextDouble();
		System.out.print("\tTranscript Multiplier? ");
		double multiplier = console.nextDouble();
		double score = Compute_GPA(overall_GPA,max_GPA,multiplier);
		System.out.printf("\tGPA score = %.1f\n",score);
		return score;
	}
	public static void Compare(double score1,double score2,double score3){
		System.out.printf("First applicant overall score  = %.1f\n",score1);
		System.out.printf("Second applicant overall score  = %.1f\n",score2);
		System.out.printf("Second applicant overall score  = %.1f\n",score3);
	}
	public static double Compute_SAT(int math,int reading,int writing){
		return (2*math+reading+writing)/32;
	}
	public static double Compute_ACT(int english,int math,int reading,int science){
		return (english+2*math+reading+science)/1.8;
	}
	public static double Compute_GPA(double overall_GPA,double max_GPA,double multiplier){
		return overall_GPA/max_GPA*100*multiplier;
	}
}
