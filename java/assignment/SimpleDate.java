package day7;

//Liang Xing
//Assignment #7

public class SimpleDate {
	private int month;
	private int day;
	public SimpleDate(int month,int day){
		this.month = month;
		this.day = day;
	}
	public SimpleDate(SimpleDate date){
		this.month = date.month;
		this.day = date.day;
	}
	public int getMonth(){
		return this.month;
	}
	public int getDay(){
		return this.day;
	}
	public String toString(){
		return month+"/"+day;
	}
	public boolean equals(SimpleDate d){
		if(this.month == d.month&&this.day == d.day)
			return true;
		return false;
	}
	public int daysInMonth(){
		int[] days = {31,28,31,30,31,30,31,31,30,31,30,31};
		return days[this.month-1];
	}
	public void nextDay(){
		if(this.day == daysInMonth()){
			this.month = (this.month+1)%12;
			this.day = 1;
		}
		else
			this.day += 1;
	}
}
