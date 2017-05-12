package day2;

public class test {
	public static void main(String[] args){
		int size=4;
		top_bottom(size);
		Top_Part(size);
		Bottom_Part(size);
		top_bottom(size);
	}
	public static void top_bottom(int size){
		System.out.print("#");
		for(int i=0;i<size;i++){			
			System.out.print("====");
		}
		System.out.println("#");	
	}
	public static void Top_Part(int size){
		for(int i=size;i>0;i--){
			System.out.print("|");
			for(int j=0;j<(i-1)*2;j++){
				System.out.print(" ");
			}
			System.out.print("<>");
			for(int j=size-i;j>0;j--){
				System.out.print("....");
			}
			System.out.print("<>");
			for(int j=0;j<(i-1);j++){
				System.out.print("  ");
			}
			System.out.println("|");
		}
	}
	public static void Bottom_Part(int size){
		for(int i=0;i<size;i++){
			System.out.print("|");
			for(int j=0;j<i;j++){
				System.out.print("  ");
			}
			System.out.print("<>");
			for(int j=size-i;j>1;j--){
				System.out.print("....");
			}
			System.out.print("<>");
			for(int j=0;j<i;j++){
				System.out.print("  ");
			}
			System.out.println("|");
		}
	}
}
