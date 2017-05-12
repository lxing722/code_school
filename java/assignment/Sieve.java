package day9;

//Liang Xing
//Assignment #9

public class Sieve {
	
	private IntegerQueue queueNum = new IntegerQueue(); 
	private IntegerQueue queuePri = new IntegerQueue(); 
	private int max;
	public Sieve(){
		this.max = 0;
	}
	public void computeTo(int n){
		if(n>=2){
			while(!queuePri.isEmpty())
				queuePri.poll();
			this.max = n;
			for(int i=2;i<=n;i++)
				this.queueNum.offer(i);
			int p;
			do{
				p = this.queueNum.poll();
				this.queuePri.offer(p);				
				for(int i=0;i < this.queueNum.size();i++){
					int tempInt = this.queueNum.poll();
					if(tempInt%p != 0 )
						this.queueNum.offer(tempInt);
				}
			}while(p < Math.sqrt(n));
			while(!this.queueNum.isEmpty())
				this.queuePri.offer(this.queueNum.poll());
		}		
	}
	public void reportResults(){
		int i = 0;
		int count = 0;
		while(count < this.queuePri.size()){			
			int element = this.queuePri.poll();			
			System.out.print(element+" ");
			i++;
			if(i == 12&&count < this.queuePri.size()){
				System.out.println();
				i = 0;
			}
			count++;
			this.queuePri.offer(element);			
		}
	}
	public int getMax(){
		return this.max;
	}
	public int getCount(){
		return this.queuePri.size();
	}
}
