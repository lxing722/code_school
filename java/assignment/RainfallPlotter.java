package day5;

//Liang Xing
//Assignment #5

import java.awt.*;
import java.io.*;
import java.util.*;

public class RainfallPlotter {
	
	public static int found = 0;
	public static String[] cityFound = new String[3];//To store the city that is plotted.
	
	public static void main(String[] args)throws FileNotFoundException{
		information();
		DrawingPanel panel = new DrawingPanel(840, 550);
		Graphics g = panel.getGraphics();		
		draw_String(g);
		draw_Rect(g);
		interact(g);
	}
	public static void information(){
		System.out.println("Welcome to the Rainfall Plotter program!");
		System.out.println("You can plot the rainfall for up to 3 cities.");
		System.out.println("You can stop plotting by entering 'stop' as the name of the city.");
	}
	public static void draw_String(Graphics g){
		g.drawString("Jan", 0, 550);
		g.drawString("Feb", 70, 550);
		g.drawString("Mar", 140, 550);
		g.drawString("Apr", 210, 550);
		g.drawString("May", 280, 550);
		g.drawString("Jun", 350, 550);
		g.drawString("Jul", 420, 550);
		g.drawString("Aug", 490, 550);
		g.drawString("Sep", 560, 550);
		g.drawString("Oct", 630, 550);
		g.drawString("Nov", 700, 550);
		g.drawString("Dec", 770, 550);
	}
	public static void draw_Rect(Graphics g){
		g.drawRect(0,0,840,550);
		g.drawLine(0,25,840,25);
		g.drawLine(0,525,840,525);
		for(int i=1;i<=12;i++){
			g.drawLine(i*70, 25, i*70, 550);
		}
	}
	//This function will interact with user.
	public static void interact(Graphics g)throws FileNotFoundException{
		Scanner console = new Scanner(System.in);
		System.out.print("city? ");
		String city = console.next();
		while(!city.equals("stop")){
			if(Arrays.asList(cityFound).contains(city))
				System.out.println("It's plotted!");
			else{
				findCity(g,city);
				if(found == 3){
					System.out.println("No more city!");
					break;
				}
			}
			System.out.print("city? ");
			city = console.next();
		}		
		System.out.println("Thank you for using the Rainfall Plotter program!");
		console.close();
	}
	//This function will find the city that user input and print its information.
	public static void findCity(Graphics g,String city)throws FileNotFoundException{
		Scanner input = new Scanner(new File("C:/Users/star/Desktop/rainfall.txt"));
		while(input.hasNextLine()){
			String line = input.nextLine();
			Scanner scan = new Scanner(line);
			if(check(scan,city)){
				print(scan,g,city,found);
				cityFound[found] = city;
				found++;
				scan.close();
			}
		}
		input.close();
	}
	//This function will check if the city that user input is available.
	public static boolean check(Scanner scan,String str){		
		if(str.equals(scan.next()))
			return true;	
		return false;
	}
	//This function will print the information of a city.
	public static void print(Scanner scan,Graphics g,String city,int n){
		color(g);
		g.drawString(city, n*70, 25);
		double temp = 0;
		int i = 0;
		while(scan.hasNextDouble()){
			double num = scan.nextDouble();
			g.drawString(String.valueOf(num), i*70, 525-(int)convert(num));
			if(temp != 0){
				g.drawLine((i-1)*70,525-(int)convert(temp),i*70,525-(int)convert(num));
			}
			temp = num;
			i++;
		}
	}
	//This function will set color according to the city.
	public static void color(Graphics g){
		if(found == 0)
			g.setColor(Color.red);
		else if(found == 1)
			g.setColor(Color.blue);
		else
			g.setColor(Color.green);
	}
	public static double convert(double n){
		return n*10/3;
	}
}
