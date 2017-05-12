package day7;

//Liang Xing
//Assignment #7

public class FullDate extends SimpleDate{
	private int year;
	private int month;
	private int day;
	public FullDate(int year,int month,int day){
		super(month,day);
		this.year = year;
	}
	public FullDate(FullDate date){
		super(date);
		this.year = date.year;
	}
	public int getYear(){
		return this.year;
	}
	public boolean lessOrEqual(FullDate date){
		if(this.year<date.year)
			return true;
		else if(this.year==date.year){
			if(this.month<date.month)
				return true;
			else if(this.month==date.month){
				if(this.day<=date.day)
					return true;
			}
		}
		return false;
	}
	public String toString(){
		return this.year+"/"+super.toString();
	}
	public boolean equals(FullDate d){
		if(this.year==d.year&&this.month==d.month&&this.day==d.day)
			return true;
		return false;
	}
	public void nextDay(){
		if(this.month==12&&this.day==31){
			this.year += 1;
			this.month = this.day = 1;
		}
		else{
			if(this.day == daysInMonth()){
				this.month = (this.month+1)%12;
				this.day = 1;
			}
			else
				this.day += 1;
		}
	}
}
