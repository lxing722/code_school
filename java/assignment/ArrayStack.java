package day8;

//Liang Xing
//Assignment #8

import java.util.*;

public class ArrayStack {
	
	private static final int max_length = 1000;
	private ArrayList<Character> stack = new ArrayList<Character>();
	private int length;
	public	ArrayStack(){
		this.length = 0;
	}
	public boolean isEmpty(){
		if(this.length == 0)
			return true;
		return false;
	}
	public char peek(){
		if(this.length > 0)
			return stack.get(this.length-1);
		return '\0';
	}
	public void push(char c){
		if(this.length<max_length)
			stack.add(this.length++,c);
		else
			System.out.println("The stack is full!");
	}
	public char pop(){
		if(this.isEmpty())
			return '\0';
		return stack.get(--this.length);
	}
}
