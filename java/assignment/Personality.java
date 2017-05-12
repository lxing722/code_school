package day6;

//Liang Xing
//Assignment #6

import java.io.FileNotFoundException;
import java.io.*;
import java.util.*;

public class Personality {
	
	public static final int size = 4;
	
	public static void main(String[] args)
			throws FileNotFoundException{	
		Scanner input = new Scanner(new File("C:/Users/star/Desktop/smalldata.txt"));
		PrintStream output = new PrintStream(new File("C:/Users/star/Desktop/smalldata_output.txt"));
		while(input.hasNextLine()){
			String line_name = input.nextLine();
			output.print(line_name+": ");
			String line_answers = input.nextLine();
			output.print(Arrays.toString(readLine(line_answers))+" = ");
			output.println(getResult(readLine(line_answers))[0]+getResult(readLine(line_answers))[1]+getResult(readLine(line_answers))[2]+getResult(readLine(line_answers))[3]);
		}
		input.close();
	}
	public static int[] readLine(String str){
		int[] answer_A = new int[size];
		int[] answer_B = new int[size];
		int[] B_percentages = new int[size];
		for(int i=0;i<70;i++){
			if(i%7 == 0)
				changeArray(answer_A,answer_B,str.charAt(i),0);
			else if(i%7 == 1||i%7 == 2)
				changeArray(answer_A,answer_B,str.charAt(i),1);
			else if(i%7 == 3||i%7 == 4)
				changeArray(answer_A,answer_B,str.charAt(i),2);
			else if(i%7 == 5||i%7 == 6)
				changeArray(answer_A,answer_B,str.charAt(i),3);
		}
		for(int i=0;i<size;i++){
			if(answer_A[i]+answer_B[i] != 0)
				B_percentages[i] = (int)Math.round(answer_B[i]*100/(answer_A[i]+answer_B[i]));
		}		
		return B_percentages;
	}
	public static String[] getResult(int[] a){
		String[] personality = new String[size];
		String[][] personality_1 = {{"E","I","X"},{"S","N","X"},{"T","F","X"},{"J","P","X"}};
		for(int i=0;i<size;i++){
			if(a[i]>50)
				personality[i] = personality_1[i][1];
			else if(a[i]==50)
				personality[i] = personality_1[i][2];
			else
				personality[i] = personality_1[i][0];
		}
		return personality;
	}
	public static void changeArray(int[] a,int[] b, char c,int n){
		if(c == 'A'||c == 'a')
			a[n]++;
		else if(c == 'B'||c == 'b')
			b[n]++;
	}	
}
