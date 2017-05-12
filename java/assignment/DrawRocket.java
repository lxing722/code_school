package day2;

//Liang Xing
//Assignment #2
//This program will draw a rocket with any size.

public class DrawRocket {
	public static void main(String[] args){
		Rocket(2);
		Rocket(3);
		Rocket(5);
	}
	public static void Rocket(int size){
		Hat(size);
		Line(size);
		PartOfBody(size);
		Line(size);
		PartOfBody(size);
		Line(size);
		Hat(size);
	}
	//This function is used to replace the for loops to cut down lines.
	public static void For(String str,int size){
		for(int i=0;i<size;i++){
			System.out.print(str);
		}
	}
	//To draw the top and the bottom of the rocket.
	public static void Hat(int size){
		for(int i=1;i<size*2;i++){
			For(" ",size*2-i);
			For("/",i);
			System.out.print("**");
			For("\\",i);
			For(" ",size*2-i);
			System.out.print("\n");
		}
	}
	public static void Line(int size){
		System.out.print("+");
		For("=*",size*2);
		System.out.println("+");
	}
	public static void PartOfBody(int size){
		for(int i=1;i<=size;i++){
			System.out.print("|");
			For(".",size-i);
			For("/\\",i);
			For("..",size-i);
			For("/\\",i);
			For(".",size-i);
			System.out.println("|");
		}
		for(int i=0;i<size;i++){
			System.out.print("|");
			For(".",i);
			For("\\/",size-i);
			For("..",i);
			For("\\/",size-i);
			For(".",i);
			System.out.println("|");
		}
	}
}
